#include <fstream>
#include <iostream>
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

} // namespace util
