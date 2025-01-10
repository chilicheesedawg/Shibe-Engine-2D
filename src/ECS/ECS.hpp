#pragma once

#include <cstdint>
#include <bitset>
#include <vector>

///////////////////////////////////////////////////////////////
// bitset tracks which components an entity has
// also helps track which entities a system is interested in
///////////////////////////////////////////////////////////////
const uint8_t MAX_COMPONENTS = 32;
typedef std::bitset<MAX_COMPONENTS> Signature;

///////////////////////////////////////////////////////////////
// Components store pure data that can be manipulated
// by the registry
///////////////////////////////////////////////////////////////
class Component {
public:
  Component() = default;
  ~Component() = default;
  Component(const Component&) = default;

  int get_component_id() const;

private:
  int component_id;
};

///////////////////////////////////////////////////////////////
// Entity is an ID representing an object in the world 
///////////////////////////////////////////////////////////////
class Entity {
public:
  Entity(int id) : entity_id{id} {}
  ~Entity() = default;
  Entity(const Entity&) = default;

  int get_entity_id() const;

private:
  int entity_id;
};

///////////////////////////////////////////////////////////////
// System processes entities with a certain Signature
///////////////////////////////////////////////////////////////
class System {
public:
  System() = default;
  ~System() = default;
  System(const System&) = default;
  
  void add_entity_to_system(Entity entity);
  void remove_entity_from_system(Entity entity);
  std::vector<Entity> get_system_entities() const;
  Signature& get_component_signature() const;

private:
  Signature component_signature;
  std::vector<Entity> entities;
};

///////////////////////////////////////////////////////////////
// The registry can manipulate an entity and its components
///////////////////////////////////////////////////////////////
class Registry {
public:
  Registry() = default;
  ~Registry() = default;
  Registry(const Registry&) = default;

private:
  
};
