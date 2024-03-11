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

add_library(str string/string_.h string/string_.c
        # string/tasks/digitToStartTransform.h
        # string/tasks/reverseWords.h
        # string/tasks/replaceDigitsBySpaces.h
        # ...
        # < файл с решением задачи >
        # ...
        # string/tasks/hasPairOfWordsWithEqualLetterSet.h
        # string/tasks/printWordsNonEqualLastWord.h
)

# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(2ndsemestr str)

add_subdirectory(libs)
target_link_libraries(2ndsemestr algorithms)
target_link_libraries(2ndsemestr data_structures)