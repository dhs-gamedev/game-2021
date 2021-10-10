#include "texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <gl/stb_image.h>

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
