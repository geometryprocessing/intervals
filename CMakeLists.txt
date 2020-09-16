cmake_minimum_required(VERSION 3.1)
project (interval)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/)
set(test_sources
    ${SRC_DIR}/main.cpp
)

set (CMAKE_CXX_STANDARD 11)

## include the cmake directory
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(IntervalsDependencies)

## add the dynamic library
file(GLOB_RECURSE LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/interval_operations/src/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

## download gmp
intervals_download_gmp()
find_package(GMP REQUIRED)

INCLUDE_DIRECTORIES(
    "${GMP_INCLUDES}"
)

add_executable(unit_tests ${test_sources})
target_include_directories(unit_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/interval_operations/src/)
target_link_libraries(unit_tests PUBLIC "${LIBRARIES}")
target_link_libraries(unit_tests PUBLIC ${GMP_LIBRARIES})



add_custom_command (TARGET unit_tests
    POST_BUILD COMMAND "${CMAKE_INSTALL_NAME_TOOL}"
        "-change" "interval.dylib" "@executable_path/../interval_operations/src/interval.dylib"
    "$<TARGET_FILE:unit_tests>" VERBATIM)
