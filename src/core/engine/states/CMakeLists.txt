cmake_minimum_required(VERSION 3.17)

project(states)

add_library(
		${PROJECT_NAME}
		SHARED
		menu_state.cpp
		pause_state.cpp
		game_state.cpp
		state_stack.cpp
		state.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${MANAGER_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${GUI_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} constants)