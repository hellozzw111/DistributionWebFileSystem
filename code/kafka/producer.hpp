#include <iostream>
using namespace std;
#include <librdkafka/rdkafkacpp.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>
#if _AIX
#include <unistd.h>
#endif

static volatile sig_atomic_t run_producer = 1;


class ExampleDeliveryReportCb : public RdKafka::DeliveryReportCb 
{
 public:
  void dr_cb (RdKafka::Message &message) {
    std::cout << "Message delivery for (" << message.len() << " bytes): " <<
        message.errstr() << std::endl;
    if (message.key())
      std::cout << "Key: " << *(message.key()) << ";" << std::endl;
  }
};


class ExampleEventCb : public RdKafka::EventCb {
 public:
  void event_cb (RdKafka::Event &event) {
    switch (event.type())
    {
      case RdKafka::Event::EVENT_ERROR:
        std::cerr << "ERROR (" << RdKafka::err2str(event.err()) << "): " <<
            event.str() << std::endl;
        if (event.err() == RdKafka::ERR__ALL_BROKERS_DOWN)
          run_producer = false;
        break;

      case RdKafka::Event::EVENT_STATS:
        std::cerr << "\"STATS\": " << event.str() << std::endl;
        break;

      case RdKafka::Event::EVENT_LOG:
        fprintf(stderr, "LOG-%i-%s: %s\n",
                event.severity(), event.fac().c_str(), event.str().c_str());
        break;

      default:
        std::cerr << "EVENT " << event.type() <<
            " (" << RdKafka::err2str(event.err()) << "): " <<
            event.str() << std::endl;
        break;
    }
  }
};

/* Use of this partitioner is pretty pointless since no key is provided
 * in the produce() call.so when you need input your key */
class MyHashPartitionerCb : public RdKafka::PartitionerCb {
    public:
        int32_t partitioner_cb (const RdKafka::Topic *topic, const std::string *key,int32_t partition_cnt, void *msg_opaque) 
        {
            std::cout<<"partition_cnt="<<partition_cnt<<std::endl;
            return djb_hash(key->c_str(), key->size()) % partition_cnt;
        }
    private:
        static inline unsigned int djb_hash (const char *str, size_t len) 
        {
        unsigned int hash = 5381;
        for (size_t i = 0 ; i < len ; i++)
            hash = ((hash << 5) + hash) + str[i];
        std::cout<<"hash1="<<hash<<std::endl;

        return hash;
        }
};
class Producer{
public:
  Producer(){
    std::string brokers = "localhost";
    std::string errstr;
    std::string topic_str="logs";//自行制定主题topic
    MyHashPartitionerCb hash_partitioner;
    int32_t partition = RdKafka::Topic::PARTITION_UA;
    int64_t start_offset = RdKafka::Topic::OFFSET_BEGINNING;
    bool do_conf_dump = false;
    int opt;

    int use_ccb = 0;

    //Create configuration objects
    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    RdKafka::Conf *tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

    if (tconf->set("partitioner_cb", &hash_partitioner, errstr) != RdKafka::Conf::CONF_OK) 
     {
          std::cerr << errstr << std::endl;
          exit(1);
     }

    /*
    * Set configuration properties
    */
    conf->set("metadata.broker.list", brokers, errstr);
    ExampleEventCb ex_event_cb;
    conf->set("event_cb", &ex_event_cb, errstr);

    ExampleDeliveryReportCb ex_dr_cb;

    /* Set delivery report callback */
    conf->set("dr_cb", &ex_dr_cb, errstr);

    /*
     * Create producer using accumulated global configuration.
     */
    producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) 
    {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        exit(1);
    }

    std::cout << "% Created producer " << producer->name() << std::endl;

    /*
     * Create topic handle.
     */
    topic = RdKafka::Topic::create(producer, topic_str, tconf, errstr);
    if (!topic) {
      std::cerr << "Failed to create topic: " << errstr << std::endl;
      exit(1);
    }
  }
  bool message(string line){
      if (line.empty())
      {
          producer->poll(0);
          return false;
      }

    /*
      * Produce message
      // 1. topic
      // 2. partition
      // 3. flags
      // 4. payload
      // 5. payload len
      // 6. std::string key
      // 7. msg_opaque? NULL
      */
    std::string key=line.substr(0,5);//根据line前5个字符串作为key值
    // int a = MyHashPartitionerCb::djb_hash(key.c_str(),key.size());
    // std::cout<<"hash="<<a<<std::endl;
    RdKafka::ErrorCode resp = producer->produce(topic, 0,
        RdKafka::Producer::RK_MSG_COPY /* Copy payload */,
        const_cast<char *>(line.c_str()), line.size(),
        key.c_str(), key.size(), NULL);//这里可以设计key值,因为会根据key值放在对应的partition
      if (resp != RdKafka::ERR_NO_ERROR)
          std::cerr << "% Produce failed: " <<RdKafka::err2str(resp) << std::endl;
      else
          std::cerr << "% Produced message (" << line.size() << " bytes)" <<std::endl;
      producer->poll(0);//对于socket进行读写操作。poll方法才是做实际的IO操作的。return the number of events served
    //
    //退出前处理完输出队列中的消息
    if(!run_producer){
      while (run_producer && producer->outq_len() > 0) {
        std::cerr << "Waiting for " << producer->outq_len() << std::endl;
        producer->poll(1000);
      }
    }
  }
  ~Producer(){
    delete topic;
    delete producer;
  }
private:
  RdKafka::Producer* producer;
  RdKafka::Topic *topic;
};