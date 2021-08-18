#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class level1 {
private:
    sf::RenderWindow &window;

    std::vector<sf::RectangleShape> shapeVector;

    sf::RectangleShape generateRestangle() {
        sf::RectangleShape restangle{
                {
                        (float) (rand() % (80 - 10 + 1) + 10),
                        (float) (rand() % (80 - 10 + 1) + 10)
                }
        };
        restangle.setFillColor(sf::Color::Magenta);
        restangle.setPosition((rand() % (1000 - 10 + 1) + 10), (rand() % (1000 - 10 + 1) + 10));
        return restangle;
    }

public:
    explicit level1(sf::RenderWindow &window) : window(window) {
//        for (int i = 0; i < 40; i++) {
//            auto restangle = generateRestangle();
//            shapeVector.push_back(restangle);
//        }
    }

    void drawMe() {
        for (auto &shape : shapeVector) {
            window.draw(shape);
        }
    }

    /**
     * return true if
     * @param xy
     * @return
     */
    bool hasCollision(sf::Rect<float> xy) {
        bool result = false;
        for (auto &shape : shapeVector) {
            shape.setFillColor(sf::Color::Magenta);

            if (shape.getGlobalBounds().intersects(xy)) {
                shape.setFillColor(sf::Color::Red);
                result = true;
            }
        }
        return result;
    }
};
