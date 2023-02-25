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
set(EXECUTABLE_NAME convert)

find_package(fmt REQUIRED)

add_library(${LIBRARY_NAME} OBJECT
        ${PROJECT_SOURCE_DIR}/lib/hello.cpp)

target_include_directories(${LIBRARY_NAME}
        PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${LIBRARY_NAME}
        PRIVATE fmt::fmt)

add_executable(${EXECUTABLE_NAME} ${PROJECT_SOURCE_DIR}/src/convert.cpp)
target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})
