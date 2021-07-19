//
// Created by yacopsae on 14/10/2020.
//

#include <SFML/Graphics.hpp>
#include "../engine/keyboard.cpp"
#include "PlayerModel.h"

class Player : public core::keyboard::KeyboardEngine<PlayerModel> {

private:
    float elapsed;

public:
    explicit Player(PlayerModel& model) : KeyboardEngine(model) {}

    void processEvent(sf::Event::KeyEvent keyevent, float elapsedSec) {
        elapsed = elapsedSec;
        KeyboardEngine::processEvent(keyevent);
    }

    void D_click() override {
        control.walk(elapsed);
    }
};

