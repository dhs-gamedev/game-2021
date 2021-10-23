#version 410 core

layout(location=0) in vec3 inVertexCoord;
layout(location=1) in vec2 inTexCoord;

uniform float ratio; // width / height

out vec2 texCoord;

void main() {

    gl_Position = vec4(inVertexCoord, 1.0);
    texCoord = inTexCoord;

    if (ratio < 1.0) {
        gl_Position.y *= ratio;
    }
    if (ratio > 1.0) {
        gl_Position.x /= ratio;
    }

}
