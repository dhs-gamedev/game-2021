/**
 * A basic entity in the world.
 */

#pragma once

#include <vector>

namespace ent {

class Entity {

protected:
    double x, y; // Positions in the world

public:
    Entity(double x, double y);
   ~Entity();
    virtual void render() = 0;

};

// TODO - make this more secure
extern std::vector<Entity*> g_entities;

}
