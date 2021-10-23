cmake_minimum_required(VERSION 3.17)

project(engine)

add_library(${PROJECT_NAME}
			SHARED
			engine.cpp
			entity_manager.cpp
			debug_box_2_d.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${ENGINE_INCLUDE_DIR}
						   PUBLIC ${GRAPHICS_INCLUDE_DIR}
						   PUBLIC ${SYSTEMS_INCLUDE_DIR}
						   PUBLIC ${SOUND_INCLUDE_DIR}
						   )

target_link_libraries(${PROJECT_NAME}
					  PUBLIC constants
					  PUBLIC EnTT
					  PUBLIC box2d)