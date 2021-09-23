cmake_minimum_required(VERSION 3.17)

project(states)

set(STATE_INCLUDE_DIR /home/yacopsae/CLionProjects/platformer/include/engine/state)

add_library(
		${PROJECT_NAME}
		SHARED
		menu_state.cpp
		pause_state.cpp
		game_state.cpp
)

target_include_directories(${PROJECT_NAME}
						   PUBLIC
						   ${STATE_INCLUDE_DIR}
						   ${MANAGER_INCLUDE_DIR})