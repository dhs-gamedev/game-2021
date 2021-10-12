#include "player.hpp"

#include <gl/mesh.hpp>
#include <gl/texture.hpp>
#include <main/application.hpp>

namespace ent {

Player::Player(double x, double y, Application * app)
: Entity(x, y) {
    app->player = this;
}

void Player::render() {
    tex::PLAYER_TEX->bind();
    Mesh mesh{
        std::vector<float>{
            (float)(x - 0.1f), (float)(y - 0.1f),
            (float)(x - 0.1f), (float)(y + 0.1f),
            (float)(x + 0.1f), (float)(y + 0.1f),
            (float)(x + 0.1f), (float)(y - 0.1f)
        },
        std::vector<int>{0, 1, 3, 3, 1, 2},
        std::vector<float>{0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f}
    };
    mesh.draw();
}

}
