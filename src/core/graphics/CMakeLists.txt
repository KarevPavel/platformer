cmake_minimum_required(VERSION 3.17)

project(graphics)

add_library(${PROJECT_NAME}
			SHARED
			scene_manager.cpp
			scene.cpp
			menu_scene.cpp
			game_scene.cpp
			button.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${COMPONENTS_INCLUDE_DIR}
						   PUBLIC ${GRAPHICS_INCLUDE_DIR}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${SYSTEMS_INCLUDE_DIR}
						   PUBLIC ${EVENTS_INCLUDE_DIR}
						   PUBLIC ${UTILS_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
					  PUBLIC constants
					  PUBLIC EnTT)