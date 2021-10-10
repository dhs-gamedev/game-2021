/**
 * One texture.
 * TODO - texture atlasing perhaps?
 */

#pragma once

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
