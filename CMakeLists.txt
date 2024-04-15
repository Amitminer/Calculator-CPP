cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 11)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(calculator ${SOURCES})
