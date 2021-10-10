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

int log(std::string message, util::Severity severity);

} // namespace util
