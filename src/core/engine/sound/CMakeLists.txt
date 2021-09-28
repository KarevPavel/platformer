cmake_minimum_required(VERSION 3.17)

project(sound)

add_library(
		${PROJECT_NAME}
		SHARED
		music_player.cpp
		sound_player.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${SOUND_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} constants)