//
// Created by yacopsae on 06/10/2020.
//

#include "SFML/Graphics.hpp"
#include "../models/general.h"

#ifndef PLATFORMER_PLAYER_H
#define PLATFORMER_PLAYER_H

namespace core::engine {

    class Player : core::model::Position, core::model::Health {
    public:
        const int MOVEMENT_SPEED = 5;
        Player(double totalHp, float x, float y);
        void moveRight();
        void moveLeft();
        void moveUp();
        void crouch();
        void jump();

    private:
        sf::Sprite sprite;
        sf::Texture texture;
    };
}

#endif //PLATFORMER_PLAYER_H
