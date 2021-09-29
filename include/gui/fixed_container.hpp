#pragma once

#include "container.hpp"

class FixedContainer : public Container {

 public:
  explicit FixedContainer(sf::RenderWindow &window);

  /**
   * \brief Adds a component to the container
   * \param component Component to add
   */
  void store(std::unique_ptr<Component> component) override;

  /**
   * \brief Updates the logic/status of all components inside the container
   */
  void update();

  /**
   * \brief Draws all components inside the container to the passed target
   * \param target where it should be drawn to
   * \param states provides information about rendering process (transform, shader, blend mode)
   */
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

 private:
  sf::Vector2f viewScale; //!< Current view scale
};
