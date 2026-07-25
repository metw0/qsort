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
    qsort.add_option("-w, --where", where_option, "directory to sort");
    std::string type_option;
    qsort.add_option("-t, --type", type_option, "types to sort (date, ext or name)");
    std::string df_option; // d = distinctive feature
    qsort.add_option("-d, --df", df_option, "distinctive feature to sort (like date or file extension)");

    CLI11_PARSE(qsort, argc, argv);

    if(!files::is_directory(files::path(where_option))) {
        std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                  << "path is not a directory, unknown path" << std::endl;
        return 0; // return 1 gonna return 'unknown error', so it's 0 for correct returning
    }
    if(df_option.empty()) {
        std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                  << "distinctive feature is empty, unknown distinctive feature";
        return 0; // return 1 gonna return 'unknown error', so it's 0 for correct returning
    } 

    std::unordered_map<std::string, std::function<void()>> actions = {
        {"name", [where_option, df_option]() {
            if(sort::name_sort(where_option, df_option) == 1) return 0; 
            // return 1 gonna return 'unknown error', so it's 0 for correct returning
        }},
        {"ext", []() {/* some code */}},
        {"date", []() {/* some code */}}
    };

    auto it = actions.find(type_option);
    if(it != actions.end()) {
        it->second();
    } else {
        std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                  << "types date, ext or name is acceptable, unknown type" << std::endl;
        return 0; // return 1 gonna return 'unknown error', so it's 0 for correct returning
    }

    return 0;
}