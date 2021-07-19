cmake_minimum_required(VERSION 3.17)
project(platformer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(${PROJECT_BINARY_DIR})

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

link_directories(${SFML_INCLUDE_DIR})
include_directories(${SFML_LIBRARY_DIR})

configure_file(resources/3dsoldier.png resources/3dsoldier.png COPYONLY)

add_executable(platformer
        src/core/engine/keyboard.cpp
        src/core/models/general.cpp
        src/core/models/general.h
        src/core/engine/player.cpp
        src/core/engine/player.h
        src/core/engine/constants.cpp
        src/core/engine/constants.h
        src/core/engine/menu.cpp
        src/core/engine/menu.h
        src/core/models/main_menu.cpp
        src/core/engine/menu_item.cpp
        src/core/engine/menu_item.h
        src/core/engine/menu_engine.cpp
        src/core/engine/menu_engine.h
        src/platformer.cpp
        src/core/engine/game_engine.cpp
        src/core/engine/game_engine.h
        src/core/models/Player.cpp src/core/models/PlayerModel.cpp src/core/models/PlayerModel.h src/core/models/Ball.cpp src/core/models/Ball.h src/core/models/BallKeyBoard.cpp src/core/models/BallKeyBoard.h src/core/models/PointOfView.cpp src/core/models/PointOfView.h src/core/models/Vector.cpp src/core/models/Vector.h)

set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)

target_link_libraries(platformer ${SFML_LIBRARIES})

