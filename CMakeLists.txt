cmake_minimum_required(VERSION 3.10)

# set the project name
project(Daletos VERSION 1.0.0)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(main PRIVATE fmt::fmt)

find_package(EASTL CONFIG REQUIRED)
target_link_libraries(main PRIVATE EASTL)

# Library inclusion
# add_library
#     (
#     <library_name> <SPECIFIERS>
#     lib.hpp
#     lib.cpp
#     )

# add the executable
add_executable(Daletos ./main.cxx)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)






# <SPECIFIER>      STATIC || SHARED || MODULE
# <library_name>   "Name Of the library"
