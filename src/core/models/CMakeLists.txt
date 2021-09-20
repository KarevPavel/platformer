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

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${MODELS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_EXT_INCLUDE_DIR})