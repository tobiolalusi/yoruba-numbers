cmake_minimum_required(VERSION 3.24)

project(yoruba-numbers
        VERSION 0.0.1
        DESCRIPTION "Numbers to Words in Yorùbá converter"
        HOMEPAGE_URL https://yoruba-numbers.tobiolalusi.com
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Wformat=2 -g)

set(LIBRARY_NAME ${PROJECT_NAME})

find_package(fmt REQUIRED)

file(GLOB LIBRARY_SOURCES lib/*.cpp)

add_library(${LIBRARY_NAME} OBJECT ${LIBRARY_SOURCES})

target_include_directories(${LIBRARY_NAME}
        PUBLIC include)

target_link_libraries(${LIBRARY_NAME}
        PUBLIC fmt::fmt)

# convert executable
set(EXECUTABLE_NAME convert)
add_executable(${EXECUTABLE_NAME} src/convert.cpp)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIBRARY_NAME})

# test executable
add_subdirectory(test)
