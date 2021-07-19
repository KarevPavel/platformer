//
// Created by yacopsae on 12/10/2020.
//

#ifndef PLATFORMER_GAME_ENGINE_H
#define PLATFORMER_GAME_ENGINE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "iostream"

namespace core::engine {

    class GameEngine {

    public:
       void StartNewGame(sf::RenderWindow &window);

    private:
        void LoadLevel(int number);

        void LoadResources();

        void GenerateLevel();
    };


    typedef void (GameEngine::*GEngineFn)(sf::RenderWindow &window);
}

#endif //PLATFORMER_GAME_ENGINE_H
