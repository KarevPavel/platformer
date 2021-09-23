cmake_minimum_required(VERSION 3.17)

project(box2d)

add_library(
		${PROJECT_NAME}
		SHARED
		debug_box_2_d.cpp
		world_listener.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${MODELS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_EXT_INCLUDE_DIR})