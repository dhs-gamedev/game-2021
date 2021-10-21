#include "util.hpp"

#include <fstream>
#include <iostream>
#include <stdlib.h>

#include <main/util.hpp>

namespace {
    const char * log_file_path = "log.txt";
    std::ofstream out_file;
    // Whether debugs go to standard out (always false for now)
    bool debug_to_stdout = false;
}

namespace util {

const char *severity_text[] = {
    "Normal: ", "Debug: ", "Error: ", "Warning: ", "Fatal: "};

void init_log_system() {
    out_file = std::ofstream(log_file_path, std::ios::app);
    if (!out_file.is_open()) {
        std::cout <<
        "Unable to create log file - your permissions are amiss, and this " <<
        "indicates that other aspects of the game may be unable to work " <<
        "properly. Exiting ...\n";
        exit(-1);
    } else {
        out_file.write("Successfully created log file!", Severity::NORMAL);
    }
}

void cleanup_log_system() {
    out_file.close();
}

int log(std::string message, util::Severity severity) {
    std::string msg = severity_text[severity] + message + "\n";
    if (severity != Severity::DEBUG || debug_to_stdout)
        std::cout << msg;
    out_file << msg;
	return 0;
}

int check_for_gl_error(ExitValue val) {

    // Generic error messages
    static struct {
        GLenum error;
        const char * message;
    } error_messages[] = {
        {GL_INVALID_ENUM,                  "Invalid enum"},
        {GL_INVALID_VALUE,                 "Invalid value"},
        {GL_INVALID_OPERATION,             "Invalid operation"},
        {GL_INVALID_FRAMEBUFFER_OPERATION, "Invalid framebuffer operation"},
        {GL_OUT_OF_MEMORY,                 "Out of memory"},
        {GL_STACK_UNDERFLOW,               "Stack underflow"},
        {GL_STACK_OVERFLOW,                "Stack overflow"},
    };

    auto error_val = glGetError();
    if (error_val == GL_NO_ERROR)
        return 0;
    
    for (auto& error_pair : error_messages) {
        if (error_pair.error == error_val) {
            if (val == EXIT_IF_ERROR) {
                log(error_pair.message, util::Severity::FATAL);
                exit(-1);
            } else {
                log(error_pair.message, util::Severity::ERROR);
                return (int) error_val;
            }
        }
    }
    
}

} // namespace util
