file(GLOB SOURCES "*.c" "*.h")
add_library(parser STATIC ${SOURCES})
target_link_libraries(parser PRIVATE commands)