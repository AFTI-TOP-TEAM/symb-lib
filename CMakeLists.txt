cmake_minimum_required(VERSION 2.8)

project(symb-lib )
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set ( CMAKE_CXX_FLAGS "-Werror")
include_directories(src/ src/symblib/)

file(GLOB SOURCES
    src/symblib/manager/*.cpp
    src/symblib/node/*.cpp
    src/symblib/node/AST/*.cpp
    src/symblib/processor/*.cpp
    src/symblib/classlib/*.cpp
)

file(GLOB HEADERS
    src/symblib/manager/*.h
    src/symblib/node/*.h
    src/symblib/node/AST/*.h
    src/symblib/processor/*.h
    src/symblib/classlib/*.h
    src/symblib/Types.h
    src/symblib/Nodes.h
)

add_subdirectory(src/symblib/parser)
add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})
add_subdirectory(test)

add_executable(run src/exe/main.cpp)
#add_executable(example src/exe/example.cpp)
#target_link_libraries(example ${PROJECT_NAME} ${PARSER_LIB_NAME})
target_link_libraries(run ${PROJECT_NAME} ${PARSER_LIB_NAME})
