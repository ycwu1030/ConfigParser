#ifndef __CONVERSION__
#define __CONVERSION__

#include <iostream>
#include <sstream>
#include <string>

namespace config_parser {
void exitWithError(const std::string &err_msg);

class Convert {
public:
    template <typename T>
    static std::string T_to_string(T const &val) {
        std::ostringstream ostr;
        ostr << val;
        return ostr.str();
    }

    template <typename T>
    static T string_to_T(std::string const &val) {
        std::istringstream istr(val);
        T returnVal;
        if (!(istr >> returnVal)) {
            exitWithError("ConfigParser: Not a valid " + static_cast<std::string> typeid(T).name() + " received!\n");
        }
        return returnVal;
    }

    static std::string string_to_T(std::string const &val) { return val; }
};
};  // namespace config_parser

#endif  //__CONVERSION__
