#version 410 core

out vec4 fragColor;
in vec2 texCoord;
uniform sampler2D tex;

void main() {
    vec4 inter = texture(tex, texCoord);
    if (inter.r < 0.05) discard;
    fragColor = vec4(0.0, 0.0, 0.0, 1.0);
}
