cmake_minimum_required(VERSION 3.15)
project(GradesAnalyserV2)

# C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h")

# Executable target
add_executable(GradesAnalyserV2 ${SOURCES} ${HEADERS})
