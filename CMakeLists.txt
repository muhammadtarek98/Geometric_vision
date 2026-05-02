cmake_minimum_required(VERSION 4.1)
project(GeometricVision LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
enable_testing()
add_subdirectory(Core)
add_subdirectory(Vector)
add_subdirectory(Point)
add_subdirectory(Plane)
add_subdirectory(Line)
add_subdirectory(Intersection)
add_subdirectory(Angle)
add_subdirectory(GeometricUtils)
add_subdirectory(Distance)
add_subdirectory(DCEL)
add_subdirectory(SweepLine)
add_subdirectory(ConvexHull)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
    Core
    Angle
    Vector
    Point
    Line
    Plane
    Intersection
    GeometricUtils
    Distance
    DCEL
    SweepLine
    GTest::gtest_main)
find_program(VALGRIND_PROGRAM valgrind)
if(VALGRIND_PROGRAM)
    add_test(NAME ValgrindMemCheck COMMAND ${VALGRIND_PROGRAM} --leak-check=full --error-exitcode=1 $<TARGET_FILE:${PROJECT_NAME}>)
endif()
