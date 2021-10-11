#version 410 core

out vec4 fragColor;
in vec2 texCoord;
uniform sampler2D tex;

void main() {
    fragColor = texture(tex, texCoord);
    if (fragColor.a < 0.05) discard;
}
