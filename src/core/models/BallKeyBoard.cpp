//
// Created by yacopsae on 14/11/2020.
//

#include "BallKeyBoard.h"

void BallKeyBoard::D_click() {
    control.rotateRight();
}

void BallKeyBoard::A_click() {
    control.rotateLeft();
}

void BallKeyBoard::W_click() {
    control.moveForward();
}

void BallKeyBoard::S_click() {
    control.moveBackward();
}
