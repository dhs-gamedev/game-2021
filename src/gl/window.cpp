#include "window.hpp"

#include <gl/gl.h>

namespace gl {

Window::Window() {

    glfwInit();

    GL_INIT_CONTEXT();
#ifdef __linux__
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
#ifdef __linux__
        monitor,
#else
        nullptr,
#endif
        nullptr);

    glfwMakeContextCurrent(this->wn);
    gladLoadGL();
    glfwShowWindow(this->wn);
    // Test - apocalyptic gray
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

    // Set window as non-resizable until the shaders are done being set up.
    glfwSetWindowAttrib(this->wn, GLFW_RESIZABLE, GLFW_FALSE);
}

Window::~Window() {

    glfwDestroyWindow(this->wn);
    glfwTerminate();
}

bool Window::is_open() { return !glfwWindowShouldClose(wn); }

} // namespace gl
