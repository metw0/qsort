#pragma once
namespace ansi {
    constexpr const char *BOLD_RED = "\033[1;31m";
    constexpr const char *YELLOW = "\033[33m";
    constexpr const char *RESET = "\033[0m";
}
namespace files = std::filesystem;
namespace sort {
    int name_sort(std::string path_str, std::string df_str);
}
