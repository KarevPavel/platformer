//
// Created by yacopsae on 12/10/2021.
//

#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include <resource_manager.hpp>
#include "music_player.hpp"

#include "scene.hpp"
#include "entity_manager.hpp"


class MenuScene : public Scene
{
  EntityManager em;
  sf::Vector2f click_position;
  sf::Sprite background_texture;
  FontManager fonts;
  MusicPlayer music;

  sf::Vector2f getMousePosition();

 public:
  MenuScene();
  ~MenuScene();

  void init() override;
  void update() override;
  void fixedUpdate(const float dt) override;
  void render(const float alpha_lerp) override;
};