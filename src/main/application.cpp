#include "application.hpp"

#include <iostream>
#include <vector>

#include <GLFW/glfw3.h>

#include <entity/entity.hpp>
#include <gl/mesh.hpp>
#include <gl/shader.hpp>
#include <gl/texture.hpp>
#include <main/util.hpp>

Application::Application()
: wn (500, 500) {
    gl::load_all_shaders();
    tex::load_all_textures();
    glfwSetWindowUserPointer(wn.wn, this);
    glfwSetKeyCallback(
        wn.wn,
        [](GLFWwindow * wn, int a, int b, int c, int d) {
            ((Application*)glfwGetWindowUserPointer(wn))->key_callback(wn, a, b, c, d);
        }
    );
    new ent::Player(0.0f, 0.0f, this);
}

void Application::mainloop() {
    Mesh bg_mesh{
        std::vector<float>{-1.f, -1.f, -1.f,  1.f,  1.f,  1.f,  1.f, -1.f},
        std::vector<int>{0, 1, 3, 3, 1, 2},
        std::vector<float>{0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f}
    };
    gl::GAME_SHADER->bind();

    while (wn.is_open()) {
        wn.clear();

        // World rendering
        tex::GROUND_TEX->bind();
        bg_mesh.draw();
        for (auto entity : ent::g_entities) {
            entity->render();
        }

        wn.render();
        wn.poll_events(); 
    }

    tex::GROUND_TEX->unbind();
}

Application::~Application() {
    // Nothing yet
    util::log("The application has finished exiting.", util::Severity::NORMAL);
}

void Application::key_callback(
    GLFWwindow * unused1,
    int key_code, int unused2, int action, int modifier_keys
) {
    std::cout << "Key event!\n";
}
