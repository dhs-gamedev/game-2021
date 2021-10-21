#include <fstream>
#include <iostream>
#include <stdlib.h>

#include <gl/glad.h>

#include <main/util.hpp>

namespace {
    const char * log_file = "log.txt";
    // If a "log file cannot be opened" warning has already been shown
    bool log_file_warning_shown = false;
    // Whether debugs go to standard out
    bool debug_to_stdout = false;
}

namespace util {

const char *severity_text[] = {
    "Normal: ", "Debug: ", "Error: ", "Warning: ", "Fatal: "};

int log(std::string message, util::Severity severity) {
    std::ofstream out_file(log_file, std::ios::app);
    std::string msg = severity_text[severity] + message;
    if (!out_file.is_open()) {
        if (!log_file_warning_shown) {
            log_file_warning_shown = true;
            debug_to_stdout = true;
            log(
                "Cannot print to log file, printing all logs including debugs to standard out"
                , util::Severity::WARNING
            );
        }
    } else {
        out_file << msg << std::endl;
    }
    if (severity != Severity::DEBUG || debug_to_stdout)
        std::cout << msg << std::endl;
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
