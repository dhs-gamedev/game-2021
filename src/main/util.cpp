#include "util.hpp"

#include <fstream>
#include <iostream>
#include <stdlib.h>

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

} // namespace util
