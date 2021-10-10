/**
 * Defines a window class for use, based on GLFW.
 */

#pragma once

#include <gl/glad.h>
#include <GLFW/glfw3.h>

namespace gl {

class Window {

    GLFWwindow * wn;

public:
    Window(int width, int height);
   ~Window();
    bool is_open();
    
    // Simple inlines
    inline void clear() { glClear(GL_COLOR_BUFFER_BIT); }
    inline void render() { glfwSwapBuffers(wn); }
    inline void poll_events() { glfwPollEvents(); }

};

}
