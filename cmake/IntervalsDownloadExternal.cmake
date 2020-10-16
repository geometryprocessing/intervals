################################################################################
include(DownloadProject)

# With CMake 3.8 and above, we can hide warnings about git being in a
# detached head by passing an extra GIT_CONFIG option.
set(INTERVALS_EXTRA_OPTIONS TLS_VERIFY OFF)
if(NOT (${CMAKE_VERSION} VERSION_LESS "3.8.0"))
	list(APPEND INTERVALS_EXTRA_OPTIONS GIT_CONFIG advice.detachedHead=false)
endif()

# On CMake 3.6.3 and above, there is an option to use shallow clones of git repositories.
# The shallow clone option only works with real tags, not SHA1, so we use a separate option.
set(INTERVALS_BRANCH_OPTIONS)
if(NOT (${CMAKE_VERSION} VERSION_LESS "3.6.3"))
	# Disabled for now until we can make sure that it has no adverse effects
	# (Downside is that the eigen mirror is huge again)
	# list(APPEND INTERVALS_BRANCH_OPTIONS GIT_SHALLOW 1)
endif()

option(INTERVALS_SKIP_DOWNLOAD "Skip downloading external libraries" OFF)

# Shortcut functions
function(intervals_download_project_aux name source)
	if(NOT INTERVALS_SKIP_DOWNLOAD)
		download_project(
			PROJ         ${name}
			SOURCE_DIR   "${source}"
			DOWNLOAD_DIR "${INTERVALS_EXTERNAL}/.cache/${name}"
			QUIET
			${INTERVALS_EXTRA_OPTIONS}
			${ARGN}
		)
	endif()
endfunction()

function(intervals_download_project name)
	intervals_download_project_aux(${name} "${INTERVALS_EXTERNAL}/${name}" ${ARGN})
endfunction()

################################################################################

## gmp
function(intervals_download_gmp)
    intervals_download_project(gmp
		GIT_REPOSITORY https://github.com/alisw/GMP
    )
endfunction()

function(intervals_download_filib)
	intervals_download_project(filib
		GIT_REPOSITORY https://github.com/txstc55/filib
		GIT_TAG        1b36c5047fd2ee27fcbb6d73deb25da7f77a6f70
	)
endfunction()

## Sanitizers
function(intervals_download_sanitizers)
    intervals_download_project(sanitizers-cmake
        GIT_REPOSITORY https://github.com/arsenm/sanitizers-cmake.git
        GIT_TAG        6947cff3a9c9305eb9c16135dd81da3feb4bf87f
    )
endfunction()

## CLI11
function(intervals_download_cli11)
    intervals_download_project(cli11
        URL     https://github.com/CLIUtils/CLI11/archive/v1.6.1.tar.gz
        URL_MD5 48ef97262adb0b47a2f0a7edbda6e2aa
    )
endfunction()