//
// Created by yacopsae on 23/09/2021.
//

#include <textures.hpp>
#include "SFML/Graphics/RenderTarget.hpp"

#include "resource_manager.hpp"
#include "button.hpp"
#include "fonts.hpp"

void Button::onEnter() {
  Component::onEnter();

  // Changes the texture to a different one (set) when hovering
  sprite.setTexture(selectedTexture);

  /*// Increases the button size accordingly when hovered over
  centerOrigin(sprite);
  sprite.setScale(1.2, 1.2);

  centerOrigin(text);
  text.setScale(1.2, 1.2);
   */
}

void Button::onLeave() {
  Component::onLeave();

  sprite.setTexture(normalTexture);

  // Decreases the button size (to the default scale) after leaving
  /*centerOrigin(sprite);
  sprite.setScale(1, 1);

  centerOrigin(text);
  text.setScale(1, 1);*/
}

void Button::activate() {
  Component::activate();

  if (activateFunction)
	activateFunction(*this);
}

void Button::deactivate() {
  Component::deactivate();

  if (deactivateFunction)
	deactivateFunction(*this);
}

void Button::setSize(int width, int height) {
  sprite.setTextureRect(sf::IntRect(0, 0, width, height));
  //centerOrigin(sprite);
}

Button::Button(TextureManager &textures, FontManager &fonts) :
	Component(),
	normalTexture(textures.getResourceRef(constants::BLACK_PATH)),
	selectedTexture(textures.getResourceRef(constants::BLACK_PATH)),
	text("", fonts.getResourceRef(constants::LIBERATIONMONO_BOLD_PATH),
		 20) {

  text.setFillColor(sf::Color::White);
  text.setOutlineColor(sf::Color(47, 60, 76, 255));
  text.setOutlineThickness(1.5f);

  sprite.setTexture(normalTexture);
  //centerOrigin(sprite);
}

void Button::setActiveFunction(std::function<void(Button &)> onActivate) {
  activateFunction = std::move(onActivate);
}

void Button::setDeactiveFunction(std::function<void(Button &)> onDeactivate) {
  deactivateFunction = std::move(onDeactivate);
}

void Button::setText(const std::string &_text) {
  text.setString(_text);
  //centerOrigin(text);
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
  //centerOrigin(sprite);
}

void Button::handleEvents(const sf::Event &event) {
  if (event.type == sf::Event::MouseButtonPressed && isSelected()) {
	if (event.mouseButton.button == sf::Mouse::Left)
	  activate();
	if (event.mouseButton.button == sf::Mouse::Right)
	  deactivate();
  }
}

void Button::update(sf::Vector2f mousePosition) {
  // If mouse has left the button
  if (isSelected() && !getGlobalBounds().contains(mousePosition))
	onLeave();

  // If mouse has entered the button
  if (!isSelected() && getGlobalBounds().contains(mousePosition))
	onEnter();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();
  target.draw(sprite, states);
  target.draw(text, states);
}
