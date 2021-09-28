cmake_minimum_required(VERSION 3.17)

project(gui)

add_library(
		${PROJECT_NAME}
		SHARED
		component.cpp
		button.cpp
)

target_link_libraries(
		${PROJECT_NAME}
		constants)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${GUI_INCLUDE_DIR}
						   PUBLIC ${MANAGER_INCLUDE_DIR})
