//
// Created by yacopsae on 25/10/2021.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <resource_manager.hpp>
#include <SFML/Window/Event.hpp>
#include "utils.hpp"

class Button : public sf::Drawable, public sf::Transformable {

 public:
  Button(TextureManager &textures, FontManager &fonts);

  void onEnter();

  void onLeave();

  void activate();

  void deactivate();

  void setSize(int width, int height);

  void setDeactiveFunction(std::function<void(Button &)> onDeactivate);

  void setText(const std::string &text);

  sf::FloatRect getGlobalBounds() const;

  sf::FloatRect getLocalBounds() const;

  void matchSizeToText(float padding = 0.f);

  void setPositionBelow(const Button &object, float padding = 0.f);

  void handleEvents(const sf::Event &event);

  void update(sf::Vector2f mousePosition);

  void setActiveFunction(std::function<void(Button &)> onActivate);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
 private:

  sf::Texture &normalTexture;
  const sf::Texture &selectedTexture;
  sf::Sprite sprite;
  sf::Text text;
  sf::Vector2f size;

  std::function<void(Button &)> activateFunction;
  std::function<void(Button &)> deactivateFunction;
  bool isSelected;
  bool isActive;
};