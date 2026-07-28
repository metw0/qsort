#include <iostream>
#include <CLI/CLI.hpp>
#include <string>
#include <unordered_map>
#include <functional>
#include <filesystem>
#include "header.h"

int main(int argc, char **argv) {
    CLI::App qsort{"qsort - simple sorting programm for Linux"};

    std::string where_option;
    qsort.add_option("-w, --where", where_option, "directory to sort")->required();
    std::string type_option;
    qsort.add_option("-t, --type", type_option, "types to sort (date, ext or name)")->required();
    std::string df_option; // d = distinctive feature
    qsort.add_option("-d, --df", df_option, "distinctive feature to sort (like date or file extension)")->required();

    CLI11_PARSE(qsort, argc, argv);

    if(!files::is_directory(files::path(where_option))) {
        std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                  << "path is not a directory" << std::endl;
        std::exit(1); 
    }

    std::unordered_map<std::string, std::function<int()>> actions = {
        {"name", [where_option, df_option]() -> int {
            return sort::name_sort(where_option, df_option);
        }},
        {"ext", [where_option, df_option]() -> int {
            return sort::ext_sort(where_option, df_option);
        }},
        {"date", [where_option, df_option]() -> int {
            return sort::date_sort(where_option, df_option);
        }}
    };

    auto it = actions.find(type_option);
    if(it != actions.end()) {
        if(it->second() != 0) std::exit(1);
        std::cout << "success" << std::endl;
    } else {
        std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                  << "unknown type, use --help" << std::endl;
        std::exit(1);
    }

    std::exit(0);
}