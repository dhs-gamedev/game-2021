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
    tex::render_texture(
        x, y, WIDTH, HEIGHT,
        tex::RenderBasis::MID, tex::RenderBasis::LOW,
        tex::PLAYER_TEX.get()
    );
}

void Player::jump() {
    static const double PLAYER_JUMP_SPEED = 25.0;
    this->dy = PLAYER_JUMP_SPEED;
}

}
