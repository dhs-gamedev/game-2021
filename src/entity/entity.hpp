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
    // Move by an offset
    inline void move(double x_off, double y_off) {
        x += x_off;
        y += y_off;
    }

};

// TODO - make this more secure
extern std::vector<Entity*> g_entities;

}
