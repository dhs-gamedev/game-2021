#include "application.hpp"

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
    gl::GAME_SHADER->bind();

    while (wn.is_open()) {
        wn.clear();

        tex::render_texture(
            0, 0, 2, 2, tex::RenderBasis::MID, tex::RenderBasis::MID,
            tex::GROUND_TEX.get()
        );
        
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
    if (action == GLFW_PRESS) {
        switch (key_code) {
            case GLFW_KEY_A:
            case GLFW_KEY_LEFT:
                this->player->move(-0.05, 0);
                break;
            case GLFW_KEY_D:
            case GLFW_KEY_RIGHT:
                this->player->move( 0.05, 0);
                break;
            default:
                break;
        }
    }
}
