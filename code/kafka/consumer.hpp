#include <iostream>
using namespace std;
#include <librdkafka/rdkafkacpp.h>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <csignal>
#include <cstring>
#include <mutex>
#if _AIX
#include <unistd.h>
#endif
static volatile sig_atomic_t run_consumer = 1;

class ExampleDeliveryReportCb_consumer : public RdKafka::DeliveryReportCb 
{
 public:
  void dr_cb (RdKafka::Message &message) {
    std::cout << "Message delivery for (" << message.len() << " bytes): " <<
        message.errstr() << std::endl;
    if (message.key())
      std::cout << "Key: " << *(message.key()) << ";" << std::endl;
  }
};

class ExampleEventCb_consumer : public RdKafka::EventCb {
 public:
  void event_cb (RdKafka::Event &event) {
    switch (event.type())
    {
      case RdKafka::Event::EVENT_ERROR:
        std::cerr << "ERROR (" << RdKafka::err2str(event.err()) << "): " <<
            event.str() << std::endl;
        if (event.err() == RdKafka::ERR__ALL_BROKERS_DOWN)
          run_consumer = false;
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

class MyHashPartitionerCb_consumer : public RdKafka::PartitionerCb {
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

const char* msg_consume(RdKafka::Message* message, void* opaque)
{
    switch (message->err())
    {
        case RdKafka::ERR__TIMED_OUT:
            break;

        case RdKafka::ERR_NO_ERROR:
          /* Real message */
            return static_cast<const char *>(message->payload()); // void* payload()
        case RdKafka::ERR__PARTITION_EOF:
              /* Last message */
              run_consumer = false;
              break;
        case RdKafka::ERR__UNKNOWN_TOPIC:
        case RdKafka::ERR__UNKNOWN_PARTITION:
            std::cerr << "Consume failed: " << message->errstr() << std::endl;
            run_consumer = false;
            break;
    default:
        /* Errors */
        std::cerr << "Consume failed: " << message->errstr() << std::endl;
        run_consumer = false;
    }
    return nullptr;
}
class ExampleConsumeCb_consumer : public RdKafka::ConsumeCb {
    public:
        void consume_cb (RdKafka::Message &msg, void *opaque)
        {
            msg_consume(&msg, opaque);
        }
};
class Consumer{
  public:
    friend class Log;
    Consumer(){
      std::string brokers = "localhost";
      std::string errstr;
      std::string topic_str="first";//first
      MyHashPartitionerCb_consumer hash_partitioner;
      int32_t partition = RdKafka::Topic::PARTITION_UA;//为何不能用？？在Consumer这里只能写0？？？无法自动吗？？？
      partition = 0;
      start_offset = RdKafka::Topic::OFFSET_BEGINNING;
      bool do_conf_dump = false;
      int opt;

      int use_ccb = 0;

      //Create configuration objects
      conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
      tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

      if (tconf->set("partitioner_cb", &hash_partitioner, errstr) != RdKafka::Conf::CONF_OK) 
      {
          std::cerr << errstr << std::endl;
          exit(1);
      }

      /*
      * Set configuration properties
      */
      conf->set("metadata.broker.list", brokers, errstr);
      ExampleEventCb_consumer ex_event_cb;
      conf->set("event_cb", &ex_event_cb, errstr);

      ExampleDeliveryReportCb_consumer ex_dr_cb;

      /* Set delivery report callback */
      conf->set("dr_cb", &ex_dr_cb, errstr);
      /*
      * Create consumer using accumulated global configuration.
      */
      consumer = RdKafka::Consumer::create(conf, errstr);
      if (!consumer) 
      {
        std::cerr << "Failed to create consumer: " << errstr << std::endl;
        exit(1);
      }

      std::cout << "% Created consumer " << consumer->name() << std::endl;

      /*
      * Create topic handle.
      */
      topic = RdKafka::Topic::create(consumer, topic_str, tconf, errstr);
      if (!topic)
      {
        std::cerr << "Failed to create topic: " << errstr << std::endl;
        exit(1);
      }
    }
    ~Consumer(){
      delete topic;
      delete conf;
      delete tconf;
      delete consumer;
    }
    void message(){
      /*
      * Start consumer for topic+partition at start offset
      */
      RdKafka::ErrorCode resp = consumer->start(topic, 0, start_offset);
      if (resp != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Failed to start consumer: " << RdKafka::err2str(resp) << std::endl;
        exit(1);
      }

      ExampleConsumeCb_consumer ex_consume_cb;

      /*
      * Consume messages
      */
      while (run_consumer)
      {
        if (use_ccb)
        {
            consumer->consume_callback(topic, 0, 1000, &ex_consume_cb, &use_ccb);
        }
        else 
        {
            RdKafka::Message *msg = consumer->consume(topic, 0, 1000);
            const char* messages = msg_consume(msg, NULL);
            logger(messages);
        }
        consumer->poll(0);
      }

      /*
      * Stop consumer
      */
      consumer->stop(topic, 0);

      consumer->poll(1000);
    }
    void logger(string msg){
      //获得日志等级
      string level = msg.substr(0, 3);
      msg = msg.substr(3, msg.size()-3);
      // 启动专门的写日志线程
      // 获取当前的日期，然后取日志信息，写入相应的日志文件当中 a+
      time_t now = time(nullptr);
      tm *nowtm = localtime(&now);

      char file_name[128];
      sprintf(file_name, "/root/WebServer/logs/%d-%d-%d-log.txt", nowtm->tm_year+1900, nowtm->tm_mon+1, nowtm->tm_mday);

      FILE *pf = fopen(file_name, "a+");
      if (pf == nullptr)
      {
          std::cout << "logger file : " << file_name << " open error!" << std::endl;
          exit(EXIT_FAILURE);
      }

      char time_buf[128] = {0};
      sprintf(time_buf, "%d:%d:%d =>[%s] ", 
              nowtm->tm_hour, 
              nowtm->tm_min, 
              nowtm->tm_sec,
              level);
      msg.insert(0, time_buf);
      msg.append("\n");

      fputs(msg.c_str(), pf);
      fclose(pf);
    }
  private:
    RdKafka::Topic *topic;
    RdKafka::Conf *conf, *tconf;
    RdKafka::Consumer *consumer;
    bool use_ccb;
    int64_t start_offset;
};