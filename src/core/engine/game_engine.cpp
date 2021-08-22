#include <game_engine.h>
#include <tmxlite/Map.hpp>

namespace core::engine {

    void GameEngine::startNewGame(sf::RenderWindow &window) {
        LoadLevel(core::engine::game::FIRST_LEVEL);

        std::cout << " DRAW! " << std::endl;
    }

    void GameEngine::exitGame(sf::RenderWindow &window) {
        //TODO: Здесь сохранить все необходимые ресурсы
        window.close();
    }

    void GameEngine::LoadLevel(int number) {
       //tmx::MapLoader ml("path/to/maps");
        tmx::Map map;
        map.load("assets/demo.tmx");
/*
        MapLayer layerZero(map, 0);
        MapLayer layerOne(map, 1);
        MapLayer layerTwo(map, 2);*/
    }

    void LoadPlayer() {

    }

    void GameEngine::LoadResources() {

    }

    void GameEngine::GenerateLevel() {

    }
}
