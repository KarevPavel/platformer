cmake_minimum_required(VERSION 3.17)

project(manager)

add_library(
		${PROJECT_NAME}
		SHARED
		resource_manager.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${MANAGER_INCLUDE_DIR})