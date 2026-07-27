#include <iostream>
#include <string>
#include <filesystem>
#include "header.h"

/* 
sutils is short for sort_utils 
checks for sort.cpp */
namespace sutils {
    bool check_exists(const files::path &path) {
        if(!files::exists(path) && !files::create_directory(path)) {
            std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                      << "directory does not exist and unable to create it" << std::endl;
            return false;
        }
        return true;
    }
    bool check_is_founded(bool is_founded, const std::string &df) {
        if(is_founded) return true;
        if(df[0] != '.') {
            std::cerr << ansi::BOLD_YELLOW << "warning: " << ansi::RESET 
                      << "there are no files that include " << df << " in name" << std::endl;
            return false;
        } else {
            std::cerr << ansi::BOLD_YELLOW << "warning: " << ansi::RESET 
                      << "there are no files with ext " << df << std::endl;
            return false;
        }
    }
    std::string check_type(const std::string &df) {
        if(df[0] == '.') return "ext";
        else if(df.find("/")) return "date";
        return "name";
    }
}