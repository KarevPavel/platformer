cmake_minimum_required(VERSION 3.17)

project(models)

add_library(
        ${PROJECT_NAME}
        general.cpp
        player_model.cpp
        player.cpp
        ball.cpp
        point_of_view.cpp
        vector.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../include/engine)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../include/models)