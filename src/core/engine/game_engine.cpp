//
// Created by yacopsae on 12/10/2020.
//

#include "constants.h"
#include "game_engine.h"
#include "../models/Player.cpp"
#include <SFML/Graphics.hpp>

namespace core::engine {

    void GameEngine::StartNewGame(sf::RenderWindow &window) {
        LoadLevel(core::engine::game::FIRST_LEVEL);
        /*sf::RectangleShape rshape;
        rshape.setSize(sf::Vector2f(20, 20));
        rshape.setPosition(200, 200);
        rshape.setFillColor(sf::Color::Red);
        window.draw(rshape);*/


        std::cout << " DRAW! " << std::endl;

    }

    void GameEngine::LoadLevel(int number){

    }

    void GameEngine::LoadResources(){
        
    }

    void GameEngine::GenerateLevel(){

    }
}
