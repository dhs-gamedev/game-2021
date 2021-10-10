/*
 * Header-only - GL contexts and whatnot.
 */

#pragma once

#define GL_SILENCE_DEPRECATION // macOS says it's deprecated. WHY?!

#include <gl/glad.h>

// OpenGL 4.1
#define V_MAJ 4
#define V_MIN 1

#define GL_INIT_CONTEXT() do { \
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, V_MAJ); \
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, V_MIN); \
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); \
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); \
} while (0)
