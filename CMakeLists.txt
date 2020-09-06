cmake_minimum_required(VERSION 3.1)
project (interval)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(test_sources
    ${SRC_DIR}/main.cpp
)



## add the dynamic library
# add_library(rounded SHARED IMPORTED)
# set_property(TARGET rounded PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/rounded_operations/src/rounded.dylib)
file(GLOB_RECURSE LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/rounded_operations/src/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

add_executable(unit_tests ${test_sources})
target_link_libraries(unit_tests PUBLIC "${LIBRARIES}")
target_include_directories(unit_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/rounded_operations/src/)

add_custom_command (TARGET unit_tests
    POST_BUILD COMMAND "${CMAKE_INSTALL_NAME_TOOL}"
        "-change" "rounded.dylib" "@executable_path/../rounded_operations/src/rounded.dylib"
    "$<TARGET_FILE:unit_tests>" VERBATIM)
