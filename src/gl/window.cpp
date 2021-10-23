#include "window.hpp"

#include <gl/gl.h>

namespace gl {

Window::Window() {

#if defined(__APPLE__) || defined(__linux__)
    #define FULLSCREEN_SUPPORTED // We want to see where fullscreen is allowed
#endif // __APPLE__ || __linux__

    glfwInit();

    GL_INIT_CONTEXT();
#ifdef FULLSCREEN_SUPPORTED
    auto monitor = glfwGetPrimaryMonitor();
    auto vm = glfwGetVideoMode(monitor);
#endif

    this->wn = glfwCreateWindow(
#ifdef __linux__
        vm->width, vm->height,
#else
        500, 500,
#endif
        "Game 2021-22",
        nullptr,
        nullptr
    );

    glfwMakeContextCurrent(this->wn);
    gladLoadGL();
    glfwShowWindow(this->wn);
    // Test - apocalyptic gray
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

#ifdef __APPLE__
    glfwSetWindowAttrib(this->wn, GLFW_AUTO_ICONIFY, GLFW_FALSE);
    glfwFocusWindow(this->wn);
#endif

#ifdef FULLSCREEN_SUPPORTED
    glfwSetWindowMonitor(this->wn, monitor, 0, 0, vm->width, vm->height, vm->refreshRate);
    glfwSetWindowAttrib(this->wn, GLFW_RESIZABLE, GLFW_FALSE);
#endif

}

Window::~Window() {

    glfwDestroyWindow(this->wn);
    glfwTerminate();
}

bool Window::is_open() { return !glfwWindowShouldClose(wn); }

} // namespace gl
