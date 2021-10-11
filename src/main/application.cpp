#include "application.hpp"

#include <vector>

#include <gl/mesh.hpp>
#include <gl/shader.hpp>
#include <gl/texture.hpp>
#include <main/util.hpp>

Application::Application()
: wn (500, 500) {
    gl::load_all_shaders();
    tex::load_all_textures();
}

void Application::mainloop() {
    Mesh mesh{
        std::vector<float>{-1.f, -1.f, -1.f,  1.f,  1.f,  1.f,  1.f, -1.f},
        std::vector<int>{0, 1, 3, 3, 1, 2},
        std::vector<float>{0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f}
    };
    tex::GROUND_TEX->bind();
    gl::GAME_SHADER->bind();

    while (wn.is_open()) {
        wn.clear();
        mesh.draw();
        wn.render();
        wn.poll_events(); 
    }

    tex::GROUND_TEX->unbind();
}

Application::~Application() {
    // Nothing yet
    util::log("The application has finished exiting.", util::Severity::NORMAL);
}
