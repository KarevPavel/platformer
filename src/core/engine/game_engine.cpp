#include <game_engine.h>
#include <tmxlite/Map.hpp>

namespace core::engine {

GameEngine::GameEngine(STATE &currentState,
					   sf::RenderWindow &window,
					   Ball ball,
					   int lvl) :
	_currentState(currentState),
	_window(window),
	_mapLayer(LoadLevel(lvl)),
	_ball(ball) {
  this->_view = sf::View{
	  {400, 400},
	  {200, 200}
  };
}

void GameEngine::startNewGame(sf::RenderWindow &window) {
  //window.setView(_view);
//        LoadResources();
}

void GameEngine::update(sf::Time time) {

  _view.setCenter(_ball.getCord());

  _window.setView(_view);
  for (auto &layer : _mapLayer) {
	layer.update(time);
	_window.draw(layer);
  }
  _ball.update(time, _mapLayer);
}

void GameEngine::changeState(STATE &currentState) {
  this->_currentState = currentState;
}

void GameEngine::exitGame(sf::RenderWindow &window) {
  //TODO: Здесь сохранить все необходимые ресурсы

  window.close();
}

std::list<MapLayer> GameEngine::LoadLevel(int number) {
  tmx::Map map;
  map.load("/home/yacopsae/CLionProjects/platformer/resources/levels/level" + std::to_string(number) + ".tmx");

  auto list = std::list<MapLayer>();
  for (int i = 0; i < map.getLayers().size(); i++) {
	list.emplace_back(map, i);
  }
  return list;
}

void GameEngine::LoadPlayer() {

}

/*    MapLayer GameEngine::LoadResources() {
        //return LoadLevel(core::engine::game::FIRST_LEVEL);
    }*/

void GameEngine::GenerateLevel() {

}
}
