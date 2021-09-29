//
// Created by yacopsae on 29/09/2021.
//

#include "fixed_container.hpp"

FixedContainer::FixedContainer(sf::RenderWindow &window) :
	Container(window) {

}

void FixedContainer::store(std::unique_ptr<Component> component) {
  pinnedComponents.push_back(std::move(component));
}

void FixedContainer::update() {
  const auto mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

  for (auto &pinnedComponent : pinnedComponents)
	pinnedComponent->update(mousePosition);

  const auto leftUppercorner = window.mapPixelToCoords({0, 0});
  setPosition(leftUppercorner);

  viewScale.x = window.getView().getSize().x / window.getDefaultView().getSize().x;
  viewScale.y = window.getView().getSize().y / window.getDefaultView().getSize().y;
  setScale(viewScale);
}

void FixedContainer::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();

  for (const auto &pinnedComponent : pinnedComponents)
	target.draw(*pinnedComponent, states);
}

