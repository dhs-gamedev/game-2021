#pragma once

#include "entity.hpp"

class Application;

namespace ent {

namespace move {
const unsigned LEFT  = 1,
               RIGHT = 2,
               JUMP  = 4;
}

class Player : public Entity {

private:
    Player(double x, double y);
    void jump();
    void move(EntityDirection dir);

    // Bitfield of movements (jumping, going left, etc.)
    unsigned active_movements = 0;

    void try_to_jump();
    void try_to_move(EntityDirection dir);

public:
    // Must be constructed with an application argument
    Player(double x, double y, Application*);
   ~Player();
    void render() override;

    constexpr static const float WIDTH = 0.2f,
                                 HEIGHT = 0.3f,
                                 SPEED = 15.0f;

    // Set whether the player will repeatedly do various movements
    void set_jumping(bool);
    void set_moving_left(bool);
    void set_moving_right(bool);

    void do_movement();

};

}
