#include "shader.hpp"

#include <stdio.h>
#include <string>

#include <gl/glad.h>

namespace {

// Load a whole file as a string.
const GLchar* load_file_as_string(const char* path) {
    // TODO - do this with C++ classes.
    FILE* fp = fopen(path, "r");
    if (!fp) return nullptr;
    fseek(fp, 0, SEEK_END);
    int len = ftell(fp);
    // Yes, I know the memes. Haha. Funny.
    char* code = (char*) malloc(len + 1);
    rewind(fp);
    for (int pos = 0; pos < len; ++pos) {
        code[pos] = getc(fp);
    }
    code[len] = 0;
    return code;
}

}

namespace gl {

Shader::Shader(const char* vertex_path, const char* fragment_path) {

    this->program_id = glCreateProgram();
    // TODO - check for error

    auto vertcode = load_file_as_string(vertex_path), fragcode = load_file_as_string(fragment_path);
    int vert = create_subshader(vertcode, GL_VERTEX_SHADER);
    int frag = create_subshader(fragcode, GL_FRAGMENT_SHADER);

    this->link(vert, frag);

    free((void*) vertcode);
    free((void*) fragcode);
    
}

int Shader::create_subshader(const GLchar* code, int type) {

    int id = glCreateShader(type);
    // TODO - check if id == 0

    glShaderSource(id, 1, &code, nullptr);
    glCompileShader(id);

    GLint compile_status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &compile_status);
    if (compile_status == GL_FALSE) {
        // Check for error - if so, ...
        GLchar errorbuf[512];
        glGetShaderInfoLog(id, 512, nullptr, errorbuf);
        // std::cerr << std::string(errorbuf) << "\n";
        // TODO - use log
    }

    return id;

}

void Shader::link(int vert, int frag) {
    glAttachShader(this->program_id, vert);
    glAttachShader(this->program_id, frag);
    glLinkProgram (this->program_id);
    // We no longer need these sub-shaders.
    glDetachShader(this->program_id, vert);
    glDetachShader(this->program_id, frag);
}

void Shader::bind() {
    glUseProgram(this->program_id);
}

void Shader::unbind() {
    glUseProgram(0);
}

void Shader::destroy() {
    if (this->program_id) {
        glDeleteShader(this->program_id);
        this->program_id = 0;
    }
}

Shader::~Shader() {
    this->unbind();
    glDeleteShader(this->program_id);
}

std::unique_ptr<Shader> GAME_SHADER;

void load_all_shaders() {
    GAME_SHADER = std::make_unique<Shader>(
        "src/gl/shad/basic_vert.glsl", "src/gl/shad/basic_frag.glsl"
    );
    // More shaders in the future?
}

void unload_all_shaders() {
    GAME_SHADER->destroy();
}

}
