cmake_minimum_required(VERSION 3.10)

project(tdd_cyclic_buffer C)

#add_subdirectory(../Unity unity)

include(FetchContent)
FetchContent_Declare(
  Unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.5.2
)

set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "Enable Unity Fixture Extension")
set(UNITY_EXTENSION_MEMORY  ON CACHE BOOL "Enable Unity Memory Extension")
FetchContent_MakeAvailable(Unity)

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
