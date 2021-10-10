#include <iostream>
#include <main/util.hpp>

namespace util {

const char *severity_text[] = {
    "Normal: ", "Debug: ", "Error: ", "Warning: ", "Fatal: "};

int log(std::string message, util::Severity severity) {
    std::cout << util::severity_text[severity] << message << std::endl;
	return 0;
}

}
