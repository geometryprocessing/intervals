# Copy project header files into the build directory
function(intervals_copy_headers)
	foreach(filepath IN ITEMS ${ARGN})
		get_filename_component(filename "${filepath}" NAME)
		if(${filename} MATCHES ".*\.(hpp|h|ipp)$")
			configure_file(${filepath} ${PROJECT_BINARY_DIR}/include/intervals/${filename})
		endif()
	endforeach()
endfunction()

# Set source group for IDE like Visual Studio or XCode
function(intervals_set_source_group)
	foreach(filepath IN ITEMS ${ARGN})
		get_filename_component(folderpath "${filepath}" DIRECTORY)
		get_filename_component(foldername "${folderpath}" NAME)
		source_group(foldername FILES "${filepath}")
	endforeach()
endfunction()

# Add an application from one source
function(intervals_add_application APP_SOURCE)
	# Add executable
	get_filename_component(APP_NAME ${APP_SOURCE} NAME_WE)
	add_executable(${APP_NAME} ${APP_SOURCE})
	message(STATUS "Compiling single-source application: ${APP_NAME}")

	# Dependencies
	target_link_libraries(${APP_NAME} PRIVATE ${ARGN})

	# Output directory for binaries
	set_target_properties(${APP_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

	if(INTERVALS_WITH_SANITIZERS)
		add_sanitizers(${APP_NAME})
	endif()
endfunction()