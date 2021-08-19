cmake_minimum_required(VERSION 3.17)

project(engine)

add_library(
        ${PROJECT_NAME}
        applcation.cpp
        constants.cpp
        game_engine.cpp
        player_engine.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../include/engine)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../include/models)
add_subdirectory(menu)