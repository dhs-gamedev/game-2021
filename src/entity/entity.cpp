#include "entity.hpp"

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

}
