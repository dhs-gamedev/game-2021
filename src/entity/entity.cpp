#include "entity.hpp"

#include <main/application.hpp> // FRAMERATE

namespace ent {

Entity::Entity(double x, double y) {
    this->x = x;
    this->y = y;
    g_entities.push_back(this);
}

Entity::~Entity() {
    auto begin = g_entities.begin();
    for (auto it = begin; it < g_entities.end(); ++it) {
        if (g_entities.at(it - begin) == this) {
            g_entities.erase(it);
        }
    }
}

std::vector<Entity*> g_entities{};

void affect_all_with_gravity() {
    static const double GRAVITY_STRENGTH = 200.0;
    for (auto entity : g_entities) {
        entity->dy -= (GRAVITY_STRENGTH / (16 * FRAMERATE));
    }
}

void update_all_entities() {
    for (auto entity : g_entities) {
        entity->move(
            entity->dx / (16 * FRAMERATE),
            entity->dy / (16 * FRAMERATE)
        );
        // TODO - more?
    }
    affect_all_with_gravity();
}

}
