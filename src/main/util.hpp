#include <map>
#include <string>

#pragma once

namespace util {

enum Severity {
    NORMAL,
    DEBUG,
    ERROR,
    WARNING,
    FATAL,
};

/**
 * Errors out if this fails.
 */
void init_log_system();

void cleanup_log_system();

int log(std::string message, util::Severity severity);

enum ExitValue {
    NO_EXIT,
    EXIT_IF_ERROR,
};

// Check for GL errors and log if any have occurred. Exit if val is set and an
// error is found. Returns nonzero if error, zero if good.
int check_for_gl_error(ExitValue val);

} // namespace util
