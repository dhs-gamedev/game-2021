/**
 * A wrapper around a complete shader program.
 */

#pragma once

#include <map>
#include <memory>
#include <string>

#include <gl/glad.h>

namespace gl {

class Shader {

private:
    // The OpenGL ID of this shader.
    unsigned program_id;
    // Create a single vertex or fragment shader.
    int create_subshader(const char* code, int type);
    // Finalize the shader.
    void link(int vert, int frag);

    // All uniforms.
    std::map<std::string, int> uniforms;

public:
    // Take in the file paths.
    Shader(const char* vertex_path, const char* fragment_path);
   ~Shader();

    void bind(); // set as active shader
    void unbind();
    void destroy();

    void register_uniform(std::string name);
    void set_uniform_value(std::string name, float value);

friend void unload_all_shaders();

};

extern std::unique_ptr<Shader> GAME_SHADER, // the basic shader
                               TEXT_SHADER;

/**
 * Initialize all shaders (for now just one)
 */
void load_all_shaders();
void unload_all_shaders();

}
