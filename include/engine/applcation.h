//
// Created by yacopsae on 18/08/2021.
//
#pragma once

#include <player_engine.h>
#include <SFML/Graphics.hpp>
#include <main_menu.h>
#include <menu_engine.h>
#include "game_engine.h"
#include <ball.h>

class Application {


private:
    void configureWindow(sf::RenderWindow &window);

public:
    int start();


};