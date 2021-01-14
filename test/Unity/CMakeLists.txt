cmake_minimum_required(VERSION 3.10)

set(INCLUDE_DIRS
	src
	extras/fixture/src
	extras/memory/src
)

add_library(unity STATIC
	src/unity.c
	extras/fixture/src/unity_fixture.c
	extras/memory/src/unity_memory.c
) 

target_compile_options(unity PRIVATE "-Wall")
target_include_directories(unity PUBLIC ${INCLUDE_DIRS})