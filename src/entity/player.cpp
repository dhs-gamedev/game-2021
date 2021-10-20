#include "player.hpp"

#include <gl/mesh.hpp>
#include <gl/texture.hpp>
#include <main/application.hpp>

namespace ent {

Player::Player(double x, double y, Application * app)
: Entity(x, y) {
    app->player = this;
    this->direction_facing = EntityDirection::RIGHT;
}

void Player::render() {
    tex::render_texture(
        x, y, WIDTH, HEIGHT,
        tex::RenderBasis::MID, tex::RenderBasis::LOW,
        tex::PLAYER_TEX.get(),
        (this->direction_facing == LEFT)
            ? tex::Mirrored::MIRRORED
            : tex::Mirrored::NORMAL
    );
}

void Player::jump() {
    static const double PLAYER_JUMP_SPEED = 25.0;
    this->dy = PLAYER_JUMP_SPEED;
}

void Player::try_to_jump() {
    if (this->is_on_ground()) this->jump();
}

void Player::try_to_move(EntityDirection dir) {
    if (this->is_on_ground()) this->move(dir);
}

void Player::move(EntityDirection dir) {

    if (dir == EntityDirection::LEFT) {
        this->dx = -SPEED;
    } else {
        this->dx =  SPEED;
    }

}

void Player::set_jumping(bool b) {
    if (b) {
        this->active_movements |=  move::JUMP;
    } else {
        this->active_movements &= ~move::JUMP;
    }
}

void Player::set_moving_right(bool b) {
    if (b) {
        this->active_movements |=  move::RIGHT;
        this->active_movements &= ~move::LEFT;
    } else {
        this->active_movements &= ~move::RIGHT;
    }
}

void Player::set_moving_left(bool b) {
    if (b) {
        this->active_movements |=  move::LEFT;
        this->active_movements &= ~move::RIGHT;
    } else {
        this->active_movements &= ~move::LEFT;
    }
}

void Player::do_movement() {
    if (this->active_movements & move::JUMP) {
        this->try_to_jump();
    }
    if (this->active_movements & move::LEFT) {
        this->try_to_move(EntityDirection::LEFT);
    }
    if (this->active_movements & move::RIGHT) {
        this->try_to_move(EntityDirection::RIGHT);
    }
}

}
