#include "Conversion.h"

namespace config_parser {
void exitWithError(const std::string &err_msg) {
    std::cout << err_msg;
    std::cout << "Press Any Key to Exit..." << std::endl;
    std::cin.ignore();
    std::cin.get();

    exit(EXIT_FAILURE);
}
template <>
std::string Convert::string_to_T<std::string>(std::string const &val) {
    return val;
}
}  // namespace config_parser
