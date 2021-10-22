#include "text.hpp"

#include <stdio.h>
#include <stdlib.h>

#include <gl/glad.h>
#include <gl/stb_truetype.h>
#include <main/util.hpp>

namespace gl {

Font::Font(const std::string& font_path, int font_size) {

    unsigned char * fontbuf;
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

    stbtt_fontinfo font;
    if (!stbtt_InitFont(&font, fontbuf, 0)) {
        util::log("Couldn't initialize font", util::Severity::FATAL);
    }

}

}
