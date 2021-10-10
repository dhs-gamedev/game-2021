#include <iostream>
#include <main/util.hpp>

int log(std::string message, util::Severity severity) {
    std::cout << util::severity_text[severity] << message << std::endl;
	return 0;
}
