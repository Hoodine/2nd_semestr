add_library(data_structures
        bitset/bitset.c
        vector/vector.h
        vector/vector.c
        vector/vectorVoid.c
        vector/vectorVoid.h
        matrix/matrix.c
        matrix/matrix.h
)

target_link_libraries(data_structures algorithms)