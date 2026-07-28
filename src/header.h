#pragma once
namespace ansi {
    constexpr const char *BOLD_RED = "\033[1;31m";
    constexpr const char *BOLD_YELLOW = "\033[1;33m";
    constexpr const char *RESET = "\033[0m";
}
namespace files = std::filesystem;
namespace sutils {
    bool check_exists(const files::path &path);
    bool check_is_founded(bool is_founded, const std::string &df);
    bool check_type(const std::string type, const std::string &df);
}
namespace sort {
    int name_sort(std::string path_str, std::string df_str);
    int ext_sort(std::string path_str, std::string df_str);
}
