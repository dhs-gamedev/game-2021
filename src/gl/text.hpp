/**
 * Text rendering with TrueType.
 */

#pragma once

#include <string>

namespace gl {

class Font {

private:
    // Fonts are represented as a texture and bits and pieces are drawn.
    unsigned texID;

public:
     Font(const std::string& font_path, int font_size);
    ~Font();

    void draw(const std::string& text, float x, float y, float scale);

};

}
