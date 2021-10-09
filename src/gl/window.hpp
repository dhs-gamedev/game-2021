/**
 * Defines a window class for use, based on GLFW.
 */

#include <GLFW/glfw3.h>

namespace gl {

class Window {

    GLFWwindow * wn;

public:
    Window(int width, int height);
   ~Window();
    bool is_open();
    
    // Simple inlines
    inline void render() { glfwSwapBuffers(wn); }
    inline void poll_events() { glfwPollEvents(); }

};

}
