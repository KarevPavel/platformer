//
// Created by yacopsae on 18/08/2021.
//

#pragma once

#include <game_engine.h>
#include <menu.h>
#include <menu_item.h>

namespace core::models {

    class MainMenu : public core::engine::Menu {

    public:
        explicit MainMenu(sf::RenderWindow &window);

    };
}