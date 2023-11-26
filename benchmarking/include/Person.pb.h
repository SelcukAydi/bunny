// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Person.proto
// Protobuf C++ Version: 4.26.0-dev

#ifndef GOOGLE_PROTOBUF_INCLUDED_Person_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_Person_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/port_def.inc"
#if PROTOBUF_VERSION != 4026000
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/port_undef.inc"
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_Person_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_Person_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_Person_2eproto;
namespace benchmarktesting {
class Person;
struct PersonDefaultTypeInternal;
extern PersonDefaultTypeInternal _Person_default_instance_;
class Person_Role;
struct Person_RoleDefaultTypeInternal;
extern Person_RoleDefaultTypeInternal _Person_Role_default_instance_;
}  // namespace benchmarktesting
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace benchmarktesting {

// ===================================================================


// -------------------------------------------------------------------

class Person_Role final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:benchmarktesting.Person.Role) */ {
 public:
  inline Person_Role() : Person_Role(nullptr) {}
  ~Person_Role() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Person_Role(
      ::google::protobuf::internal::ConstantInitialized);

  inline Person_Role(const Person_Role& from) : Person_Role(nullptr, from) {}
  inline Person_Role(Person_Role&& from) noexcept
      : Person_Role(nullptr, std::move(from)) {}
  inline Person_Role& operator=(const Person_Role& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person_Role& operator=(Person_Role&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person_Role& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person_Role* internal_default_instance() {
    return reinterpret_cast<const Person_Role*>(
        &_Person_Role_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Person_Role& a, Person_Role& b) { a.Swap(&b); }
  inline void Swap(Person_Role* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person_Role* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person_Role* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Person_Role>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Person_Role& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Person_Role& from) { Person_Role::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Person_Role* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "benchmarktesting.Person.Role"; }

 protected:
  explicit Person_Role(::google::protobuf::Arena* arena);
  Person_Role(::google::protobuf::Arena* arena, const Person_Role& from);
  Person_Role(::google::protobuf::Arena* arena, Person_Role&& from) noexcept
      : Person_Role(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kRoleNameFieldNumber = 1,
  };
  // optional string roleName = 1;
  bool has_rolename() const;
  void clear_rolename() ;
  const std::string& rolename() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_rolename(Arg_&& arg, Args_... args);
  std::string* mutable_rolename();
  PROTOBUF_NODISCARD std::string* release_rolename();
  void set_allocated_rolename(std::string* value);

  private:
  const std::string& _internal_rolename() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_rolename(
      const std::string& value);
  std::string* _internal_mutable_rolename();

  public:
  // @@protoc_insertion_point(class_scope:benchmarktesting.Person.Role)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      45, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr rolename_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Person_2eproto;
};
// -------------------------------------------------------------------

class Person final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:benchmarktesting.Person) */ {
 public:
  inline Person() : Person(nullptr) {}
  ~Person() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Person(
      ::google::protobuf::internal::ConstantInitialized);

  inline Person(const Person& from) : Person(nullptr, from) {}
  inline Person(Person&& from) noexcept
      : Person(nullptr, std::move(from)) {}
  inline Person& operator=(const Person& from) {
    CopyFrom(from);
    return *this;
  }
  inline Person& operator=(Person&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Person& default_instance() {
    return *internal_default_instance();
  }
  static inline const Person* internal_default_instance() {
    return reinterpret_cast<const Person*>(
        &_Person_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(Person& a, Person& b) { a.Swap(&b); }
  inline void Swap(Person* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Person* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Person* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<Person>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Person& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Person& from) { Person::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  ::size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::google::protobuf::internal::ParseContext* ctx) final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(Person* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "benchmarktesting.Person"; }

 protected:
  explicit Person(::google::protobuf::Arena* arena);
  Person(::google::protobuf::Arena* arena, const Person& from);
  Person(::google::protobuf::Arena* arena, Person&& from) noexcept
      : Person(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::MessageLite::ClassData* GetClassData()
      const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const final;
  // nested types ----------------------------------------------------
  using Role = Person_Role;

  // accessors -------------------------------------------------------
  enum : int {
    kRolesFieldNumber = 3,
    kNameFieldNumber = 1,
    kIdFieldNumber = 2,
  };
  // repeated .benchmarktesting.Person.Role roles = 3;
  int roles_size() const;
  private:
  int _internal_roles_size() const;

  public:
  void clear_roles() ;
  ::benchmarktesting::Person_Role* mutable_roles(int index);
  ::google::protobuf::RepeatedPtrField< ::benchmarktesting::Person_Role >*
      mutable_roles();
  private:
  const ::google::protobuf::RepeatedPtrField<::benchmarktesting::Person_Role>& _internal_roles() const;
  ::google::protobuf::RepeatedPtrField<::benchmarktesting::Person_Role>* _internal_mutable_roles();
  public:
  const ::benchmarktesting::Person_Role& roles(int index) const;
  ::benchmarktesting::Person_Role* add_roles();
  const ::google::protobuf::RepeatedPtrField< ::benchmarktesting::Person_Role >&
      roles() const;
  // optional string name = 1;
  bool has_name() const;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // optional int32 id = 2;
  bool has_id() const;
  void clear_id() ;
  ::int32_t id() const;
  void set_id(::int32_t value);

  private:
  ::int32_t _internal_id() const;
  void _internal_set_id(::int32_t value);

  public:
  // @@protoc_insertion_point(class_scope:benchmarktesting.Person)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 1,
      36, 2>
      _table_;
  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::RepeatedPtrField< ::benchmarktesting::Person_Role > roles_;
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::int32_t id_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_Person_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Person_Role

// optional string roleName = 1;
inline bool Person_Role::has_rolename() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Person_Role::clear_rolename() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.rolename_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Person_Role::rolename() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:benchmarktesting.Person.Role.roleName)
  return _internal_rolename();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Person_Role::set_rolename(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.rolename_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:benchmarktesting.Person.Role.roleName)
}
inline std::string* Person_Role::mutable_rolename() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_rolename();
  // @@protoc_insertion_point(field_mutable:benchmarktesting.Person.Role.roleName)
  return _s;
}
inline const std::string& Person_Role::_internal_rolename() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.rolename_.Get();
}
inline void Person_Role::_internal_set_rolename(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.rolename_.Set(value, GetArena());
}
inline std::string* Person_Role::_internal_mutable_rolename() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.rolename_.Mutable( GetArena());
}
inline std::string* Person_Role::release_rolename() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:benchmarktesting.Person.Role.roleName)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.rolename_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.rolename_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Person_Role::set_allocated_rolename(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.rolename_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.rolename_.IsDefault()) {
          _impl_.rolename_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:benchmarktesting.Person.Role.roleName)
}

// -------------------------------------------------------------------

// Person

// optional string name = 1;
inline bool Person::has_name() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline void Person::clear_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.name_.ClearToEmpty();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Person::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:benchmarktesting.Person.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Person::set_name(Arg_&& arg,
                                                     Args_... args) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:benchmarktesting.Person.name)
}
inline std::string* Person::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:benchmarktesting.Person.name)
  return _s;
}
inline const std::string& Person::_internal_name() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.name_.Get();
}
inline void Person::_internal_set_name(const std::string& value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.name_.Set(value, GetArena());
}
inline std::string* Person::_internal_mutable_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_._has_bits_[0] |= 0x00000001u;
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* Person::release_name() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  // @@protoc_insertion_point(field_release:benchmarktesting.Person.name)
  if ((_impl_._has_bits_[0] & 0x00000001u) == 0) {
    return nullptr;
  }
  _impl_._has_bits_[0] &= ~0x00000001u;
  auto* released = _impl_.name_.Release();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.name_.Set("", GetArena());
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return released;
}
inline void Person::set_allocated_name(std::string* value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  _impl_.name_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.name_.IsDefault()) {
          _impl_.name_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:benchmarktesting.Person.name)
}

// optional int32 id = 2;
inline bool Person::has_id() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline void Person::clear_id() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.id_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline ::int32_t Person::id() const {
  // @@protoc_insertion_point(field_get:benchmarktesting.Person.id)
  return _internal_id();
}
inline void Person::set_id(::int32_t value) {
  _internal_set_id(value);
  _impl_._has_bits_[0] |= 0x00000002u;
  // @@protoc_insertion_point(field_set:benchmarktesting.Person.id)
}
inline ::int32_t Person::_internal_id() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.id_;
}
inline void Person::_internal_set_id(::int32_t value) {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.id_ = value;
}

// repeated .benchmarktesting.Person.Role roles = 3;
inline int Person::_internal_roles_size() const {
  return _internal_roles().size();
}
inline int Person::roles_size() const {
  return _internal_roles_size();
}
inline void Person::clear_roles() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  _impl_.roles_.Clear();
}
inline ::benchmarktesting::Person_Role* Person::mutable_roles(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:benchmarktesting.Person.roles)
  return _internal_mutable_roles()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::benchmarktesting::Person_Role>* Person::mutable_roles()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:benchmarktesting.Person.roles)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  return _internal_mutable_roles();
}
inline const ::benchmarktesting::Person_Role& Person::roles(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:benchmarktesting.Person.roles)
  return _internal_roles().Get(index);
}
inline ::benchmarktesting::Person_Role* Person::add_roles() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::benchmarktesting::Person_Role* _add = _internal_mutable_roles()->Add();
  // @@protoc_insertion_point(field_add:benchmarktesting.Person.roles)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::benchmarktesting::Person_Role>& Person::roles() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:benchmarktesting.Person.roles)
  return _internal_roles();
}
inline const ::google::protobuf::RepeatedPtrField<::benchmarktesting::Person_Role>&
Person::_internal_roles() const {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return _impl_.roles_;
}
inline ::google::protobuf::RepeatedPtrField<::benchmarktesting::Person_Role>*
Person::_internal_mutable_roles() {
  PROTOBUF_TSAN_READ(&_impl_._tsan_detect_race);
  return &_impl_.roles_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace benchmarktesting


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_Person_2eproto_2epb_2eh