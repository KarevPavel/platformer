#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include "SFML/Graphics/Drawable.hpp"

#include "component.hpp"

class Container : public sf::Transformable, public sf::Drawable {
 public:
  explicit Container(const sf::RenderWindow &window);

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


