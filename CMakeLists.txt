cmake_minimum_required(VERSION 3.1)

project (interval)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(test_sources
    ${SRC_DIR}/main.cpp
)

## add the dynamic library
# add_library(rounded SHARED IMPORTED)
# set_property(TARGET rounded PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/rounded_operations/src/rounded.dylib)
file(GLOB LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/rounded_operations/src/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

add_executable(unit_tests ${test_sources})
target_include_directories(unit_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/rounded_operations/src/)
target_link_libraries(unit_tests ${LIBRARIES})
