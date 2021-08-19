cmake_minimum_required(VERSION 3.17)

project(platformer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/resources)

add_subdirectory(src/core)

link_directories(lib)

add_executable(${PROJECT_NAME}
        src/platformer.cpp
        include/engine/keyboard.h)


target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib/include/pugixml)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib/include/tmx)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/engine)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include/models)

target_link_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(${PROJECT_NAME}
        sfml-graphics
        sfml-window
        sfml-system

        tmx-loader

        engine
        menu
        models)



