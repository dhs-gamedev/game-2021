/**
 * Main application class - all game variables and whatnot should be stored
 * here when we get them in the future.
 */

#pragma once

#include <gl/window.hpp>

class Application {

private:
    gl::Window wn;

public:
    Application();
   ~Application();
    void mainloop();

};
