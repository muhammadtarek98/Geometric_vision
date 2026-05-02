add_library(ConvexHull INTERFACE)
add_subdirectory(ConvexHull2D)
add_subdirectory(ConvexHull3D)
target_link_libraries(ConvexHull INTERFACE
        ConvexHull2D
        ConvexHull3D)
target_include_directories(ConvexHull INTERFACE
        ConvexHull2D/header
        ConvexHull3D/header)
