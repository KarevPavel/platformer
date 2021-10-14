cmake_minimum_required(VERSION 3.17)

project(systems)

add_library(
		${PROJECT_NAME}
		SHARED
		base_system.cpp
		sound_system.cpp
		level_system.cpp
		game_system.cpp map_render_system.cpp map_render_system.hpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${SYSTEMS_INCLUDE_DIR}
						   PUBLIC ${EVENTS_INCLUDE_DIR}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${GRAPHICS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${COMPONENTS_INCLUDE_DIR}
						   )

target_link_libraries(${PROJECT_NAME}
					  PUBLIC constants
					  PUBLIC EnTT)