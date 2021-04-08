cmake_minimum_required(VERSION 3.14)

project(tdd_cyclic_buffer C)

option(STATIC_ANALYSIS "Build for static analysis" OFF)

if (STATIC_ANALYSIS)
include(../../cmake/static-analysis.cmake)
endif()

add_subdirectory(../Unity unity)

set(INCLUDE_DIRS
	../../src
)

set(TEST_INCLUDE_DIRS
	.
)

set(SRCS
	../../src/cyclic_buffer/cyclic_buffer.c
)

set(TEST_SRCS
	cyclic_buffer_main.c
	cyclic_buffer_runner.c
	cyclic_buffer_test.c
)

set(GLOBAL_DEFINES

)

add_executable(${CMAKE_PROJECT_NAME} ${SRCS} ${TEST_SRCS})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE ${GLOBAL_DEFINES})
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra)
target_link_libraries(${CMAKE_PROJECT_NAME} unity)

enable_testing()
add_test(tests ${CMAKE_PROJECT_NAME})
