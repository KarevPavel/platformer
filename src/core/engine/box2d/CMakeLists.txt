cmake_minimum_required(VERSION 3.17)

project(box2d)

add_library(
		${PROJECT_NAME}
		debug_box_2_d.cpp
		world_listener.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/engine)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/models)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/engine/menu)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/engine/sound)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/engine/state)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/engine/box2d)