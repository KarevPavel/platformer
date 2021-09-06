#include <game_engine.h>
#include <tmxlite/Map.hpp>

namespace core::engine {

    GameEngine::GameEngine(STATE &currentState,
                           sf::RenderWindow &window,
                           int lvl) :
            _currentState(currentState),
            _window(window),
            _mapLayer(LoadLevel(lvl)) {
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            _view.setCenter(_view.getCenter().x, _view.getCenter().y + 10);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            _view.setCenter(_view.getCenter().x, _view.getCenter().y - 10);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            _view.setCenter(_view.getCenter().x - 10, _view.getCenter().y);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            _view.setCenter(_view.getCenter().x + 10, _view.getCenter().y);
        }

        _window.setView(_view);
        for (auto &layer : _mapLayer) {
            layer.update(time);
            _window.draw(layer);
        }
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
