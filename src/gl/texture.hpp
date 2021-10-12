/**
 * One texture.
 * TODO - texture atlasing perhaps?
 */

#pragma once

#include <memory>
#include <string>

#include <gl/glad.h>

namespace gl {

class Texture {

    // The OpenGL ID assigned to this texture.
    unsigned id;

public:
    Texture(std::string filename);
   ~Texture();
    void bind(); // Make this the currently drawn texture
    void unbind(); // Shouldn't need to be used often, actually

};

}

namespace tex {

// More textures here later?
extern std::unique_ptr<gl::Texture>
    GROUND_TEX,
    PLAYER_TEX;

void load_all_textures();

}
