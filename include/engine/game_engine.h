//
// Created by yacopsae on 12/10/2020.
//

#pragma once

#include <constants.h>
#include <SFML/Graphics.hpp>
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