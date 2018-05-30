cmake_minimum_required(VERSION 3.10)
project(cmake_build_debug)

set(CMAKE_CXX_STANDARD 11)

add_executable(cmake_build_debug
        cmake_install.cmake
        CMakeCache.txt
        Makefile
        Part2.cbp
        Part2.exe
        parte.txt)
