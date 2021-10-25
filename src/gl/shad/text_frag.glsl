#version 410 core

out vec4 fragColor;
in vec2 texCoord;
uniform sampler2D tex;

void main() {
    ~?~?~?~? // syntax error
    vec4 inter = texture(tex, texCoord);
    fragColor = vec4(inter.r, inter.r, inter.r, 1.0);
    if (fragColor.r < 0.05) discard;
}
