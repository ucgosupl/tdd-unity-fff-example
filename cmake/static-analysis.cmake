cmake_minimum_required(VERSION 3.14)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CPPCHECK_CONFIG
	"--enable=all"
	"--inconclusive"
	"--force" 
	"--inline-suppr"
	"--output-file=cppcheck.out"
)

set(CLANG_TIDY_CONFIG
	"-checks=-*,cert-*,clang-analyzer-*,performance-*,portability-*,readability-*,bugprone-*,misc-*"
	"--export-fixes=clang-tidy.out"
)

find_program(CMAKE_C_CPPCHECK NAMES cppcheck)
if (CMAKE_C_CPPCHECK)
    list(APPEND CMAKE_C_CPPCHECK ${CPPCHECK_CONFIG})
endif()

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (CMAKE_CXX_CPPCHECK)
    list(APPEND CMAKE_CXX_CPPCHECK ${CPPCHECK_CONFIG})
endif()

find_program(CMAKE_C_CLANG_TIDY NAMES clang-tidy)
if (CMAKE_C_CLANG_TIDY)
    list(APPEND CMAKE_C_CLANG_TIDY ${CLANG_TIDY_CONFIG})
endif()

find_program(CMAKE_CXX_CLANG_TIDY NAMES clang-tidy)
if (CMAKE_CXX_CLANG_TIDY)
    list(APPEND CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_CONFIG})
endif()