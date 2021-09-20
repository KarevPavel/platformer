//
// Created by yacopsae on 12/10/2020.
//

#pragma once

#include <constants.h>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <ball.h>
#include "iostream"
#include "SFMLOrthogonalLayer.h"

namespace core::engine {

    class GameEngine {

    public:
        enum STATE {
            MENU,
            GAME
        };

        GameEngine() = delete;
        GameEngine(GameEngine& ) = delete;
        explicit GameEngine(STATE & currentState,
                            sf::RenderWindow &window,
                            Ball& ball,
                            int lvl);

        void changeState(STATE & currentState);

        void startNewGame(sf::RenderWindow &window);

        void update(sf::Time time);

        void exitGame(sf::RenderWindow &window);

    private:
        STATE & _currentState;
        sf::RenderWindow & _window;
        std::list<MapLayer> _mapLayer;
        sf::View _view;
        Ball _ball;

        std::list<MapLayer> LoadLevel(int number);

        void GenerateLevel();

        void LoadPlayer();

    };

    typedef void (GameEngine::*GEngineFn)(sf::RenderWindow & window);
    typedef void (GameEngine::*GEngineStateChange)(GameEngine::STATE & currentState);
}