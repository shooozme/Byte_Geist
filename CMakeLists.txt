cmake_minimum_required(VERSION 3.5)
project(ByteGeist)

message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "CMake system name: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMake system processor: ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "CMake source directory: ${CMAKE_SOURCE_DIR}")

file(GLOB SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*)
foreach(DIR ${SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${DIR} AND EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/CMakeLists.txt)
        message(STATUS "Adding subdirectory: ${DIR}")
        add_subdirectory(${DIR})
    endif()
endforeach(DIR)

add_executable(ByteGeist src/interpreter.c)
target_link_libraries(ByteGeist util commands parser)
