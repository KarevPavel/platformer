
find_program(PYTHON_EXECUTABLE python)

if(NOT PYTHON_EXECUTABLE)
	message(FATAL_ERROR "python not found. Required by generator.")
endif()

set(GENERATOR generate_resources.py)

function(add_generated_stuff MAIN_DIR TARGET INFILE)
	set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${INFILE})
	set(GENERATOR_PATH ${PYTHON_EXECUTABLE} ${MAIN_DIR}/${GENERATOR})
	set(INPATH ${MAIN_DIR}/${INFILE})

	execute_process(
			COMMAND ${GENERATOR_PATH} --print-dependencies ${INPATH}
			OUTPUT_VARIABLE DEPENDENCIES
			RESULT_VARIABLE RETURN_VALUE
	)

	if (NOT RETURN_VALUE EQUAL 0)
		message(FATAL_ERROR "Failed to get dependencies for ${INFILE}")
	endif()
    message('DEPENDENCIES '${DEPENDENCIES})
	add_custom_command(
			COMMAND ${GENERATOR_PATH} ${INPATH}
			OUTPUT ${DEPENDENCIES}
			DEPENDS ${GENERATOR} ${INFILE}
			COMMENT "Generating ${DEPENDENCIES} from ${INFILE}"
	)

	add_library(${TARGET} SHARED ${DEPENDENCIES})
	target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
endfunction()