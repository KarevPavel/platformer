cmake_minimum_required(VERSION 3.17)

project(platformer)

set(PROJECT_NAME platformer)

#####
#####  TODO: Указать версии бибилиотек!!!
#####
###################################################################
# Предопределенные переменные
include(ProjectVariables.cmake)

###################################################################
# Копирование сурс ресорсов в папку сборки
file(COPY resources DESTINATION ${PROJECT_BINARY_DIR}/)

###################################################################
# Простая код-генерация.
# Перегоняет названия файлов в папке resources в константы
include(GenerateConsts.cmake)
add_generated_stuff(${MAIN_PROJECT_SOURCE} constants resources)

###################################################################
# Сборка графической библиотеки SFML 2.5.1
# URL: https://github.com/SFML/SFML.git
add_subdirectory(lib/SFML)

###################################################################
# Сборка физической библиотеки box2d
# URL: https://github.com/erincatto/box2d
add_subdirectory(lib/box2d)

###################################################################
# Сборка парсера Tiled карт
# URL: https://github.com/fallahn/tmxlite
add_subdirectory(lib/tmxlite/tmxlite)

###################################################################
# Сборка ecs движка
# URL: https://github.com/skypjack/entt.git
add_subdirectory(lib/entt)

###################################################################
# Парсер ini файлов
# URL: https://github.com/benhoyt/inih
#add_subdirectory(lib/inih)

###################################################################
# Главная сборка
add_subdirectory(src/core)

###################################################################
# Start point
add_executable(${PROJECT_NAME} src/main.cpp include/core/events/sound_events.hpp include/core/components/game_components.hpp include/core/utils/utils.hpp)


target_link_libraries(${PROJECT_NAME}
					  PUBLIC sfml-system
					  PUBLIC sfml-graphics
					  PUBLIC sfml-window
					  PUBLIC sfml-audio
					  PUBLIC sfml-network
					  PUBLIC tmxlite
					  PUBLIC EnTT
					  PUBLIC systems
					  PUBLIC engine
					  PUBLIC graphics
					  PUBLIC sound
					  PUBLIC maplayer
					  )

#[[ TODO: For removal
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
			   include/engine/SFMLOrthogonalLayer.h src/core_v2/engine/engine.cpp src/core_v2/engine/engine.hpp src/core_v2/graphics/texture_manager.cpp src/core_v2/graphics/texture_manager.hpp src/core_v2/graphics/scene_manager.cpp src/core_v2/graphics/scene_manager.hpp)

message(TMXLITE_LIBRARIES ${TMXLITE_LIBRARIES})
message(SFML_LIBRARIES ${SFML_LIBRARIES})
message(BOX2D_LIBRARIES ${BOX2D_LIBRARIES})


///mb later
///		gtest
///		gtest_main

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
]]