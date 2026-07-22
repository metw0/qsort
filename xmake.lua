set_project("qsort")
set_version("1.0.0")

set_languages("c++17", "c17")
add_rules("mode.debug", "mode.release")


target("qsort")
    set_kind("binary")
    add_files("src/*.cpp")
    add_includedirs("include")

    add_syslinks("pthread", "dl")
    
    add_cxxflags("-Wall", "-Wextra", "-Wpedantic", "-Wshadow", "-Wconversion", "-Weverything")

    if is_mode("debug") then
        add_cxxflags("-g3", "-O0", "-DDEBUG")
        add_ldflags("-rdynamic")
        set_symbols("debug")
    end

    if is_mode("release") then
        add_cxxflags("-O3")
        set_symbols("none")
        set_strip("all")  
    end