set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
add_definitions(-ftemplate-backtrace-limit=0)
set(MAIN_PROJECT_SOURCE ${CMAKE_SOURCE_DIR})
set(ENGINE_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine)
set(MODELS_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/models)
set(SOUND_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/sound)
set(STATE_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/states)
set(BOX2D_EXT_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/box2d)
set(MANAGER_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/engine/manager)
set(GUI_INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include/gui)