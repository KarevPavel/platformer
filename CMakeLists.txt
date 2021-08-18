cmake_minimum_required(VERSION 3.17)
project(platformer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

link_directories(${SFML_INCLUDE_DIR})

include_directories(src/core)
include_directories(${SFML_LIBRARY_DIR})
include_directories(${PROJECT_BINARY_DIR})


#configure_file(resources/3dsoldier.png resources/3dsoldier.png COPYONLY)

add_executable(platformer
        src/platformer.cpp
        src/core/models/general.cpp
        src/core/engine/player_engine.cpp
        src/core/engine/constants.cpp
        src/core/engine/menu.cpp
        src/core/engine/menu_item.cpp
        src/core/engine/menu_engine.cpp
        src/core/engine/game_engine.cpp
        src/core/engine/applcation.cpp

        src/core/models/main_menu.cpp
        src/core/models/player_model.cpp
        src/core/models/player.cpp
        src/core/models/ball.cpp
        src/core/models/point_of_view.cpp
        src/core/models/vector.cpp

        src/core/levels/level1.cpp

        include/engine/keyboard.h)


set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)

target_include_directories(platformer PUBLIC ./include/engine)
target_include_directories(platformer PUBLIC ./include/models)

target_link_libraries(platformer ${SFML_LIBRARIES})

