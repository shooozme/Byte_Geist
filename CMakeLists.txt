cmake_minimum_required(VERSION 3.5)
project(ByteGeist)

message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "CMake system name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMake system processor: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMake source directory: ${CMAKE_SOURCE_DIR}")

set(SOURCE_DIRS
    src/commands
    src/parser
    src/util
)

foreach(DIR ${SOURCE_DIRS})
    add_subdirectory(${DIR})
endforeach(DIR)

add_executable(ByteGeist src/interpreter.c)
target_link_libraries(ByteGeist commands parser util)