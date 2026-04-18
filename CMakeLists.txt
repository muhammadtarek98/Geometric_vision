cmake_minimum_required(VERSION 4.1)
project(GeometricVision LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
find_package(GTest REQUIRED)
enable_testing()
add_subdirectory(core)
add_subdirectory(vector)
add_subdirectory(point)
add_subdirectory(plane)
add_subdirectory(line)
add_subdirectory(intersection)
add_subdirectory(Angle)
add_subdirectory(geometric_utils)
add_subdirectory(distance)
add_subdirectory(DCEL)
add_subdirectory(Sweep_Line)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME}
    Core
    Angle
    Vector
    Point
    Line
    Plane
    Intersection
    Geometric_utils
    Distance
    DCEL
    Monotone_partition
    GTest::gtest_main)
find_program(VALGRIND_PROGRAM valgrind)
if(VALGRIND_PROGRAM)
    add_test(NAME ValgrindMemCheck COMMAND ${VALGRIND_PROGRAM} --leak-check=full --error-exitcode=1 $<TARGET_FILE:${PROJECT_NAME}>)
endif()
