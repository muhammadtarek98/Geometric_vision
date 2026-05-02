add_library(SweepLine INTERFACE)
add_subdirectory(MonotonePolygonPartitioning)
add_subdirectory(LineSegmentIntersection)
target_link_libraries(SweepLine INTERFACE
        MonotonePolygonPartitioning
        LineSegmentIntersection)
target_include_directories(SweepLine INTERFACE
        MonotonePolygonPartitioning/header
        LineSegmentIntersection/header)
