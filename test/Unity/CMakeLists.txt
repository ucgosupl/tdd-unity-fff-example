cmake_minimum_required(VERSION 3.14)

set(UNITY_OUT_DIR ${CMAKE_SOURCE_DIR}/../Unity/out)

include(FetchContent)

FetchContent_Declare(
  Unity
  GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
  GIT_TAG        v2.5.2
  SOURCE_DIR     ${UNITY_OUT_DIR}/src
  BINARY_DIR     ${UNITY_OUT_DIR}/bin
)

set(FETCHCONTENT_BASE_DIR ${UNITY_OUT_DIR})

set(UNITY_EXTENSION_FIXTURE ON CACHE BOOL "Enable Unity Fixture Extension")
set(UNITY_EXTENSION_MEMORY  ON CACHE BOOL "Enable Unity Memory Extension")

FetchContent_GetProperties(Unity)
if (NOT Unity_POPULATED)
    FetchContent_Populate(Unity)
endif ()

add_subdirectory(${unity_SOURCE_DIR} ${unity_BINARY_DIR})
