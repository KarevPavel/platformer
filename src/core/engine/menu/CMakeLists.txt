cmake_minimum_required(VERSION 3.17)

project(menu)

add_library(
		${PROJECT_NAME}
		SHARED
		main_menu.cpp
		menu.cpp
		menu_item.cpp
		menu_engine.cpp
)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${MODELS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   PUBLIC ${STATE_INCLUDE_DIR}
						   PUBLIC ${BOX2D_EXT_INCLUDE_DIR}
						   PUBLIC ${GUI_INCLUDE_DIR}
						   )

target_link_libraries(${PROJECT_NAME} constants)