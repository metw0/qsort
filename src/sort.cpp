#include <iostream>
#include <string>
#include <filesystem>
#include "header.h"

/* 
df is distinctive feature from main.cpp
files is namespace of std::filesystem
*/
namespace sort {
    int name_sort(std::string path_str, std::string df_str) {
        const files::path path{path_str}; 
        if(!files::exists(path) && !files::create_directory(path)) {
            std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET << "directory does not exist and unable to create it, unknown error";
            return 1;
        }

        const std::string &df = df_str;
        for(const auto &file : files::directory_iterator(files::current_path())) {
            std::string file_name = file.path().filename().string();   

            if(!files::is_regular_file(file.path()) || files::exists(path / file_name)) continue;
            if(file_name.find(df) == std::string::npos) continue;

            files::rename(file.path(), path / file_name);
        }
        return 0;
    }

    int ext_sort() {
        /* some code */
    }

    int date_sort() {
        /* some code */
    }
}