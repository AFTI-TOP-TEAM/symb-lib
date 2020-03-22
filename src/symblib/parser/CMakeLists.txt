set(PARSER_LIB_NAME parser)

file(GLOB RECPARSER_HEADER
    parser/*.h
    Location.h
    lexer/*.h)
file(GLOB RECPARSER_SOURSES
    parser/*.cpp
    lexer/*.cpp)

add_library(${PARSER_LIB_NAME} SHARED ${RECPARSER_HEADER} ${RECPARSER_SOURSES})
