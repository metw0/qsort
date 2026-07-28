#include <iostream>
#include <string>
#include <filesystem>
#include "header.h"

/* 
sutils is short for sort_utils 
chrono is namespace for std::chrono
files is namespace for std::filesystem
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
    bool check_is_founded(bool is_founded, const std::string &df, const std::string type) {
        if(is_founded) return true;
        if(type == "name") {
            std::cerr << ansi::BOLD_YELLOW << "warning: " << ansi::RESET 
                      << "there are no files that include " << df << " in name" << std::endl;
            return false;
        } 
        if(type == "ext") {
            std::cerr << ansi::BOLD_YELLOW << "warning: " << ansi::RESET 
                      << "there are no files with ext " << df << std::endl;
            return false;
        }
        if(type == "date") {
            std::cerr << ansi::BOLD_YELLOW << "warning: " << ansi::RESET 
                      << "there are no files with last write date " << df << std::endl;
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
    /* path variable is path to file
    */
    std::string get_file_date(const files::path &path) {
        auto ftime = files::last_write_time(path);
        auto sctp = chrono::time_point_cast<chrono::system_clock::duration>(
            ftime - files::file_time_type::clock::now() + chrono::system_clock::now()
        );

        std::time_t tt = std::chrono::system_clock::to_time_t(sctp);
        std::tm* tm = std::localtime(&tt);

        std::ostringstream oss;
        oss << std::put_time(tm, "%Y-%m-%d");
        return oss.str();
    }
}