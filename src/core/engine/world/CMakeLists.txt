cmake_minimum_required(VERSION 3.17)

project(world)

add_library(
		${PROJECT_NAME}
		SHARED
		world_listener.cpp
		world.cpp
		level.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${MANAGER_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${GUI_INCLUDE_DIR}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_INCLUDE_DIR}
						   PUBLIC ${WORLD_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} constants)