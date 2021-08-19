cmake_minimum_required(VERSION 3.17)

project(menu)

add_library(
        ${PROJECT_NAME}
        main_menu.cpp
        menu.cpp
        menu_item.cpp
        menu_engine.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/engine)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/../../../../include/models)