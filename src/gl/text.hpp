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
     Font(const std::string& font_path, int font_size);
    ~Font();

    void draw(const std::string& text, float x, float y, float scale);

friend class TextLabel;

};

class TextLabel {
    
private:
    DataBuffer bitmap;
    unsigned id;

public:
     TextLabel(const std::string& text, const Font& font);
    ~TextLabel();

    void draw(float x, float y, float xs, float ys);

};

}
