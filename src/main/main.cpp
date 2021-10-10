/**
 * Main file for the 2021-22 game - for now, just does Hello World.
 */

#include <gl/mesh.hpp>
#include <gl/shader.hpp>
#include <gl/texture.hpp>
#include <gl/window.hpp>
#include <main/util.hpp>

int main(int argc, char ** argv) {

	util::log("Game has initialized!", util::Severity::NORMAL);
    
    gl::Window wn{500, 500};

    gl::load_all_shaders();
    tex::load_all_textures();

    Mesh mesh{
        std::vector{-0.5f, -0.5f, -0.5f,  0.5f,  0.5f,  0.5f,  0.5f, -0.5f},
        std::vector{0, 1, 3, 3, 1, 2},
        std::vector{0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f}
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
