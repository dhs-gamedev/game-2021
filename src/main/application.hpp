/**
 * Main application class - all game variables and whatnot should be stored
 * here when we get them in the future.
 */

#pragma once

#include <vector>

#include <entity/player.hpp>
#include <gl/text.hpp>
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

    // For redrawing the screen
    void redraw();

    // For cleanly shutting down the game
    bool running = true;

    // All labels (hacky - TOFIX)
    std::vector<gl::TextLabel*> labels;

public:
    Application();
   ~Application();
    void mainloop();
    void close();

friend class ent::Player;

};
