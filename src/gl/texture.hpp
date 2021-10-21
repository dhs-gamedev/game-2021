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
    void destroy();

};

}

namespace tex {

// More textures here later?
extern std::unique_ptr<gl::Texture>
    GROUND_TEX,
    PLAYER_TEX;

void load_all_textures();
void unload_all_textures();

/**
 * What part of the texture the coordinates reference. e.g.: LOW, CENTER means
 * the x coordinate is the left of the figure and the y coordinate is the middle
 * of it.
 */
enum RenderBasis {
    LOW,
    MID,
    HI
};

// Whether the texture is rendered normal or mirrored
enum Mirrored {
    NORMAL,
    MIRRORED,
};

// Render a texture at a specific spot
void render_texture(
    double x, double y, double width, double height,
    RenderBasis xaxis_basis, RenderBasis yaxis_basis, gl::Texture * tex,
    Mirrored flip = Mirrored::NORMAL
);

}
