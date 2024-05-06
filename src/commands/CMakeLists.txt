#[-- Make sure to add all *working* source files here. --]

set(SOURCE_FILES commands.c)
set(HEADER_FILES commands.h)

add_library(commands ${SOURCE_FILES} ${HEADER_FILES})