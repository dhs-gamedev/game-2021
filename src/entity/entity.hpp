/**
 * A basic entity in the world.
 */

#pragma once

#include <vector>

namespace ent {

class Entity {

protected:
    double x, y; // Positions in the world
    // How fast the object is moving, measured in 16ths of the screen PER SEC.
    double dx = 0, dy = 0;

public:
    Entity(double x, double y);
   ~Entity();
    virtual void render() = 0;
    // Move by an offset
    inline void move(double x_off, double y_off) {
        x += x_off;
        y += y_off;
    }

friend void affect_all_with_gravity();
friend void update_all_entities();

};

// TODO - make this more secure
extern std::vector<Entity*> g_entities;

void update_all_entities();

}
