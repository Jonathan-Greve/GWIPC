// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CONNECTIONS_GWIPC_H_
#define FLATBUFFERS_GENERATED_CONNECTIONS_GWIPC_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace GWIPC {

struct Connections;
struct ConnectionsBuilder;

struct Connections FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ConnectionsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CONNECTED_IDS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *connected_ids() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_CONNECTED_IDS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CONNECTED_IDS) &&
           verifier.VerifyVector(connected_ids()) &&
           verifier.VerifyVectorOfStrings(connected_ids()) &&
           verifier.EndTable();
  }
};

struct ConnectionsBuilder {
  typedef Connections Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_connected_ids(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> connected_ids) {
    fbb_.AddOffset(Connections::VT_CONNECTED_IDS, connected_ids);
  }
  explicit ConnectionsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Connections> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Connections>(end);
    return o;
  }
};

inline flatbuffers::Offset<Connections> CreateConnections(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> connected_ids = 0) {
  ConnectionsBuilder builder_(_fbb);
  builder_.add_connected_ids(connected_ids);
  return builder_.Finish();
}

inline flatbuffers::Offset<Connections> CreateConnectionsDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *connected_ids = nullptr) {
  auto connected_ids__ = connected_ids ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*connected_ids) : 0;
  return GWIPC::CreateConnections(
      _fbb,
      connected_ids__);
}

inline const GWIPC::Connections *GetConnections(const void *buf) {
  return flatbuffers::GetRoot<GWIPC::Connections>(buf);
}

inline const GWIPC::Connections *GetSizePrefixedConnections(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<GWIPC::Connections>(buf);
}

inline bool VerifyConnectionsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<GWIPC::Connections>(nullptr);
}

inline bool VerifySizePrefixedConnectionsBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<GWIPC::Connections>(nullptr);
}

inline void FinishConnectionsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GWIPC::Connections> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedConnectionsBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GWIPC::Connections> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace GWIPC

#endif  // FLATBUFFERS_GENERATED_CONNECTIONS_GWIPC_H_
