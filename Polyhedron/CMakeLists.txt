file(GLOB SRC "./source/*.cpp")
file(GLOB INCLUDE_DIR "./header/*.hpp")
add_library(PolyHedron STATIC ${SRC})
target_include_directories(PolyHedron PUBLIC ./header)
target_link_libraries(PolyHedron PUBLIC Vector Angle Plane Point DCEL Core DCEL )
# Minor change to trigger recompile
