#ifndef _CONFIG_PARSER_
#define _CONFIG_PARSER_

#include <map>

#include "Conversion.h"

namespace config_parser {

class ConfigParser {
private:
    std::map<std::string, std::string> contents;
    // std::string fName;

    void Remove_Comment(std::string &line) const;

    bool Only_Whitespace_Line(const std::string &line) const;

    bool Valid_Line(const std::string &line) const;

    void Extract_Key(std::string &key, int const &pos, const std::string &line) const;

    void Extract_Value(std::string &value, int const &pos, const std::string &line) const;

    void Extract_Content(const std::string &line);

    void Parse_Line(const std::string &line, int const line_Number);

public:
    ConfigParser(const std::string &fName);
    ~ConfigParser(){};

    bool Has_Key(const std::string &key) const;

    void Parse_File(const std::string &fName);

    void Print_Config() const;

    template <typename ValueType>
    ValueType Get_Value(const std::string &key, ValueType const &defaultValue = ValueType()) const {
        if (!Has_Key(key)) {
            return defaultValue;
        }
        return Convert::string_to_T<ValueType>(contents.find(key)->second);
    }
};

};  // namespace config_parser

#endif  //_CONFIG_PARSER_
