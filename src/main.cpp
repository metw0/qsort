#include <iostream>
#include <CLI/CLI.hpp>
#include <string>
#include <unordered_map>
#include <functional>
#include "header.h"

int main(int argc, char **argv) {
    CLI::App qsort{"demo"};

    std::string where_option;
    qsort.add_option("-w, --where", where_option, "");
    std::string type_option;
    qsort.add_option("-t, --type", type_option, "");

    CLI11_PARSE(qsort, argc, argv);

    if(where_option.find("/") == std::string::npos) {
        std::cout << ansi::BOLD_RED << "error: " << ansi::RESET << "/correct/path/ is acceptable, unknown path" << std::endl;
        return 0; // return 1 gonna return 'unknown error', so it's 0 for correct returning
    }

    std::unordered_map<std::string, std::function<void()>> actions = {
        {"date", []() {/* some code */}},
        {"ext", []() {/* some code */}},
        {"name", []() {/* some code */}}
    };

    auto it = actions.find(type_option);
    if(it != actions.end()) {
        it->second();
    } else {
        std::cout << ansi::BOLD_RED << "error: " << ansi::RESET << "types date, ext or name is acceptable, unknown type" << std::endl;
        return 0; // return 1 gonna return 'unknown error', so it's 0 for correct returning
    }

    return 0;
}