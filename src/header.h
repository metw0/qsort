#pragma once
namespace ansi {
    constexpr const char *BOLD_RED = "\033[1;31m";
    constexpr const char *BOLD_YELLOW = "\033[1;33m";
    constexpr const char *RESET = "\033[0m";
}
namespace files = std::filesystem;
namespace chrono = std::chrono;
namespace sutils {
    bool check_exists(const files::path &path);
    bool check_is_founded(bool is_founded, const std::string &df, const std::string type);
    bool check_type(const std::string type, const std::string &df);
    std::string get_file_date(const files::path &path);
}
namespace sort {
    int name_sort(std::string path_str, std::string df_str);
    int ext_sort(std::string path_str, std::string df_str);
    int date_sort(std::string path_str, std::string df_str);
}
