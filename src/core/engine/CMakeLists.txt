cmake_minimum_required(VERSION 3.17)

project(engine)

add_library(
		${PROJECT_NAME}
		SHARED
		application.cpp
		constants.cpp
		game_engine.cpp
		player_engine.cpp
		settings_manager.cpp
		world.cpp)

add_subdirectory(box2d)
add_subdirectory(menu)
add_subdirectory(states)
add_subdirectory(sound)
add_subdirectory(manager)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${MODELS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_EXT_INCLUDE_DIR})


target_link_libraries(
		box2d
		menu
		states
		sound
		manager
)