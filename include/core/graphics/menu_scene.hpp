//
// Created by yacopsae on 12/10/2021.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

#include <resource_manager.hpp>
#include "music_player.hpp"
#include <button.hpp>
#include "scene.hpp"
#include "entity_manager.hpp"
#include "drawable_container.hpp"

class MenuScene : public Scene
{
  EntityManager em;
  sf::Text gameName;
  sf::Sprite backgroundTexture;
  //std::vector<std::unique_ptr<Button>> buttons;
  DrawableContainer<Button>* buttons;

 public:
  MenuScene();
  ~MenuScene();

  void init() override;
  void update() override;
  void fixedUpdate(const float dt) override;
  void render(const float alpha_lerp) override;

 private:
  void createButtons(sf::RenderWindow &window, sf::Vector2f position);
};