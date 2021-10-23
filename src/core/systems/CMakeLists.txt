cmake_minimum_required(VERSION 3.17)

project(systems)

add_library(
		${PROJECT_NAME}
		SHARED
		base_system.cpp
		music_system.cpp
		map_render_system.cpp
		game_system.cpp
		sound_system.cpp
		physics_system.cpp)

add_subdirectory(map)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${COMPONENTS_INCLUDE_DIR}
						   PUBLIC ${SYSTEMS_INCLUDE_DIR}
						   PUBLIC ${EVENTS_INCLUDE_DIR}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${GRAPHICS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${SYSTEMS_MAP_INCLUDE_DIR}
						   )

target_link_libraries(${PROJECT_NAME}
					  PUBLIC constants
					  PUBLIC EnTT)