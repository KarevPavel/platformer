//
// Created by yacopsae on 23/09/2021.
//

#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "component.hpp"
#include "utils.hpp"

class Button : public Component {

 public:
  Button(TextureManager &textures, FontManager &fonts);

  void onEnter() override;

  void onLeave() override;

  void activate() override;

  void deactivate() override;

  void setSize(int width, int height);

  void setActiveFunction(std::function<void(Button &)> onActivate);

  void setDeactiveFunction(std::function<void(Button &)> onDeactivate);

  void setText(const std::string &text);

  sf::FloatRect getGlobalBounds() const override;

  sf::FloatRect getLocalBounds() const override;

  void matchSizeToText(float padding = 0.f);

  template<typename T>
  void setPositionBelow(const T &object, float padding = 0.f);

  void handleEvents(const sf::Event &event) override;

  void update(sf::Vector2f mousePosition) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
 private:

  sf::Texture &normalTexture;
  const sf::Texture &selectedTexture;
  sf::Sprite sprite;
  sf::Text text;
  sf::Vector2f size;

  std::function<void(Button &)> activateFunction;
  std::function<void(Button &)> deactivateFunction;
};

template<typename T>
inline void Button::setPositionBelow(const T &object, float padding) {
  const sf::Vector2f pos(object.getPosition().x, object.getPosition().y);

  auto offset = sf::Vector2f(0, object.getGlobalBounds().height);

  padding *= getScale().y;
  offset *= getScale().y;
  setPosition(pos + offset + sf::Vector2f(0, padding));
}