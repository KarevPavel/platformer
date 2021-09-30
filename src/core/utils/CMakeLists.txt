cmake_minimum_required(VERSION 3.17)

project(utils)

add_library(
		${PROJECT_NAME}
		SHARED
		utils.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${UTILS_INCLUDE_DIR})