set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(MAIN_PROJECT_SOURCE ${CMAKE_SOURCE_DIR})
set(INCLUDE_DIR ${MAIN_PROJECT_SOURCE}/include_v2)
set(ENGINE_INCLUDE_DIR ${INCLUDE_DIR}/core/engine)
set(COMPONENTS_INCLUDE_DIR ${INCLUDE_DIR}/core/components)
set(EVENTS_INCLUDE_DIR ${INCLUDE_DIR}/core/events)
set(GRAPHICS_INCLUDE_DIR ${INCLUDE_DIR}/core/graphics)
set(SYSTEMS_INCLUDE_DIR ${INCLUDE_DIR}/core/systems)
set(SOUND_INCLUDE_DIR ${INCLUDE_DIR}/core/sound)

add_definitions(-ftemplate-backtrace-limit=0)