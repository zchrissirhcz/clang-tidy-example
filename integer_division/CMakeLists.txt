cmake_minimum_required(VERSION 3.20)
project(integer_division)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(clang-tidy.cmake)

add_executable(main main.cpp)
cvpkg_apply_clang_tidy(main)