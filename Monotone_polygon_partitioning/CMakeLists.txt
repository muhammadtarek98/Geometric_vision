file(GLOB SRC "./source/*.cpp")
file(GLOB INCLUDE "./header/*.hpp")
add_library(Monotone_partition STATIC ${SRC})
target_include_directories(Monotone_partition PUBLIC ./header)
target_link_libraries(Monotone_partition PUBLIC Core Vector
        Geometric_utils DCEL Point angle)
