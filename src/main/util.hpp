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

} // namespace util
