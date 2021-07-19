#include "SFML/Graphics.hpp"
#include "keyboard.cpp"
#include "player.h"
namespace core::engine {

    class PlayerEngine : core::keyboard::KeyboardEngine<Player> {

        explicit PlayerEngine(Player player):KeyboardEngine(player){}

        void D_click() override {
            control.moveRight();
        }

        void A_click() override {
            control.moveLeft();
        }

        void W_click() override {
            control.moveUp();
        }

        void S_click() override {
            control.crouch();
        }

        void Space_click() override {
            control.jump();
        }
    };


    Player::Player(double totalHp, float x, float y) : Health(totalHp), Position(x, y) {
        texture.loadFromFile("./resources/3dsoldier.png", sf::IntRect(10, 10, 32, 60));
        sprite.setTexture(texture);
        sprite.setPosition(50, 50);
    }

    void Player::moveRight() {
        sprite.move(MOVEMENT_SPEED, 0);;
    }

    void Player::moveLeft(){
        sprite.move(-MOVEMENT_SPEED, 0);
    }

    void Player::moveUp(){
        sprite.move(0, -MOVEMENT_SPEED);
    }

    void Player::crouch(){
        sprite.move(0, MOVEMENT_SPEED);
    }

    void Player::jump(){
        sprite.move(0, -MOVEMENT_SPEED);
    }
}
