cmake_minimum_required(VERSION 3.17)

project(manager)

add_library(
		${PROJECT_NAME}
		SHARED
		resources.cpp
		font_manager.cpp
		music_manager.cpp texture_manager.cpp ../../../../include/engine/manager/texture_manager.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${MANAGER_INCLUDE_DIR})