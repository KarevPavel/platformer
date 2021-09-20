cmake_minimum_required(VERSION 3.17)

project(states)

add_library(
		${PROJECT_NAME}
		menu_state.cpp
		pause_state.cpp
		game_state.cpp
)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${MODELS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_EXT_INCLUDE_DIR})