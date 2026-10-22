add_library(Tree INTERFACE)
add_subdirectory(BST)
add_subdirectory(One_D_range_query)
add_subdirectory(KDTree)
target_include_directories(Tree INTERFACE BST/header
        KDTree/header One_D_range_query/header)
target_link_libraries(Tree INTERFACE BST KDTree O
        neDimRangeQuery)
