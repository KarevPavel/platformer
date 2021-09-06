cmake_minimum_required(VERSION 3.17)
project(platformer)
SET(PROJECT_NAME platformer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/resources)

find_package(TMXLITE REQUIRED)
find_package(SFML 2.5 REQUIRED graphics window system)

include_directories(
        ${TMXLITE_INCLUDE_DIR}
        ${SFML_INCLUDE_DIR}
)

add_subdirectory(src/core)

add_executable(${PROJECT_NAME}
        src/platformer.cpp
        include/engine/keyboard.h include/engine/SFMLOrthogonalLayer.h)

message(TMXLITE_LIBRARIES ${TMXLITE_LIBRARIES})
message(SFML_LIBRARIES ${SFML_LIBRARIES})

target_link_libraries(
        ${PROJECT_NAME}
        ${TMXLITE_LIBRARIES}
        ${SFML_LIBRARIES}
        gtest
        gtest_main
        engine
        menu
        models
)
