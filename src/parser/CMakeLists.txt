#[-- Make sure to add all *working* source files here. --]

set(SOURCE_FILES parser.c token.c)
set(HEADER_FILES parser.h token.h)

add_library(parser ${SOURCE_FILES} ${HEADER_FILES})