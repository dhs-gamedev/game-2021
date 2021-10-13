#pragma once

#include "entity.hpp"

class Application;

namespace ent {

class Player : public Entity {

private:
    Player(double x, double y);

public:
    // Must be constructed with an application argument
    Player(double x, double y, Application*);
   ~Player();
    void render() override;

    constexpr static const float WIDTH = 0.2f, HEIGHT = 0.2f;

};

}
