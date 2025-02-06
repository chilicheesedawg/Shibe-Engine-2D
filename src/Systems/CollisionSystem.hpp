#pragma once
#include "../ECS/ECS.hpp"
#include "../Components/BoxColliderComponent.hpp"
#include "../Components/TransformComponent.hpp"

class CollisionSystem : public System {
public:
  CollisionSystem() {
    require_component<BoxColliderComponent>();
    require_component<TransformComponent>();
  }
  ~CollisionSystem() = default;

  void Update(bool& is_colliding) {
    auto entities = get_system_entities();

    for (auto i = entities.begin(); i != entities.end(); i++) {
        auto& collider = i->get_component<BoxColliderComponent>();
        auto& transform = i->get_component<TransformComponent>();

        for (auto j = i + 1; j != entities.end(); j++) {
            auto& rhs_collider = j->get_component<BoxColliderComponent>();
            auto& rhs_transform = j->get_component<TransformComponent>();

            if(transform.position.x < rhs_transform.position.x + rhs_collider.width &&
                transform.position.x + collider.width > rhs_transform.position.x &&
                transform.position.y < rhs_transform.position.y + rhs_collider.height &&
                transform.position.y + collider.height > rhs_transform.position.y)
                  is_colliding = true;
            else
                  is_colliding = false;
        }
    }
  }
};
