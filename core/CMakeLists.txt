file(GLOB SRC "./source/*.cpp")
file(GLOB INCLUDE "./header/*.hpp")
add_library(Core STATIC ${SRC})
target_include_directories(Core PUBLIC ./header )