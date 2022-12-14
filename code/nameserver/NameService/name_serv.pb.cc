// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: name_serv.proto

#include "name_serv.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace nameserver {
PROTOBUF_CONSTEXPR HeartBeatRequest::HeartBeatRequest(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.score_)*/{}
  , /*decltype(_impl_._score_cached_byte_size_)*/{0}
  , /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.host_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.role_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.port_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct HeartBeatRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HeartBeatRequestDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~HeartBeatRequestDefaultTypeInternal() {}
  union {
    HeartBeatRequest _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeartBeatRequestDefaultTypeInternal _HeartBeatRequest_default_instance_;
PROTOBUF_CONSTEXPR HeartBeatResponse::HeartBeatResponse(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.success_)*/false
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct HeartBeatResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR HeartBeatResponseDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~HeartBeatResponseDefaultTypeInternal() {}
  union {
    HeartBeatResponse _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 HeartBeatResponseDefaultTypeInternal _HeartBeatResponse_default_instance_;
}  // namespace nameserver
static ::_pb::Metadata file_level_metadata_name_5fserv_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_name_5fserv_2eproto = nullptr;
static const ::_pb::ServiceDescriptor* file_level_service_descriptors_name_5fserv_2eproto[1];

const uint32_t TableStruct_name_5fserv_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _split_
  ~0u,  // no sizeof(Split)
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatRequest, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatRequest, _impl_.host_),
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatRequest, _impl_.port_),
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatRequest, _impl_.role_),
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatRequest, _impl_.score_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  ~0u,  // no _split_
  ~0u,  // no sizeof(Split)
  PROTOBUF_FIELD_OFFSET(::nameserver::HeartBeatResponse, _impl_.success_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::nameserver::HeartBeatRequest)},
  { 13, -1, -1, sizeof(::nameserver::HeartBeatResponse)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::nameserver::_HeartBeatRequest_default_instance_._instance,
  &::nameserver::_HeartBeatResponse_default_instance_._instance,
};

const char descriptor_table_protodef_name_5fserv_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017name_serv.proto\022\nnameserver\"Y\n\020HeartBe"
  "atRequest\022\014\n\004name\030\001 \001(\t\022\014\n\004host\030\002 \001(\t\022\014\n"
  "\004port\030\005 \001(\005\022\014\n\004role\030\003 \001(\t\022\r\n\005score\030\004 \003(\005"
  "\"$\n\021HeartBeatResponse\022\017\n\007success\030\001 \001(\0102W"
  "\n\013NameService\022H\n\tHeartBeat\022\034.nameserver."
  "HeartBeatRequest\032\035.nameserver.HeartBeatR"
  "esponseB\003\200\001\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_name_5fserv_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_name_5fserv_2eproto = {
    false, false, 260, descriptor_table_protodef_name_5fserv_2eproto,
    "name_serv.proto",
    &descriptor_table_name_5fserv_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_name_5fserv_2eproto::offsets,
    file_level_metadata_name_5fserv_2eproto, file_level_enum_descriptors_name_5fserv_2eproto,
    file_level_service_descriptors_name_5fserv_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_name_5fserv_2eproto_getter() {
  return &descriptor_table_name_5fserv_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_name_5fserv_2eproto(&descriptor_table_name_5fserv_2eproto);
namespace nameserver {

// ===================================================================

class HeartBeatRequest::_Internal {
 public:
};

HeartBeatRequest::HeartBeatRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:nameserver.HeartBeatRequest)
}
HeartBeatRequest::HeartBeatRequest(const HeartBeatRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  HeartBeatRequest* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.score_){from._impl_.score_}
    , /*decltype(_impl_._score_cached_byte_size_)*/{0}
    , decltype(_impl_.name_){}
    , decltype(_impl_.host_){}
    , decltype(_impl_.role_){}
    , decltype(_impl_.port_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.host_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.host_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_host().empty()) {
    _this->_impl_.host_.Set(from._internal_host(), 
      _this->GetArenaForAllocation());
  }
  _impl_.role_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.role_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_role().empty()) {
    _this->_impl_.role_.Set(from._internal_role(), 
      _this->GetArenaForAllocation());
  }
  _this->_impl_.port_ = from._impl_.port_;
  // @@protoc_insertion_point(copy_constructor:nameserver.HeartBeatRequest)
}

inline void HeartBeatRequest::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.score_){arena}
    , /*decltype(_impl_._score_cached_byte_size_)*/{0}
    , decltype(_impl_.name_){}
    , decltype(_impl_.host_){}
    , decltype(_impl_.role_){}
    , decltype(_impl_.port_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.host_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.host_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.role_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.role_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

HeartBeatRequest::~HeartBeatRequest() {
  // @@protoc_insertion_point(destructor:nameserver.HeartBeatRequest)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void HeartBeatRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.score_.~RepeatedField();
  _impl_.name_.Destroy();
  _impl_.host_.Destroy();
  _impl_.role_.Destroy();
}

void HeartBeatRequest::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void HeartBeatRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:nameserver.HeartBeatRequest)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.score_.Clear();
  _impl_.name_.ClearToEmpty();
  _impl_.host_.ClearToEmpty();
  _impl_.role_.ClearToEmpty();
  _impl_.port_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* HeartBeatRequest::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "nameserver.HeartBeatRequest.name"));
        } else
          goto handle_unusual;
        continue;
      // string host = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_host();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "nameserver.HeartBeatRequest.host"));
        } else
          goto handle_unusual;
        continue;
      // string role = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_role();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "nameserver.HeartBeatRequest.role"));
        } else
          goto handle_unusual;
        continue;
      // repeated int32 score = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedInt32Parser(_internal_mutable_score(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 32) {
          _internal_add_score(::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 port = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 40)) {
          _impl_.port_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* HeartBeatRequest::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:nameserver.HeartBeatRequest)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "nameserver.HeartBeatRequest.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // string host = 2;
  if (!this->_internal_host().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_host().data(), static_cast<int>(this->_internal_host().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "nameserver.HeartBeatRequest.host");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_host(), target);
  }

  // string role = 3;
  if (!this->_internal_role().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_role().data(), static_cast<int>(this->_internal_role().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "nameserver.HeartBeatRequest.role");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_role(), target);
  }

  // repeated int32 score = 4;
  {
    int byte_size = _impl_._score_cached_byte_size_.Get();
    if (byte_size > 0) {
      target = stream->WriteInt32Packed(
          4, _internal_score(), byte_size, target);
    }
  }

  // int32 port = 5;
  if (this->_internal_port() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(5, this->_internal_port(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:nameserver.HeartBeatRequest)
  return target;
}

size_t HeartBeatRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:nameserver.HeartBeatRequest)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated int32 score = 4;
  {
    size_t data_size = ::_pbi::WireFormatLite::
      Int32Size(this->_impl_.score_);
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    int cached_size = ::_pbi::ToCachedSize(data_size);
    _impl_._score_cached_byte_size_.Set(cached_size);
    total_size += data_size;
  }

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string host = 2;
  if (!this->_internal_host().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_host());
  }

  // string role = 3;
  if (!this->_internal_role().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_role());
  }

  // int32 port = 5;
  if (this->_internal_port() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_port());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HeartBeatRequest::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    HeartBeatRequest::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HeartBeatRequest::GetClassData() const { return &_class_data_; }


void HeartBeatRequest::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<HeartBeatRequest*>(&to_msg);
  auto& from = static_cast<const HeartBeatRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:nameserver.HeartBeatRequest)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.score_.MergeFrom(from._impl_.score_);
  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_host().empty()) {
    _this->_internal_set_host(from._internal_host());
  }
  if (!from._internal_role().empty()) {
    _this->_internal_set_role(from._internal_role());
  }
  if (from._internal_port() != 0) {
    _this->_internal_set_port(from._internal_port());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void HeartBeatRequest::CopyFrom(const HeartBeatRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:nameserver.HeartBeatRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeartBeatRequest::IsInitialized() const {
  return true;
}

void HeartBeatRequest::InternalSwap(HeartBeatRequest* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.score_.InternalSwap(&other->_impl_.score_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.host_, lhs_arena,
      &other->_impl_.host_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.role_, lhs_arena,
      &other->_impl_.role_, rhs_arena
  );
  swap(_impl_.port_, other->_impl_.port_);
}

::PROTOBUF_NAMESPACE_ID::Metadata HeartBeatRequest::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_name_5fserv_2eproto_getter, &descriptor_table_name_5fserv_2eproto_once,
      file_level_metadata_name_5fserv_2eproto[0]);
}

// ===================================================================

class HeartBeatResponse::_Internal {
 public:
};

HeartBeatResponse::HeartBeatResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:nameserver.HeartBeatResponse)
}
HeartBeatResponse::HeartBeatResponse(const HeartBeatResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  HeartBeatResponse* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.success_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.success_ = from._impl_.success_;
  // @@protoc_insertion_point(copy_constructor:nameserver.HeartBeatResponse)
}

inline void HeartBeatResponse::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.success_){false}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

HeartBeatResponse::~HeartBeatResponse() {
  // @@protoc_insertion_point(destructor:nameserver.HeartBeatResponse)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void HeartBeatResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void HeartBeatResponse::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void HeartBeatResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:nameserver.HeartBeatResponse)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.success_ = false;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* HeartBeatResponse::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // bool success = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.success_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* HeartBeatResponse::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:nameserver.HeartBeatResponse)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // bool success = 1;
  if (this->_internal_success() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteBoolToArray(1, this->_internal_success(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:nameserver.HeartBeatResponse)
  return target;
}

size_t HeartBeatResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:nameserver.HeartBeatResponse)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bool success = 1;
  if (this->_internal_success() != 0) {
    total_size += 1 + 1;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData HeartBeatResponse::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    HeartBeatResponse::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*HeartBeatResponse::GetClassData() const { return &_class_data_; }


void HeartBeatResponse::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<HeartBeatResponse*>(&to_msg);
  auto& from = static_cast<const HeartBeatResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:nameserver.HeartBeatResponse)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_success() != 0) {
    _this->_internal_set_success(from._internal_success());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void HeartBeatResponse::CopyFrom(const HeartBeatResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:nameserver.HeartBeatResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool HeartBeatResponse::IsInitialized() const {
  return true;
}

void HeartBeatResponse::InternalSwap(HeartBeatResponse* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_.success_, other->_impl_.success_);
}

::PROTOBUF_NAMESPACE_ID::Metadata HeartBeatResponse::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_name_5fserv_2eproto_getter, &descriptor_table_name_5fserv_2eproto_once,
      file_level_metadata_name_5fserv_2eproto[1]);
}

// ===================================================================

NameService::~NameService() {}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* NameService::descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_name_5fserv_2eproto);
  return file_level_service_descriptors_name_5fserv_2eproto[0];
}

const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* NameService::GetDescriptor() {
  return descriptor();
}

void NameService::HeartBeat(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                         const ::nameserver::HeartBeatRequest*,
                         ::nameserver::HeartBeatResponse*,
                         ::google::protobuf::Closure* done) {
  controller->SetFailed("Method HeartBeat() not implemented.");
  done->Run();
}

void NameService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                             ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                             const ::PROTOBUF_NAMESPACE_ID::Message* request,
                             ::PROTOBUF_NAMESPACE_ID::Message* response,
                             ::google::protobuf::Closure* done) {
  GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_name_5fserv_2eproto[0]);
  switch(method->index()) {
    case 0:
      HeartBeat(controller,
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::nameserver::HeartBeatRequest*>(
                 request),
             ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::nameserver::HeartBeatResponse*>(
                 response),
             done);
      break;
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      break;
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& NameService::GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::nameserver::HeartBeatRequest::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->input_type());
  }
}

const ::PROTOBUF_NAMESPACE_ID::Message& NameService::GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
  GOOGLE_DCHECK_EQ(method->service(), descriptor());
  switch(method->index()) {
    case 0:
      return ::nameserver::HeartBeatResponse::default_instance();
    default:
      GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
      return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
          ->GetPrototype(method->output_type());
  }
}

NameService_Stub::NameService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
  : channel_(channel), owns_channel_(false) {}
NameService_Stub::NameService_Stub(
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
    ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
  : channel_(channel),
    owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
NameService_Stub::~NameService_Stub() {
  if (owns_channel_) delete channel_;
}

void NameService_Stub::HeartBeat(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::nameserver::HeartBeatRequest* request,
                              ::nameserver::HeartBeatResponse* response,
                              ::google::protobuf::Closure* done) {
  channel_->CallMethod(descriptor()->method(0),
                       controller, request, response, done);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace nameserver
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::nameserver::HeartBeatRequest*
Arena::CreateMaybeMessage< ::nameserver::HeartBeatRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::nameserver::HeartBeatRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::nameserver::HeartBeatResponse*
Arena::CreateMaybeMessage< ::nameserver::HeartBeatResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::nameserver::HeartBeatResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
