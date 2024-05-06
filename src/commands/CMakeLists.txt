file(GLOB SOURCES "*.c" "*.h")
add_library(commands STATIC ${SOURCES})