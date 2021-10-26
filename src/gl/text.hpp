/**
 * Text rendering with TrueType.
 */

#pragma once

#include <string>

#include <gl/stb_truetype.h>

namespace gl {

typedef unsigned char * DataBuffer;

class Font {

private:
    DataBuffer fontbuf;
    stbtt_fontinfo info;

public:
    // Get a font's data from a file path containing the font.
     Font(const std::string& font_path);
    ~Font();

friend class TextLabel;

};

class TextLabel {
    
private:
    DataBuffer bitmap;
    unsigned id;

public:
    // Initialize the text label with the given text and font.
    // EX: TextLabel("Hello World", Font("font.ttf"));
     TextLabel(const std::string& text, const Font& font);
     TextLabel() = delete;
    ~TextLabel();

    // Draw at the specified position. This should be replaced later.
    // NOTE: x and y are LOWER LEFT!
    // Also, the text is not scaled to fit the box. Whatever.
    void draw(float x, float y, float xs, float ys);

};

}
