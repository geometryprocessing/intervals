cmake_minimum_required(VERSION 3.1)
project (intervals)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/)


if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	set(INLINE_EXPANSION_TOPLEVEL_PROJECT ON)
else()
	set(INLINE_EXPANSION_TOPLEVEL_PROJECT OFF)
endif()

set (CMAKE_CXX_STANDARD 11)


## include the cmake directory
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(IntervalsDependencies)

## include utilities
include(IntervalsUtils)

# Generate position independent code by default
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# add_library() can only be called without any source since CMake 3.11 ...
add_library(intervals src/interval.cpp src/interval.hpp)


# Public include directory for the project
target_include_directories(intervals PUBLIC ${PROJECT_BINARY_DIR}/include)


target_compile_features(intervals PUBLIC ${CXX14_FEATURES})
target_include_directories(intervals PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/interval_operations/src/)

if(INLINE_EXPANSION_TOPLEVEL_PROJECT)
	# Unit tests
	include(CTest)
	enable_testing()
	add_subdirectory(tests)
endif()
