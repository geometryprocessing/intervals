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


## add the dynamic library
if(APPLE)
    file(GLOB_RECURSE LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../interval_operations/src/*.dylib")
    message("MACOS LIBRARIES = ${LIBRARIES}")
endif()

if(UNIX AND NOT APPLE)
    file(GLOB_RECURSE LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../interval_operations/src/*.so")
    message("LINUX LIBRARIES = ${LIBRARIES}")
endif()

IF (WIN32)
    file(GLOB_RECURSE LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../interval_operations/src/*.lib")
    message("WINDOWS LIBRARIES = ${LIBRARIES}")
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()


find_package(GMP REQUIRED)

INCLUDE_DIRECTORIES(
    "${GMP_INCLUDES}"
)
message("GMP LIBRARY = ${GMP_LIBRARIES}")


target_link_libraries(unit_tests PUBLIC "${LIBRARIES}")
target_link_libraries(unit_tests PUBLIC ${GMP_LIBRARIES})

find_library(prim prim "/usr/local/lib")
message("filib LIBRARY = ${prim}")
target_link_libraries(unit_tests PUBLIC ${prim})

find_package(Boost REQUIRED)
target_link_libraries(unit_tests PUBLIC Boost::boost)

## link highfive for hdf5 file writing and reading
target_link_libraries(unit_tests PUBLIC HighFive)


if(APPLE)
    add_custom_command (TARGET unit_tests
        POST_BUILD COMMAND "${CMAKE_INSTALL_NAME_TOOL}"
            "-change" "interval_c.dylib" "@executable_path/../interval_operations/src/interval_c.dylib"
        "$<TARGET_FILE:unit_tests>" VERBATIM)
endif()

target_link_libraries(unit_tests PUBLIC filib)
