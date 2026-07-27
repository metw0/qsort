#include <iostream>
#include <string>
#include <filesystem>
#include "header.h"

/* 
df is distinctive feature from main.cpp
files is namespace of std::filesystem */
namespace sort {  
    int name_sort(std::string path_str, std::string df_str) {
        const files::path path{path_str}; 
        const std::string &df = df_str;

        if(!sutils::check_exists(path)) return 1;
        if(sutils::check_type(df) != "name") {
            std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                      << "wrong type for " << df << " df" << std::endl;
            return 1;
        }

        bool is_founded = false;
        for(const auto &file : files::directory_iterator(files::current_path())) {
            std::string file_name = file.path().filename().string();  
            
            size_t pos = file_name.find_last_of('.');
            file_name.erase(pos);

            if(!files::is_regular_file(file.path()) || files::exists(path / file_name)) continue;
            if(file_name.find(df) == std::string::npos) continue;

            is_founded = true;
            files::rename(file.path(), path / file_name);
        }
        if(!sutils::check_is_founded(is_founded, df)) return 1;
        return 0;
    }
    int ext_sort(std::string path_str, std::string df_str) {
        const files::path path{path_str}; 
        const std::string &df = df_str;

        if(!sutils::check_exists(path)) return 1;
        if(sutils::check_type(df) != "ext") {
            std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                      << "wrong type for " << df << " df" << std::endl;
            return 1;
        }

        bool is_founded = false;
        for(const auto &file : files::directory_iterator(files::current_path())) {
            std::string file_name = file.path().filename().string();

            std::string file_ext = file_name;
            file_ext.erase(0, file_ext.find_last_of('.'));   

            if(!files::is_regular_file(file.path()) || files::exists(path / file_name)) continue;
            if(file_ext != df) continue;

            is_founded = true;
            files::rename(file.path(), path / file_name);
        }
        if(!sutils::check_is_founded(is_founded, df)) return 1;
        return 0;
    }
    int date_sort() {
        /* some code */
    }
}