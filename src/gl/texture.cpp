#include "texture.hpp"

#include <gl/stb_image.h>

#include <gl/mesh.hpp>

namespace gl {

Texture::Texture(std::string name) {

    stbi_set_flip_vertically_on_load(true);

    // STB stuffs these with data
    int w, h, channels;
    auto data = stbi_load(name.c_str(), &w, &h, &channels, 0);
    if (!data)
        ; // TODO - error out
    
    glGenTextures(1, &this->id);
    this->bind();

    // It's a pixel art game, we don't want the textures to appear blurry
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

}

Texture::~Texture() {
    glDeleteTextures(1, &this->id);
}

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, this->id);
}

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}

}

namespace tex {

std::unique_ptr<gl::Texture> GROUND_TEX,
                             PLAYER_TEX;

void load_all_textures() {
    GROUND_TEX = std::make_unique<gl::Texture>("res/tex/background.png");
    PLAYER_TEX = std::make_unique<gl::Texture>("res/tex/player-idea.png");
}

void render_texture(
    double x, double y, double width, double height,
    RenderBasis xbasis, RenderBasis ybasis, gl::Texture * tex) {
    float x_off, y_off;
    switch (xbasis) {
        case LOW:
            x_off = 0;
            break;
        case MID:
            x_off = - width / 2;
            break;
        case HI:
            x_off = - width;
            break;
    }
    switch (ybasis) {
        case LOW:
            y_off = 0;
            break;
        case MID:
            y_off = - height / 2;
            break;
        case HI:
            y_off = - height;
            break;
    }
    float
        xb = (float) x + x_off,
        yb = (float) y + y_off,
        wb = (float) width,
        hb = (float) height;
    Mesh mesh {
        std::vector<float>{
            xb,      yb,
            xb,      yb + hb,
            xb + wb, yb + hb,
            xb + wb, yb
        },
        std::vector<int>{0, 1, 3, 3, 1, 2},
        std::vector<float>{0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f}
    };
    tex->bind();
    mesh.draw();
}

}
