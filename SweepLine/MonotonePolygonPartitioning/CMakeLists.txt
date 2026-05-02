file(GLOB SRC "./source/*.cpp")
file(GLOB INCLUDE "./header/*.hpp")
add_library(MonotonePolygonPartitioning STATIC ${SRC})
target_include_directories(MonotonePolygonPartitioning PUBLIC ./header)
target_link_libraries(MonotonePolygonPartitioning PUBLIC Core Vector
        GeometricUtils DCEL Point Angle)
