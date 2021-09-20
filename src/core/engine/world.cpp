//
// Created by yacopsae on 16/09/2021.
//

#include "world.hpp"

World::World(sf::RenderWindow &window) :
	_window(window),
	_worldView(window.getDefaultView()),
	b2_World(b2Vec2(0.f, 9.8f)),
	debugDraw(window) {

}
