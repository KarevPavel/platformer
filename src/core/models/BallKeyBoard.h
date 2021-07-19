//
// Created by yacopsae on 14/11/2020.
//

#ifndef PLATFORMER_BALLKEYBOARD_H
#define PLATFORMER_BALLKEYBOARD_H

#include "Ball.h"
#include "../engine/keyboard.cpp"

class BallKeyBoard : public core::keyboard::KeyboardEngine<Ball> {

public:
    explicit BallKeyBoard(Ball &ball) : KeyboardEngine(ball) {}

    void D_click() override;

    void A_click() override;

    void W_click() override;

    void S_click() override;

};


#endif //PLATFORMER_BALLKEYBOARD_H
