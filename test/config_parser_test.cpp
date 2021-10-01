#include "ConfigParser.h"

using namespace config_parser;

int main(int argc, char const *argv[]) {
    ConfigParser conf(argv[1]);
    conf.Print_Config();
    return 0;
}
