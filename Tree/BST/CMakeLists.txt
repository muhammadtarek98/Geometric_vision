file(GLOB SRC "./source/*.cpp")
file(GLOB INCLUDE "./header/*.hpp")
add_library(BST STATIC ${SRC})
target_include_directories(BST PUBLIC ./header)