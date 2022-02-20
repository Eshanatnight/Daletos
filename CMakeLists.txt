cmake_minimum_required(VERSION 3.17)
project(Daletos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Daletos
        src/main.cpp
        src/Daletos.cpp
        src/str_manip.cpp
        src/SystemInfo.cpp
        include/Daletos.h
        include/str_manip.h
        include/SystemInfo.h
)