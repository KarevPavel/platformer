//
// Created by yacopsae on 29/09/2021.
//

#include "container.hpp"

Container::Container(const sf::RenderWindow &window) :
	window(window) {
}

void Container::store(std::unique_ptr<Component> component) {
  pinnedComponents.push_back(std::move(component));
}

bool Container::isEmpty() const noexcept {
  return pinnedComponents.empty();
}

Component &Container::front() {
  return *pinnedComponents.front();
}

Component &Container::back() {
  return *pinnedComponents.back();
}

void Container::handleEvents(const sf::Event &event) {
  if (clearRequest) {
	pinnedComponents.clear();
	clearRequest = false;
  }

  for (auto &pinnedComponent : pinnedComponents)
	pinnedComponent->handleEvents(event);
}

void Container::update() {
  const auto mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

  for (auto &pinnedComponent : pinnedComponents)
	pinnedComponent->update(mousePosition);
}

void Container::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();

  for (const auto &pinnedComponent : pinnedComponents)
	target.draw(*pinnedComponent, states);
}

void Container::requestClear() noexcept {
  clearRequest = true;
}
