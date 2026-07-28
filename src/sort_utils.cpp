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
    /* starts_with_dot and has_dash were created for better readability
    */
    bool check_type(const std::string type, const std::string &df) {
        bool starts_with_dot = (df[0] == '.');
        bool has_dash = (df.find('-') != std::string::npos);

        if(type == "name") return true;

        if(type == "ext") {
            if(!starts_with_dot) {
                std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                          << "ext type must start with ." << std::endl;
                return false;
            }
            if(has_dash) {
                std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                          << "ext type cannot contain -" << std::endl;
                return false;
            }
            return true;
        }
        if(type == "date") {
            if(!has_dash) {
                std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                          << "date type must contain -" << std::endl;
                return false;
            }
            if(starts_with_dot) {
                std::cerr << ansi::BOLD_RED << "error: " << ansi::RESET 
                          << "date type cannot start with ." << std::endl;
                return false;
            }
            return true;
        }
    }
}