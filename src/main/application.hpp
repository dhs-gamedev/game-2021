/**
 * Main application class - all game variables and whatnot should be stored
 * here when we get them in the future.
 */

#pragma once

#include <entity/player.hpp>
#include <gl/window.hpp>

class Application {

private:
    gl::Window wn;
    ent::Player * player;

public:
    Application();
   ~Application();
    void mainloop();

friend class ent::Player;

};
