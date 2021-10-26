//
// Created by yacopsae on 26/10/2021.
//

#pragma once

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
template <typename Component>
class DrawableContainer : public sf::Transformable, public sf::Drawable {
 public:
  explicit DrawableContainer(const sf::RenderWindow &window);

  virtual void store(std::unique_ptr<Component> component);

  bool isEmpty() const noexcept;

  Component &front();

  Component &back();

  void handleEvents(const sf::Event &event);

  void update();

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void requestClear() noexcept;

 protected:
  std::vector<std::unique_ptr<Component>> pinnedComponents;
  const sf::RenderWindow &window;
  bool clearRequest = false;

};

template <typename Component>
inline DrawableContainer<Component>::DrawableContainer(const sf::RenderWindow &window) :
	window(window) {
}

template <typename Component>
inline void DrawableContainer<Component>::store(std::unique_ptr<Component> component) {
  pinnedComponents.push_back(std::move(component));
}

template <typename Component>
inline bool DrawableContainer<Component>::isEmpty() const noexcept {
  return pinnedComponents.empty();
}

template <typename Component>
inline Component &DrawableContainer<Component>::front() {
  return *pinnedComponents.front();
}

template <typename Component>
inline Component &DrawableContainer<Component>::back() {
  return *pinnedComponents.back();
}

template <typename Component>
inline void DrawableContainer<Component>::handleEvents(const sf::Event &event) {
  if (clearRequest) {
	pinnedComponents.clear();
	clearRequest = false;
  }

  for (auto &pinnedComponent : pinnedComponents)
	pinnedComponent->handleEvents(event);
}

template <typename Component>
inline void DrawableContainer<Component>::update() {
  const auto mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

  for (auto &pinnedComponent : pinnedComponents)
	pinnedComponent->update(mousePosition);
}

template <typename Component>
inline void DrawableContainer<Component>::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  states.transform *= getTransform();

  for (const auto &pinnedComponent : pinnedComponents)
	target.draw(*pinnedComponent, states);
}

template <typename Component>
inline void DrawableContainer<Component>::requestClear() noexcept {
  clearRequest = true;
}


