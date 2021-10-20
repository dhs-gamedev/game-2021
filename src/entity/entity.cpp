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
    static const double GRAVITY_STRENGTH = 2000.0;
    for (auto entity : g_entities) {
        entity->dy -= (GRAVITY_STRENGTH / (16 * FRAMERATE));
    }
}

void update_all_entities() {
    static const double FRICTION = 0.2;
    for (auto entity : g_entities) {
        entity->move(
            entity->dx / (16 * FRAMERATE),
            entity->dy / (16 * FRAMERATE)
        );
        // Scuffed floor collision detection
        // DO NOT replace with is_on_ground(), that would probably render the
        // player unable to jump
        if (entity->y < FLOOR_HEIGHT) {
            entity->y = FLOOR_HEIGHT;
        }
        // Do friction!
        if (entity->is_on_ground()) {
            entity->dx *= (1.0 - FRICTION);
        }
        // TODO - more?
    }
    affect_all_with_gravity();
}

bool Entity::is_on_ground() {
    return this->y <= FLOOR_HEIGHT;
}
void Entity::change_location(double x_off, double y_off) {
    x += x_off;
    y += y_off;
}

void Entity::move(double x_off, double y_off) {
    this->change_location(x_off, y_off);
    if (x_off > 0) this->direction_facing = RIGHT;
    if (x_off < 0) this->direction_facing = LEFT ;
}

}
