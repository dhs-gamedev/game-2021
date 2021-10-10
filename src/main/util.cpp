#include <iostream>
#include <main/util.hpp>

int log(std::string message, util::Severity severity) {
    std::cout << util::SeverityText[severity] << message << std::endl;
	return 0;
}
