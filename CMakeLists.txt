cmake_minimum_required(VERSION 3.17)
project(platformer)
set(PROJECT_NAME platformer)

include(ProjectVariables.cmake)

file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/)

include(GenerateConsts.cmake)

add_generated_stuff(${MAIN_PROJECT_SOURCE} constants resources)

find_package(Box2D REQUIRED)
find_package(TMXLITE REQUIRED)
find_package(SFML 2.5 REQUIRED audio network graphics window system)

include_directories(
		${TMXLITE_INCLUDE_DIR}
		${SFML_INCLUDE_DIR}
		${BOX2D_INCLUDE_DIR}
		${GUI_INCLUDE_DIR}
		${UTILS_INCLUDE_DIR}
		${WORLD_INCLUDE_DIR})

add_subdirectory(src/core)
add_executable(${PROJECT_NAME}
			   src/platformer.cpp
			   include/engine/keyboard.h
			   include/engine/SFMLOrthogonalLayer.h)

message(TMXLITE_LIBRARIES ${TMXLITE_LIBRARIES})
message(SFML_LIBRARIES ${SFML_LIBRARIES})
message(BOX2D_LIBRARIES ${BOX2D_LIBRARIES})

#[[
mb later
		gtest
		gtest_main
]]
target_link_libraries(
		${PROJECT_NAME}
		${TMXLITE_LIBRARIES}
		${SFML_LIBRARIES}
		${BOX2D_LIBRARIES}
		constants
		world
		utils
		gui
		states
		engine
		menu
		manager
		box2d
		sound
		models
)