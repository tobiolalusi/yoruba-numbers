set(TESTS_EXECUTABLE_NAME test)

file(GLOB TEST_SOURCES *.cpp)

find_package(doctest REQUIRED)

include(doctest)

add_executable(${TESTS_EXECUTABLE_NAME} ${TEST_SOURCES})
target_link_libraries(${TESTS_EXECUTABLE_NAME}
        PRIVATE doctest::doctest
        PRIVATE ${LIBRARY_NAME})
