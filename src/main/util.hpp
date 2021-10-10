#include <map>
#include <string>

namespace util {

enum Severity {
    NORMAL,
    DEBUG,
    ERROR,
    WARNING,
    FATAL,
};

const char *SeverityText[] = {
    "", "Normal: ", "Debug: ", "Error: ", "Warning: ", "Fatal: "};

int log(std::string message, util::Severity severity);

} // namespace util
