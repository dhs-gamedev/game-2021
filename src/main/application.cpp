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
: wn () {
    util::init_log_system();
	util::log("Initializing application ...", util::Severity::DEBUG);
    this->load_resources();
    this->init_callbacks();
    util::log("Application was initialized!", util::Severity::DEBUG);
    util::log("Initializing game ...", util::Severity::DEBUG);
    this->init_game();
	util::log("Game was initialized!", util::Severity::NORMAL);
}

void Application::mainloop() {

    while (wn.is_open()) {

        auto start_of_frame = std::chrono::steady_clock::now();

        this->redraw();

        this->player->do_movement();
        ent::update_all_entities();
        wn.poll_events(); 

        std::this_thread::sleep_until(
            start_of_frame + std::chrono::milliseconds(
                (int) (1000.f / (float) FRAMERATE)
            )
        );

    }

}

Application::~Application() {
    this->exit_game();
    this->unload_resources();
    util::log("The application has finished exiting.", util::Severity::NORMAL);
    util::cleanup_log_system();
}

void Application::key_callback(
    GLFWwindow * unused1,
    int key_code, int unused2, int action, int modifier_keys
) {
    if (action != GLFW_REPEAT) {
        switch (key_code) {
            case GLFW_KEY_A:
            case GLFW_KEY_LEFT:
                this->player->set_moving_left(action == GLFW_PRESS);
                break;
            case GLFW_KEY_D:
            case GLFW_KEY_RIGHT:
                this->player->set_moving_right(action == GLFW_PRESS);
                break;
            case GLFW_KEY_SPACE:
            case GLFW_KEY_UP:
                this->player->set_jumping(action == GLFW_PRESS);
                break;
            default:
                break;
        }
    }
}

void Application::update_size(GLFWwindow * window, int width, int height) {
    // Update the shader uniform for size
    gl::GAME_SHADER->set_uniform_value("ratio", ((float) width) / ((float) height));
    // Redraw the screen so it doesn't stall.
    this->redraw();
}

void Application::redraw() {
        
    wn.clear();

    tex::render_texture(
        0, 0, 2, 2, tex::RenderBasis::MID, tex::RenderBasis::MID,
        tex::GROUND_TEX.get()
    );
    
    for (auto entity : ent::g_entities) {
        entity->render();
    }

    wn.render();
    
}

void Application::load_resources() {
    gl::load_all_shaders();
    tex::load_all_textures();
}

void Application::init_callbacks() {
    glfwSetWindowUserPointer(wn.wn, this);
    glfwSetKeyCallback(
        wn.wn,
        [](GLFWwindow * wn, int a, int b, int c, int d) {
            ((Application*)glfwGetWindowUserPointer(wn))->key_callback(wn, a, b, c, d);
        }
    );
    glfwSetWindowSizeCallback(
        wn.wn,
        [](GLFWwindow * wn, int width, int height) {
            ((Application*)glfwGetWindowUserPointer(wn))->update_size(wn, width, height);
        }
    );
}

void Application::init_game() {
    new ent::Player(0.0f, FLOOR_HEIGHT, this);
    gl::GAME_SHADER->bind();
    gl::GAME_SHADER->register_uniform("ratio");

    // Update size
    int w, h;
    glfwGetWindowSize(this->wn.wn, &w, &h);
    this->update_size(this->wn.wn, w, h);

    util::log("Teo was here!", util::Severity::NORMAL);
}

void Application::exit_game() {
    // Nothing yet
}

void Application::unload_resources() {
    tex::unload_all_textures();
    gl::unload_all_shaders();
}
