cmake_minimum_required(VERSION 3.1)
################################################################################################################################################################



set(test_sources
    main.cpp
    Rational.h
    helper.hpp
    Timer.h
    macro_functions.hpp
    flags.hpp
)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-march=native" COMPILER_SUPPORTS_MARCH_NATIVE)
if(COMPILER_SUPPORTS_MARCH_NATIVE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(unit_tests ${test_sources})





foreach(source IN ITEMS ${test_sources})
    source_group("tests" FILES "${source}")
endforeach()

target_link_libraries(unit_tests PUBLIC intervals)




if(INTERVALS_WITH_SANITIZERS)
    add_sanitizers(unit_tests)
endif()



if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

## use GMP library to ensure query outputs are in rationals
find_package(GMP REQUIRED)
INCLUDE_DIRECTORIES(
    "${GMP_INCLUDES}"
)
message("GMP LIBRARY = ${GMP_LIBRARIES}")
target_link_libraries(unit_tests PUBLIC ${GMP_LIBRARIES})


## link highfive for hdf5 file writing and reading
target_link_libraries(unit_tests PUBLIC HighFive)

