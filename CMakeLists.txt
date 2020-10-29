cmake_minimum_required(VERSION 3.1)
project (intervals)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/)


if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	set(INTERVALS_TOPLEVEL_PROJECT ON)
else()
	set(INTERVALS_TOPLEVEL_PROJECT OFF)
endif()

set (CMAKE_CXX_STANDARD 11)
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()


## include the cmake directory
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(IntervalsDependencies)

## include utilities
include(IntervalsUtils)

# Generate position independent code by default
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# add_library() can only be called without any source since CMake 3.11 ...
add_library(intervals src/interval.cpp src/interval.hpp src/flags.hpp src/helper_functions.hpp src/Rational.h src/Timer.h src/methods.hpp)

# Public include directory for the project
target_include_directories(intervals PUBLIC ${PROJECT_BINARY_DIR}/include)
target_compile_features(intervals PUBLIC ${CXX14_FEATURES})

## download c version of filib for testing
intervals_download_filib()
add_subdirectory(${THIRD_PARTY_DIR}/filib)
target_link_libraries(intervals PUBLIC filib)

## download highfive for reading hdf5 files
intervals_download_highfive()
set(HIGHFIVE_UNIT_TESTS OFF CACHE BOOL "Enable unit tests")
set(HIGHFIVE_EXAMPLES OFF CACHE BOOL "Compile examples")
add_subdirectory(${THIRD_PARTY_DIR}/highfive)
target_link_libraries(intervals PUBLIC HighFive)






# add boost library for interval
find_package(Boost REQUIRED)
target_link_libraries(intervals PUBLIC Boost::boost)

# add filib c++ library for interval
find_library(prim prim "/usr/local/lib")
if (NOT prim)
else()
	add_definitions(-DUSE_FILIB_PLUSPLUS)
	message("filib++ LIBRARY = ${prim}")
	target_link_libraries(intervals PUBLIC ${prim})
endif()



# use GMP library to ensure query outputs are in rationals
find_package(GMP REQUIRED)
INCLUDE_DIRECTORIES(
    "${GMP_INCLUDES}"
)
message("GMP LIBRARY = ${GMP_LIBRARIES}")
target_link_libraries(intervals PUBLIC ${GMP_LIBRARIES})




if(INTERVALS_TOPLEVEL_PROJECT)
	# Unit tests
	include(CTest)
	enable_testing()
	add_subdirectory(tests)
endif()
