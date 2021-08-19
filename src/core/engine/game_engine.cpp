//
// Created by yacopsae on 12/10/2020.
//

#include <game_engine.h>

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
       MapLoader ml("path/to/maps");
    }

    void LoadPlayer() {

    }

    void GameEngine::LoadResources() {

    }

    void GameEngine::GenerateLevel() {

    }
}
