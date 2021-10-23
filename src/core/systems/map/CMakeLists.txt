cmake_minimum_required(VERSION 3.17)

project(maplayer)

add_library(
		${PROJECT_NAME}
		SHARED
		chunk.cpp
		chunk_array.cpp
		map_layer.cpp)

target_include_directories(${PROJECT_NAME}
						   PUBLIC ${SYSTEMS_MAP_INCLUDE_DIR}
						   PUBLIC ${UTILS_INCLUDE_DIR}
						   )

target_link_libraries(${PROJECT_NAME}
					  PUBLIC constants)