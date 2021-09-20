cmake_minimum_required(VERSION 3.17)
project(platformer)
set(PROJECT_NAME platformer)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(MAIN_PROJECT_SOURCE ${CMAKE_SOURCE_DIR})
set(ENGINE_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine)
set(MODELS_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/models)
set(SOUND_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/sound)
set(STATE_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/state)
set(BOX2D_EXT_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/box2d)


file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/resources)

find_package(Box2D REQUIRED)
find_package(TMXLITE REQUIRED)
find_package(SFML 2.5 REQUIRED audio network graphics window system)

include_directories(
		${TMXLITE_INCLUDE_DIR}
		${SFML_INCLUDE_DIR}
		${BOX2D_INCLUDE_DIR}
)

add_subdirectory(src/core)

add_executable(${PROJECT_NAME}
			   src/platformer.cpp
			   include/engine/keyboard.h
			   include/engine/SFMLOrthogonalLayer.h
			   include/engine/directions.h
			   include/engine/state/state.hpp
			   include/engine/state/state_list.hpp
			   )

message(TMXLITE_LIBRARIES ${TMXLITE_LIBRARIES})
message(SFML_LIBRARIES ${SFML_LIBRARIES})
message(BOX2D_LIBRARIES ${BOX2D_LIBRARIES})

target_link_libraries(
		${PROJECT_NAME}
		${TMXLITE_LIBRARIES}
		${SFML_LIBRARIES}
		${BOX2D_LIBRARIES}
		gtest
		gtest_main
		states
		engine
		menu
		manager
		box2d
		sound
		models
)
