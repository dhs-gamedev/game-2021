#include "text.hpp"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gl/glad.h>
#include <gl/mesh.hpp>
#include <main/util.hpp>

namespace gl {

Font::Font(const std::string& font_path) {

    FILE          * file = fopen(font_path.c_str(), "r");
    if (!file) {
        util::log("Couldn't open font path", util::Severity::FATAL);
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    rewind(file);
    // Casting malloc type. Laugh.
    fontbuf = (unsigned char *) malloc(size);

    // Read file into buffer
    fread(fontbuf, 1, size, file);
    fclose(file);

    if (!stbtt_InitFont(&info, fontbuf, 0)) {
        util::log("Couldn't initialize font", util::Severity::FATAL);
    }

}

Font::~Font() {
    free(this->fontbuf);
}

TextLabel::TextLabel(const std::string& text_s, const Font& font) {

    // NOTE: this function is stolen from here:
    // https://github.com/justinmeiners/stb-truetype-example/blob/master/main.c
    // THANK YOU!

    int b_w = 512; /* bitmap width */
    int b_h = 128; /* bitmap height */
    int l_h = 64; /* line height */

    /* create a bitmap for the phrase */
    bitmap = (unsigned char *) calloc(b_w * b_h, sizeof(unsigned char));
    
    /* calculate font scaling */
    float scale = stbtt_ScaleForPixelHeight(&(font.info), l_h);
    
    int x = 0;
       
    int ascent, descent, lineGap;
    stbtt_GetFontVMetrics(&(font.info), &ascent, &descent, &lineGap);
    
    ascent = roundf(ascent * scale);
    descent = roundf(descent * scale);

    auto text = text_s.c_str();
    
    for (int i = 0; i < strlen(text); i++) {
        /* how wide is this character */
        int ax;
	    int lsb;
        stbtt_GetCodepointHMetrics(&(font.info), text[i], &ax, &lsb);
        /* (Note that each Codepoint call has an alternative Glyph version which caches the work required to lookup the character word[i].) */

        /* get bounding box for character (may be offset to account for chars that dip above or below the line */
        int c_x1, c_y1, c_x2, c_y2;
        stbtt_GetCodepointBitmapBox(&(font.info), text[i], scale, scale, &c_x1, &c_y1, &c_x2, &c_y2);
        
        /* compute y (different characters have different heights */
        int y = ascent + c_y1;
        
        /* render character (stride and offset is important here) */
        int byteOffset = x + roundf(lsb * scale) + (y * b_w);
        stbtt_MakeCodepointBitmap(&(font.info), bitmap + byteOffset, c_x2 - c_x1, c_y2 - c_y1, b_w, scale, scale, text[i]);

        /* advance x */
        x += roundf(ax * scale);
        
        /* add kerning */
        int kern;
        kern = stbtt_GetCodepointKernAdvance(&(font.info), text[i], text[i + 1]);
        x += roundf(kern * scale);

    }

    this->id = load(bitmap, b_w, b_h, GL_RED);

}

TextLabel::~TextLabel() {
    free(this->bitmap);
}

void TextLabel::draw(float x, float y, float w, float h) {

    // TODO use inheritance

    glBindTexture(GL_TEXTURE_2D, this->id);
    Mesh mesh {
        std::vector<float>{
            x, y + h, x, y, x + w, y, x + w, y + h
        },
        std::vector<int>{0, 1, 3, 3, 1, 2},
        std::vector<float>{0.f, 0.f, 0.f, 1.f, 1.f, 1.f, 1.f, 0.f}
    };
    mesh.draw();

}

}
