#include "window.hpp"

namespace gl {

Window::Window(int width, int height) {

    glfwInit();

    this->wn = glfwCreateWindow(
        width, height, "Game 2021-22", nullptr, nullptr
    );
    glfwMakeContextCurrent(this->wn);
    glfwShowWindow(this->wn);

}

Window::~Window() {

    glfwDestroyWindow(this->wn);
    glfwTerminate();

}

bool Window::is_open() {
    return !glfwWindowShouldClose(wn);
}

}
