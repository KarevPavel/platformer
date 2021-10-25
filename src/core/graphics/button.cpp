//
// Created by yacopsae on 25/10/2021.
//

#include <textures.hpp>
#include <fonts.hpp>
#include "button.hpp"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RenderStates.hpp"


Button::Button(TextureManager &textures, FontManager &fonts) :
	normalTexture(textures.getResource(constants::SELECTED_PATH)),
	selectedTexture(textures.getResource(constants::PAPER_TEXTURE_PATH)),
	text("", fonts.getResource(constants::SHLOP_RG_PATH),
		 20) {
  text.setFillColor(sf::Color::White);
  text.setOutlineColor(sf::Color(47, 60, 76, 255));
  text.setOutlineThickness(1.5f);

  normalTexture.setRepeated(true);
  sprite.setTexture(normalTexture);
  Utils::centerOrigin(sprite);
}

void Button::onEnter() {
  isSelected = true;
  sprite.setTexture(selectedTexture);
  Utils::centerOrigin(sprite);
  sprite.setScale(1.2, 1.2);
  Utils::centerOrigin(text);
  text.setScale(1.2, 1.2);
}

void Button::onLeave() {
  isSelected = false;
  sprite.setTexture(normalTexture);
  sprite.setScale(1, 1);
  text.setScale(1, 1);
  Utils::centerOrigin(sprite);
  sprite.setScale(1, 1);

  Utils::centerOrigin(text);
  text.setScale(1, 1);
}

void Button::activate() {
  isActive = true;
  if (activateFunction)
	activateFunction(*this);
}

void Button::deactivate() {
  isActive = false;
  if (deactivateFunction)
	deactivateFunction(*this);
}

void Button::setSize(int width, int height) {
  sprite.setTextureRect(sf::IntRect(0, 0, width, height));
  Utils::centerOrigin(sprite);
}

void Button::setDeactiveFunction(std::function<void(Button &)> onDeactivate) {
  deactivateFunction = std::move(onDeactivate);
}

void Button::setActiveFunction(std::function<void(Button &)> onActivate) {
  activateFunction = onActivate;
}

void Button::setPositionBelow(const Button &btn, float padding) {
  const sf::Vector2f pos(btn.getPosition().x, btn.getPosition().y);

  sf::Vector2f offset(0, btn.getGlobalBounds().height);

  padding *= getScale().y;
  offset *= getScale().y;
  setPosition(pos + offset + sf::Vector2f(0, padding));
}



void Button::setText(const std::string &_text) {
  text.setString(_text);
  Utils::centerOrigin(text);
}

sf::FloatRect Button::getGlobalBounds() const {
  auto globalBounds = sprite.getGlobalBounds();
  globalBounds.left += getPosition().x;
  globalBounds.top += getPosition().y;

  return globalBounds;
}

sf::FloatRect Button::getLocalBounds() const {
  return sprite.getLocalBounds();
}

void Button::matchSizeToText(float padding) {
  sprite.setTextureRect(sf::IntRect(0, 0,
									text.getLocalBounds().width * text.getScale().x + padding,
									text.getLocalBounds().height * text.getScale().y + padding));
  Utils::centerOrigin(sprite);
}

void Button::handleEvents(const sf::Event &event) {
  if (event.type == sf::Event::MouseButtonReleased && isSelected) {
	if (event.mouseButton.button == sf::Mouse::Left)
	  activate();
	if (event.mouseButton.button == sf::Mouse::Right)
	  deactivate();
  }
}

void Button::update(sf::Vector2f mousePosition) {
  // If mouse has left the button
  if (isSelected && !getGlobalBounds().contains(mousePosition))
	onLeave();

  // If mouse has entered the button
  if (!isSelected && getGlobalBounds().contains(mousePosition))
	onEnter();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(sprite, states);
  target.draw(text, states);
}