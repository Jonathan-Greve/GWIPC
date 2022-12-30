// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENTDATA_GWIPC_H_
#define FLATBUFFERS_GENERATED_CLIENTDATA_GWIPC_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 22 &&
              FLATBUFFERS_VERSION_MINOR == 10 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

namespace GWIPC {

struct Vec2;

struct Vec3;

struct Agent;

struct AgentLiving;
struct AgentLivingBuilder;

struct Character;
struct CharacterBuilder;

struct Party;
struct PartyBuilder;

struct Instance;
struct InstanceBuilder;

struct ClientData;
struct ClientDataBuilder;

enum TeamColor : int8_t {
  TeamColor_None = 0,
  TeamColor_Blue = 1,
  TeamColor_Red = 2,
  TeamColor_Yellow = 3,
  TeamColor_MIN = TeamColor_None,
  TeamColor_MAX = TeamColor_Yellow
};

inline const TeamColor (&EnumValuesTeamColor())[4] {
  static const TeamColor values[] = {
    TeamColor_None,
    TeamColor_Blue,
    TeamColor_Red,
    TeamColor_Yellow
  };
  return values;
}

inline const char * const *EnumNamesTeamColor() {
  static const char * const names[5] = {
    "None",
    "Blue",
    "Red",
    "Yellow",
    nullptr
  };
  return names;
}

inline const char *EnumNameTeamColor(TeamColor e) {
  if (flatbuffers::IsOutRange(e, TeamColor_None, TeamColor_Yellow)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesTeamColor()[index];
}

enum Profession : int8_t {
  Profession_None = 0,
  Profession_Warrior = 1,
  Profession_Ranger = 2,
  Profession_Monk = 3,
  Profession_Necromancer = 4,
  Profession_Mesmer = 5,
  Profession_Elementalist = 6,
  Profession_Assassin = 7,
  Profession_Ritualist = 8,
  Profession_Paragon = 9,
  Profession_Dervish = 10,
  Profession_MIN = Profession_None,
  Profession_MAX = Profession_Dervish
};

inline const Profession (&EnumValuesProfession())[11] {
  static const Profession values[] = {
    Profession_None,
    Profession_Warrior,
    Profession_Ranger,
    Profession_Monk,
    Profession_Necromancer,
    Profession_Mesmer,
    Profession_Elementalist,
    Profession_Assassin,
    Profession_Ritualist,
    Profession_Paragon,
    Profession_Dervish
  };
  return values;
}

inline const char * const *EnumNamesProfession() {
  static const char * const names[12] = {
    "None",
    "Warrior",
    "Ranger",
    "Monk",
    "Necromancer",
    "Mesmer",
    "Elementalist",
    "Assassin",
    "Ritualist",
    "Paragon",
    "Dervish",
    nullptr
  };
  return names;
}

inline const char *EnumNameProfession(Profession e) {
  if (flatbuffers::IsOutRange(e, Profession_None, Profession_Dervish)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesProfession()[index];
}

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) Vec2 FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;

 public:
  Vec2()
      : x_(0),
        y_(0) {
  }
  Vec2(float _x, float _y)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
};
FLATBUFFERS_STRUCT_END(Vec2, 8);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) Vec3 FLATBUFFERS_FINAL_CLASS {
 private:
  float x_;
  float y_;
  float z_;

 public:
  Vec3()
      : x_(0),
        y_(0),
        z_(0) {
  }
  Vec3(float _x, float _y, float _z)
      : x_(flatbuffers::EndianScalar(_x)),
        y_(flatbuffers::EndianScalar(_y)),
        z_(flatbuffers::EndianScalar(_z)) {
  }
  float x() const {
    return flatbuffers::EndianScalar(x_);
  }
  float y() const {
    return flatbuffers::EndianScalar(y_);
  }
  float z() const {
    return flatbuffers::EndianScalar(z_);
  }
};
FLATBUFFERS_STRUCT_END(Vec3, 12);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(4) Agent FLATBUFFERS_FINAL_CLASS {
 private:
  uint32_t agent_id_;
  GWIPC::Vec3 position_;
  GWIPC::Vec3 terrain_normal_;
  float rotation_;
  GWIPC::Vec2 velocity_;
  float model_width_;
  float model_height_;
  uint32_t instance_timer_;

 public:
  Agent()
      : agent_id_(0),
        position_(),
        terrain_normal_(),
        rotation_(0),
        velocity_(),
        model_width_(0),
        model_height_(0),
        instance_timer_(0) {
  }
  Agent(uint32_t _agent_id, const GWIPC::Vec3 &_position, const GWIPC::Vec3 &_terrain_normal, float _rotation, const GWIPC::Vec2 &_velocity, float _model_width, float _model_height, uint32_t _instance_timer)
      : agent_id_(flatbuffers::EndianScalar(_agent_id)),
        position_(_position),
        terrain_normal_(_terrain_normal),
        rotation_(flatbuffers::EndianScalar(_rotation)),
        velocity_(_velocity),
        model_width_(flatbuffers::EndianScalar(_model_width)),
        model_height_(flatbuffers::EndianScalar(_model_height)),
        instance_timer_(flatbuffers::EndianScalar(_instance_timer)) {
  }
  uint32_t agent_id() const {
    return flatbuffers::EndianScalar(agent_id_);
  }
  const GWIPC::Vec3 &position() const {
    return position_;
  }
  const GWIPC::Vec3 &terrain_normal() const {
    return terrain_normal_;
  }
  float rotation() const {
    return flatbuffers::EndianScalar(rotation_);
  }
  const GWIPC::Vec2 &velocity() const {
    return velocity_;
  }
  float model_width() const {
    return flatbuffers::EndianScalar(model_width_);
  }
  float model_height() const {
    return flatbuffers::EndianScalar(model_height_);
  }
  uint32_t instance_timer() const {
    return flatbuffers::EndianScalar(instance_timer_);
  }
};
FLATBUFFERS_STRUCT_END(Agent, 52);

struct AgentLiving FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef AgentLivingBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_AGENT = 4,
    VT_NAME = 6,
    VT_OWNER_AGENT_ID = 8,
    VT_ANIMATION_TYPE = 10,
    VT_WEAPON_ATTACK_SPEED = 12,
    VT_WEAPON_ATTACK_SPEED_MODIFIER = 14,
    VT_PLAYER_NUMBER = 16,
    VT_PRIMARY_PROFESSION = 18,
    VT_SECONDARY_PROFESSION = 20,
    VT_TEAM_COLOR = 22,
    VT_GUILD_ID = 24,
    VT_LEVEL = 26,
    VT_HEALTH = 28,
    VT_MAX_HEALTH = 30,
    VT_HEALTH_RECHARGE = 32,
    VT_ENERGY = 34,
    VT_MAX_ENERGY = 36,
    VT_ENERGY_RECHARGE = 38
  };
  const GWIPC::Agent *agent() const {
    return GetStruct<const GWIPC::Agent *>(VT_AGENT);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  uint32_t owner_agent_id() const {
    return GetField<uint32_t>(VT_OWNER_AGENT_ID, 0);
  }
  float animation_type() const {
    return GetField<float>(VT_ANIMATION_TYPE, 0.0f);
  }
  float weapon_attack_speed() const {
    return GetField<float>(VT_WEAPON_ATTACK_SPEED, 0.0f);
  }
  float weapon_attack_speed_modifier() const {
    return GetField<float>(VT_WEAPON_ATTACK_SPEED_MODIFIER, 0.0f);
  }
  uint32_t player_number() const {
    return GetField<uint32_t>(VT_PLAYER_NUMBER, 0);
  }
  GWIPC::Profession primary_profession() const {
    return static_cast<GWIPC::Profession>(GetField<int8_t>(VT_PRIMARY_PROFESSION, 0));
  }
  GWIPC::Profession secondary_profession() const {
    return static_cast<GWIPC::Profession>(GetField<int8_t>(VT_SECONDARY_PROFESSION, 0));
  }
  GWIPC::TeamColor team_color() const {
    return static_cast<GWIPC::TeamColor>(GetField<int8_t>(VT_TEAM_COLOR, 0));
  }
  uint16_t guild_id() const {
    return GetField<uint16_t>(VT_GUILD_ID, 0);
  }
  uint8_t level() const {
    return GetField<uint8_t>(VT_LEVEL, 0);
  }
  float health() const {
    return GetField<float>(VT_HEALTH, 0.0f);
  }
  float max_health() const {
    return GetField<float>(VT_MAX_HEALTH, 0.0f);
  }
  float health_recharge() const {
    return GetField<float>(VT_HEALTH_RECHARGE, 0.0f);
  }
  float energy() const {
    return GetField<float>(VT_ENERGY, 0.0f);
  }
  float max_energy() const {
    return GetField<float>(VT_MAX_ENERGY, 0.0f);
  }
  float energy_recharge() const {
    return GetField<float>(VT_ENERGY_RECHARGE, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<GWIPC::Agent>(verifier, VT_AGENT, 4) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint32_t>(verifier, VT_OWNER_AGENT_ID, 4) &&
           VerifyField<float>(verifier, VT_ANIMATION_TYPE, 4) &&
           VerifyField<float>(verifier, VT_WEAPON_ATTACK_SPEED, 4) &&
           VerifyField<float>(verifier, VT_WEAPON_ATTACK_SPEED_MODIFIER, 4) &&
           VerifyField<uint32_t>(verifier, VT_PLAYER_NUMBER, 4) &&
           VerifyField<int8_t>(verifier, VT_PRIMARY_PROFESSION, 1) &&
           VerifyField<int8_t>(verifier, VT_SECONDARY_PROFESSION, 1) &&
           VerifyField<int8_t>(verifier, VT_TEAM_COLOR, 1) &&
           VerifyField<uint16_t>(verifier, VT_GUILD_ID, 2) &&
           VerifyField<uint8_t>(verifier, VT_LEVEL, 1) &&
           VerifyField<float>(verifier, VT_HEALTH, 4) &&
           VerifyField<float>(verifier, VT_MAX_HEALTH, 4) &&
           VerifyField<float>(verifier, VT_HEALTH_RECHARGE, 4) &&
           VerifyField<float>(verifier, VT_ENERGY, 4) &&
           VerifyField<float>(verifier, VT_MAX_ENERGY, 4) &&
           VerifyField<float>(verifier, VT_ENERGY_RECHARGE, 4) &&
           verifier.EndTable();
  }
};

struct AgentLivingBuilder {
  typedef AgentLiving Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_agent(const GWIPC::Agent *agent) {
    fbb_.AddStruct(AgentLiving::VT_AGENT, agent);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(AgentLiving::VT_NAME, name);
  }
  void add_owner_agent_id(uint32_t owner_agent_id) {
    fbb_.AddElement<uint32_t>(AgentLiving::VT_OWNER_AGENT_ID, owner_agent_id, 0);
  }
  void add_animation_type(float animation_type) {
    fbb_.AddElement<float>(AgentLiving::VT_ANIMATION_TYPE, animation_type, 0.0f);
  }
  void add_weapon_attack_speed(float weapon_attack_speed) {
    fbb_.AddElement<float>(AgentLiving::VT_WEAPON_ATTACK_SPEED, weapon_attack_speed, 0.0f);
  }
  void add_weapon_attack_speed_modifier(float weapon_attack_speed_modifier) {
    fbb_.AddElement<float>(AgentLiving::VT_WEAPON_ATTACK_SPEED_MODIFIER, weapon_attack_speed_modifier, 0.0f);
  }
  void add_player_number(uint32_t player_number) {
    fbb_.AddElement<uint32_t>(AgentLiving::VT_PLAYER_NUMBER, player_number, 0);
  }
  void add_primary_profession(GWIPC::Profession primary_profession) {
    fbb_.AddElement<int8_t>(AgentLiving::VT_PRIMARY_PROFESSION, static_cast<int8_t>(primary_profession), 0);
  }
  void add_secondary_profession(GWIPC::Profession secondary_profession) {
    fbb_.AddElement<int8_t>(AgentLiving::VT_SECONDARY_PROFESSION, static_cast<int8_t>(secondary_profession), 0);
  }
  void add_team_color(GWIPC::TeamColor team_color) {
    fbb_.AddElement<int8_t>(AgentLiving::VT_TEAM_COLOR, static_cast<int8_t>(team_color), 0);
  }
  void add_guild_id(uint16_t guild_id) {
    fbb_.AddElement<uint16_t>(AgentLiving::VT_GUILD_ID, guild_id, 0);
  }
  void add_level(uint8_t level) {
    fbb_.AddElement<uint8_t>(AgentLiving::VT_LEVEL, level, 0);
  }
  void add_health(float health) {
    fbb_.AddElement<float>(AgentLiving::VT_HEALTH, health, 0.0f);
  }
  void add_max_health(float max_health) {
    fbb_.AddElement<float>(AgentLiving::VT_MAX_HEALTH, max_health, 0.0f);
  }
  void add_health_recharge(float health_recharge) {
    fbb_.AddElement<float>(AgentLiving::VT_HEALTH_RECHARGE, health_recharge, 0.0f);
  }
  void add_energy(float energy) {
    fbb_.AddElement<float>(AgentLiving::VT_ENERGY, energy, 0.0f);
  }
  void add_max_energy(float max_energy) {
    fbb_.AddElement<float>(AgentLiving::VT_MAX_ENERGY, max_energy, 0.0f);
  }
  void add_energy_recharge(float energy_recharge) {
    fbb_.AddElement<float>(AgentLiving::VT_ENERGY_RECHARGE, energy_recharge, 0.0f);
  }
  explicit AgentLivingBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<AgentLiving> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<AgentLiving>(end);
    return o;
  }
};

inline flatbuffers::Offset<AgentLiving> CreateAgentLiving(
    flatbuffers::FlatBufferBuilder &_fbb,
    const GWIPC::Agent *agent = nullptr,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    uint32_t owner_agent_id = 0,
    float animation_type = 0.0f,
    float weapon_attack_speed = 0.0f,
    float weapon_attack_speed_modifier = 0.0f,
    uint32_t player_number = 0,
    GWIPC::Profession primary_profession = GWIPC::Profession_None,
    GWIPC::Profession secondary_profession = GWIPC::Profession_None,
    GWIPC::TeamColor team_color = GWIPC::TeamColor_None,
    uint16_t guild_id = 0,
    uint8_t level = 0,
    float health = 0.0f,
    float max_health = 0.0f,
    float health_recharge = 0.0f,
    float energy = 0.0f,
    float max_energy = 0.0f,
    float energy_recharge = 0.0f) {
  AgentLivingBuilder builder_(_fbb);
  builder_.add_energy_recharge(energy_recharge);
  builder_.add_max_energy(max_energy);
  builder_.add_energy(energy);
  builder_.add_health_recharge(health_recharge);
  builder_.add_max_health(max_health);
  builder_.add_health(health);
  builder_.add_player_number(player_number);
  builder_.add_weapon_attack_speed_modifier(weapon_attack_speed_modifier);
  builder_.add_weapon_attack_speed(weapon_attack_speed);
  builder_.add_animation_type(animation_type);
  builder_.add_owner_agent_id(owner_agent_id);
  builder_.add_name(name);
  builder_.add_agent(agent);
  builder_.add_guild_id(guild_id);
  builder_.add_level(level);
  builder_.add_team_color(team_color);
  builder_.add_secondary_profession(secondary_profession);
  builder_.add_primary_profession(primary_profession);
  return builder_.Finish();
}

inline flatbuffers::Offset<AgentLiving> CreateAgentLivingDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const GWIPC::Agent *agent = nullptr,
    const char *name = nullptr,
    uint32_t owner_agent_id = 0,
    float animation_type = 0.0f,
    float weapon_attack_speed = 0.0f,
    float weapon_attack_speed_modifier = 0.0f,
    uint32_t player_number = 0,
    GWIPC::Profession primary_profession = GWIPC::Profession_None,
    GWIPC::Profession secondary_profession = GWIPC::Profession_None,
    GWIPC::TeamColor team_color = GWIPC::TeamColor_None,
    uint16_t guild_id = 0,
    uint8_t level = 0,
    float health = 0.0f,
    float max_health = 0.0f,
    float health_recharge = 0.0f,
    float energy = 0.0f,
    float max_energy = 0.0f,
    float energy_recharge = 0.0f) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return GWIPC::CreateAgentLiving(
      _fbb,
      agent,
      name__,
      owner_agent_id,
      animation_type,
      weapon_attack_speed,
      weapon_attack_speed_modifier,
      player_number,
      primary_profession,
      secondary_profession,
      team_color,
      guild_id,
      level,
      health,
      max_health,
      health_recharge,
      energy,
      max_energy,
      energy_recharge);
}

struct Character FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CharacterBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_AGENT_LIVING = 4
  };
  const GWIPC::AgentLiving *agent_living() const {
    return GetPointer<const GWIPC::AgentLiving *>(VT_AGENT_LIVING);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_AGENT_LIVING) &&
           verifier.VerifyTable(agent_living()) &&
           verifier.EndTable();
  }
};

struct CharacterBuilder {
  typedef Character Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_agent_living(flatbuffers::Offset<GWIPC::AgentLiving> agent_living) {
    fbb_.AddOffset(Character::VT_AGENT_LIVING, agent_living);
  }
  explicit CharacterBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Character> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Character>(end);
    return o;
  }
};

inline flatbuffers::Offset<Character> CreateCharacter(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<GWIPC::AgentLiving> agent_living = 0) {
  CharacterBuilder builder_(_fbb);
  builder_.add_agent_living(agent_living);
  return builder_.Finish();
}

struct Party FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef PartyBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PARTY_ID = 4,
    VT_LEADER_AGENT_ID = 6
  };
  uint32_t party_id() const {
    return GetField<uint32_t>(VT_PARTY_ID, 0);
  }
  uint32_t leader_agent_id() const {
    return GetField<uint32_t>(VT_LEADER_AGENT_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_PARTY_ID, 4) &&
           VerifyField<uint32_t>(verifier, VT_LEADER_AGENT_ID, 4) &&
           verifier.EndTable();
  }
};

struct PartyBuilder {
  typedef Party Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_party_id(uint32_t party_id) {
    fbb_.AddElement<uint32_t>(Party::VT_PARTY_ID, party_id, 0);
  }
  void add_leader_agent_id(uint32_t leader_agent_id) {
    fbb_.AddElement<uint32_t>(Party::VT_LEADER_AGENT_ID, leader_agent_id, 0);
  }
  explicit PartyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Party> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Party>(end);
    return o;
  }
};

inline flatbuffers::Offset<Party> CreateParty(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t party_id = 0,
    uint32_t leader_agent_id = 0) {
  PartyBuilder builder_(_fbb);
  builder_.add_leader_agent_id(leader_agent_id);
  builder_.add_party_id(party_id);
  return builder_.Finish();
}

struct Instance FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef InstanceBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_INSTANCE_ID = 4,
    VT_MAP_ID = 6
  };
  uint32_t instance_id() const {
    return GetField<uint32_t>(VT_INSTANCE_ID, 0);
  }
  uint32_t map_id() const {
    return GetField<uint32_t>(VT_MAP_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_INSTANCE_ID, 4) &&
           VerifyField<uint32_t>(verifier, VT_MAP_ID, 4) &&
           verifier.EndTable();
  }
};

struct InstanceBuilder {
  typedef Instance Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_instance_id(uint32_t instance_id) {
    fbb_.AddElement<uint32_t>(Instance::VT_INSTANCE_ID, instance_id, 0);
  }
  void add_map_id(uint32_t map_id) {
    fbb_.AddElement<uint32_t>(Instance::VT_MAP_ID, map_id, 0);
  }
  explicit InstanceBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Instance> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Instance>(end);
    return o;
  }
};

inline flatbuffers::Offset<Instance> CreateInstance(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t instance_id = 0,
    uint32_t map_id = 0) {
  InstanceBuilder builder_(_fbb);
  builder_.add_map_id(map_id);
  builder_.add_instance_id(instance_id);
  return builder_.Finish();
}

struct ClientData FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ClientDataBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CHARACTER = 4,
    VT_INSTANCE = 6,
    VT_PARTY = 8
  };
  const GWIPC::Character *character() const {
    return GetPointer<const GWIPC::Character *>(VT_CHARACTER);
  }
  const GWIPC::Instance *instance() const {
    return GetPointer<const GWIPC::Instance *>(VT_INSTANCE);
  }
  const GWIPC::Party *party() const {
    return GetPointer<const GWIPC::Party *>(VT_PARTY);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CHARACTER) &&
           verifier.VerifyTable(character()) &&
           VerifyOffset(verifier, VT_INSTANCE) &&
           verifier.VerifyTable(instance()) &&
           VerifyOffset(verifier, VT_PARTY) &&
           verifier.VerifyTable(party()) &&
           verifier.EndTable();
  }
};

struct ClientDataBuilder {
  typedef ClientData Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_character(flatbuffers::Offset<GWIPC::Character> character) {
    fbb_.AddOffset(ClientData::VT_CHARACTER, character);
  }
  void add_instance(flatbuffers::Offset<GWIPC::Instance> instance) {
    fbb_.AddOffset(ClientData::VT_INSTANCE, instance);
  }
  void add_party(flatbuffers::Offset<GWIPC::Party> party) {
    fbb_.AddOffset(ClientData::VT_PARTY, party);
  }
  explicit ClientDataBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ClientData> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ClientData>(end);
    return o;
  }
};

inline flatbuffers::Offset<ClientData> CreateClientData(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<GWIPC::Character> character = 0,
    flatbuffers::Offset<GWIPC::Instance> instance = 0,
    flatbuffers::Offset<GWIPC::Party> party = 0) {
  ClientDataBuilder builder_(_fbb);
  builder_.add_party(party);
  builder_.add_instance(instance);
  builder_.add_character(character);
  return builder_.Finish();
}

inline const GWIPC::ClientData *GetClientData(const void *buf) {
  return flatbuffers::GetRoot<GWIPC::ClientData>(buf);
}

inline const GWIPC::ClientData *GetSizePrefixedClientData(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<GWIPC::ClientData>(buf);
}

inline bool VerifyClientDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<GWIPC::ClientData>(nullptr);
}

inline bool VerifySizePrefixedClientDataBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<GWIPC::ClientData>(nullptr);
}

inline void FinishClientDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GWIPC::ClientData> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedClientDataBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<GWIPC::ClientData> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace GWIPC

#endif  // FLATBUFFERS_GENERATED_CLIENTDATA_GWIPC_H_