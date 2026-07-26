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
        if(!is_founded) {
            std::cerr << ansi::BOLD_YELLOW << "warning: " << ansi::RESET 
                      << "there are no files that include " << df << std::endl;
            return false;
        }
        return true;
    }
}