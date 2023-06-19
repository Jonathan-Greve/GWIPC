// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_UPDATEOPTIONS_GWIPC_H_
#define FLATBUFFERS_GENERATED_UPDATEOPTIONS_GWIPC_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace GWIPC {

struct UpdateOptions;
struct UpdateOptionsBuilder;

struct UpdateOptions FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef UpdateOptionsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ONLY_SEND_ACTIVE_QUEST_DESCRIPTION = 4,
    VT_ONLY_SEND_ACTIVE_QUEST_OBJECTIVES = 6,
    VT_SHOULD_UPDATE_CLIENT_DATA = 8
  };
  bool only_send_active_quest_description() const {
    return GetField<uint8_t>(VT_ONLY_SEND_ACTIVE_QUEST_DESCRIPTION, 0) != 0;
  }
  bool only_send_active_quest_objectives() const {
    return GetField<uint8_t>(VT_ONLY_SEND_ACTIVE_QUEST_OBJECTIVES, 0) != 0;
  }
  bool should_update_client_data() const {
    return GetField<uint8_t>(VT_SHOULD_UPDATE_CLIENT_DATA, 0) != 0;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_ONLY_SEND_ACTIVE_QUEST_DESCRIPTION, 1) &&
           VerifyField<uint8_t>(verifier, VT_ONLY_SEND_ACTIVE_QUEST_OBJECTIVES, 1) &&
           VerifyField<uint8_t>(verifier, VT_SHOULD_UPDATE_CLIENT_DATA, 1) &&
           verifier.EndTable();
  }
};

struct UpdateOptionsBuilder {
  typedef UpdateOptions Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_only_send_active_quest_description(bool only_send_active_quest_description) {
    fbb_.AddElement<uint8_t>(UpdateOptions::VT_ONLY_SEND_ACTIVE_QUEST_DESCRIPTION, static_cast<uint8_t>(only_send_active_quest_description), 0);
  }
  void add_only_send_active_quest_objectives(bool only_send_active_quest_objectives) {
    fbb_.AddElement<uint8_t>(UpdateOptions::VT_ONLY_SEND_ACTIVE_QUEST_OBJECTIVES, static_cast<uint8_t>(only_send_active_quest_objectives), 0);
  }
  void add_should_update_client_data(bool should_update_client_data) {
    fbb_.AddElement<uint8_t>(UpdateOptions::VT_SHOULD_UPDATE_CLIENT_DATA, static_cast<uint8_t>(should_update_client_data), 0);
  }
  explicit UpdateOptionsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<UpdateOptions> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<UpdateOptions>(end);
    return o;
  }
};

inline flatbuffers::Offset<UpdateOptions> CreateUpdateOptions(
    flatbuffers::FlatBufferBuilder &_fbb,
    bool only_send_active_quest_description = false,
    bool only_send_active_quest_objectives = false,
    bool should_update_client_data = false) {
  UpdateOptionsBuilder builder_(_fbb);
  builder_.add_should_update_client_data(should_update_client_data);
  builder_.add_only_send_active_quest_objectives(only_send_active_quest_objectives);
  builder_.add_only_send_active_quest_description(only_send_active_quest_description);
  return builder_.Finish();
}

inline const GWIPC::UpdateOptions *GetUpdateOptions(const void *buf) {
  return flatbuffers::GetRoot<GWIPC::UpdateOptions>(buf);
}

inline const GWIPC::UpdateOptions *GetSizePrefixedUpdateOptions(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<GWIPC::UpdateOptions>(buf);
}

inline bool VerifyUpdateOptionsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<GWIPC::UpdateOptions>(nullptr);
}

inline bool VerifySizePrefixedUpdateOptionsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<GWIPC::UpdateOptions>(nullptr);
}

inline void FinishUpdateOptionsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GWIPC::UpdateOptions> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedUpdateOptionsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GWIPC::UpdateOptions> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace GWIPC

#endif  // FLATBUFFERS_GENERATED_UPDATEOPTIONS_GWIPC_H_
