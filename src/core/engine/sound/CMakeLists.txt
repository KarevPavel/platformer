cmake_minimum_required(VERSION 3.17)

project(sound)

add_library(
		${PROJECT_NAME}
		sound_player.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${MODELS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_EXT_INCLUDE_DIR})