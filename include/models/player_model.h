//
// Created by yacopsae on 14/10/2020.
//
#pragma once

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class PlayerModel {

public:

    explicit PlayerModel(sf::RenderWindow &window) : window(window) {}
    void idle();
    void walk(float elapsed);
    void draw();
    void clear();
    static void moveLeftLegFront(PlayerModel *model);
    static void moveLeftLegBack(PlayerModel *model);
    static void moveRightLegFront(PlayerModel *model);
    static void moveRightLegBack(PlayerModel *model);

private:
    sf::RenderWindow &window;
    sf::Vector2f currentPosition{200, 200};
    sf::CircleShape head{10};
    sf::RectangleShape body{sf::Vector2f(20, 40)};
    sf::RectangleShape rleg{sf::Vector2f(6, 35)};
    sf::RectangleShape lleg{sf::Vector2f(6, 35)};
    sf::RectangleShape rhand{sf::Vector2f(6, 35)};
    sf::RectangleShape lhand{sf::Vector2f(6, 35)};
};



typedef void (*GEngineFn)(PlayerModel *model);

struct Frame {
    GEngineFn move;
    double duration; // in seconds
};

class Animation {
    std::vector<Frame> frames;
    double totalLength;
    double totalProgress;
    PlayerModel *target;

public:
    Animation(PlayerModel &target) {
        this->target = &target;
        totalProgress = 0.0;
    }

    void addFrame(Frame &&frame) {
        frames.push_back(frame);
        totalLength += frame.duration;
    }

    void update(double elapsed) {
        totalProgress += elapsed;
        double progress = totalProgress;
        for (auto &frame : frames) {
            progress -= (frame).duration;

            if (progress <= 0.0 || &(frame) == &frames.back()) {
                target->clear();
                frame.move(target);
                target->draw();
                break; // we found our frame
            }
        }
    }
};
