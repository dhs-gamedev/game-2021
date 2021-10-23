/**
 * Main application class - all game variables and whatnot should be stored
 * here when we get them in the future.
 */

#pragma once

#include <entity/player.hpp>
#include <gl/window.hpp>

const extern int FRAMERATE;
const extern double FLOOR_HEIGHT;

class Application {

private:
    gl::Window wn;
    ent::Player * player;
    void key_callback(GLFWwindow *, int, int, int, int);
    // When the window is resized
    void update_size(GLFWwindow *, int, int);
    // Loading in shaders and textures
    void load_resources();
    // Add key callback (later mouse callback?)
    void init_callbacks();
    // Start the game itself (player, etc.)
    void init_game();
    void exit_game();
    void unload_resources();

public:
    Application();
   ~Application();
    void mainloop();

friend class ent::Player;

};
