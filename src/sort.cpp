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
        const std::string type = "name";

        if(!sutils::check_exists(path)) return 1;
        if(!sutils::check_type(type, df)) return 1;

        bool is_founded = false;
        for(const auto &file : files::directory_iterator(files::current_path())) {
            std::string file_name = file.path().filename().string();  
            std::string short_file_name = file_name;
            
            auto pos = short_file_name.find_last_of('.');
            if(pos != std::string::npos) short_file_name.erase(pos);

            if(!files::is_regular_file(file.path()) || files::exists(path / file_name)) continue;
            if(short_file_name.find(df) == std::string::npos) continue;

            is_founded = true;
            files::rename(file.path(), path / file_name);
        }
        if(!sutils::check_is_founded(is_founded, df, type)) return 1;
        return 0;
    }
    int ext_sort(std::string path_str, std::string df_str) {
        const files::path path{path_str}; 
        const std::string &df = df_str;
        const std::string type = "ext";

        if(!sutils::check_exists(path)) return 1;
        if(!sutils::check_type(type, df)) return 1;

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
        if(!sutils::check_is_founded(is_founded, df, type)) return 1;
        return 0;
    }
    int date_sort(std::string path_str, std::string df_str) {
        const files::path path{path_str}; 
        const std::string &df = df_str;
        const std::string type = "date";

        if(!sutils::check_exists(path)) return 1;
        if(!sutils::check_type(type, df)) return 1;

        bool is_founded = false;
        for(const auto &file : files::directory_iterator(files::current_path())) {
            std::string file_name = file.path().filename().string();
            std::string file_path = file.path().string();
            std::string file_date = sutils::get_file_date(file_path);

            if(!files::is_regular_file(file.path()) || files::exists(path / file_name)) continue;
            if(file_date != df) continue;

            is_founded = true;
            files::rename(file.path(), path / file_name);
        }   
        if(!sutils::check_is_founded(is_founded, df, type)) return 1;
        return 0;
    }
}