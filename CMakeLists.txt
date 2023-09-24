# Minimum required version of Cmake needed to run the build script
cmake_minimum_required(VERSION 3.9.0)

# Name of the project
project(elliptic_rings)

# C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create an executable with main.cpp as its entry point.
add_executable(elliptic_rings
    src/main.cpp
    src/er_math.cpp
    src/er_array.cpp
    src/er_ring.cpp
)

target_include_directories(elliptic_rings PRIVATE
    ${CMAKE_SOURCE_DIR}/include
) # Not entirely sure what PRIVATE means
