cmake_minimum_required(VERSION 3.26)
project(2ndsemestr C)

set(CMAKE_C_STANDARD 11)

add_executable(2ndsemestr main.c
        libs/algorithms/array/array.c
        libs/algorithms/array/array.h
        libs/algorithms/algorithm.c
        libs/algorithms/algorithm.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        libs/algorithms/array/array.c
)

add_subdirectory(libs)
target_link_libraries(2ndsemestr algorithms)
target_link_libraries(2ndsemestr data_structures)