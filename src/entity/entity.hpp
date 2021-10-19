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
    enum EntityDirection {
        LEFT,
        RIGHT,
    } direction_facing;
    // Move by an offset
    void change_location(double x_off, double y_off);

public:
    Entity(double x, double y);
   ~Entity();
    virtual void render() = 0;

    bool is_on_ground();

    // Move and change direction
    void move(double x_off, double y_off);

friend void affect_all_with_gravity();
friend void update_all_entities();

};

// TODO - make this more secure
extern std::vector<Entity*> g_entities;

void update_all_entities();

}
