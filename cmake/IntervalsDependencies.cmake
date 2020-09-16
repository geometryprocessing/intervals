
# Prepare dependencies
#
# For each third-party library, if the appropriate target doesn't exist yet,
# download it via external project, and add_subdirectory to build it alongside
# this project.

### Configuration
set(INTERVALS_ROOT     "${CMAKE_CURRENT_LIST_DIR}/..")
set(INTERVALS_EXTERNAL "${INTERVALS_ROOT}/3rdparty")

# Download and update 3rdparty libraries
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
list(REMOVE_DUPLICATES CMAKE_MODULE_PATH)
include(IntervalsDownloadExternal)

################################################################################
# Required libraries
################################################################################

# Sanitizers
if(INTERVALS_WITH_SANITIZERS)
    intervals_download_sanitizers()
    find_package(Sanitizers)
endif()


# CL11
if(NOT TARGET CLI11::CLI11)
    intervals_download_cli11()
    add_subdirectory(${INTERVALS_EXTERNAL}/cli11)
endif()