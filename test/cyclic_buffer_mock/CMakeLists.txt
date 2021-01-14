cmake_minimum_required(VERSION 3.10)

project(tdd_cyclic_buffer_mock C)

add_subdirectory(../Unity unity)
add_subdirectory(../fff fff)

set(CMAKE_C_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(INCLUDE_DIRS
	../../src
)

set(TEST_INCLUDE_DIRS
	.
)

set(SRCS

)

set(TEST_SRCS
	cyclic_buffer_mock_main.c
	cyclic_buffer_mock_runner.c
	cyclic_buffer_mock_test.c
)

set(GLOBAL_DEFINES

)

add_executable(tdd_cyclic_buffer_mock ${SRCS} ${TEST_SRCS})

target_include_directories(tdd_cyclic_buffer_mock PRIVATE ${INCLUDE_DIRS} ${TEST_INCLUDE_DIRS})
target_compile_definitions(tdd_cyclic_buffer_mock PRIVATE ${GLOBAL_DEFINES})

target_link_libraries(tdd_cyclic_buffer_mock unity fff)

enable_testing()
add_test(tests tdd_cyclic_buffer_mock)