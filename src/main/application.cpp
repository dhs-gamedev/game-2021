#include "application.hpp"

#include <chrono>
#include <thread>
#include <vector>

#include <GLFW/glfw3.h>

#include <entity/entity.hpp>
#include <gl/mesh.hpp>
#include <gl/shader.hpp>
#include <gl/texture.hpp>
#include <main/util.hpp>

const int FRAMERATE = 60;

const  double FLOOR_HEIGHT = (18.f/100.f)*2-1;

Application::Application()
: wn (500, 500) {
	util::log("Initializing game ...", util::Severity::NORMAL);
    gl::load_all_shaders();
    tex::load_all_textures();
    glfwSetWindowUserPointer(wn.wn, this);
    glfwSetKeyCallback(
        wn.wn,
        [](GLFWwindow * wn, int a, int b, int c, int d) {
            ((Application*)glfwGetWindowUserPointer(wn))->key_callback(wn, a, b, c, d);
        }
    );
    new ent::Player(0.0f, FLOOR_HEIGHT, this);
	util::log("Game has initialized!", util::Severity::NORMAL);
}

void Application::mainloop() {
    gl::GAME_SHADER->bind();

    while (wn.is_open()) {

        auto start_of_frame = std::chrono::steady_clock::now();

        wn.clear();

        tex::render_texture(
            0, 0, 2, 2, tex::RenderBasis::MID, tex::RenderBasis::MID,
            tex::GROUND_TEX.get()
        );
        
        for (auto entity : ent::g_entities) {
            entity->render();
        }

        ent::update_all_entities();

        wn.render();
        wn.poll_events(); 

        std::this_thread::sleep_until(
            start_of_frame + std::chrono::milliseconds(
                (int) (1000.f / (float) FRAMERATE)
            )
        );

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
            case GLFW_KEY_SPACE:
            case GLFW_KEY_UP:
                this->player->try_to_jump();
                break;
            default:
                break;
        }
    }
}
