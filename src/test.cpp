//
// Created by yacopsae on 16/10/2020.
//
#include <SFML/Graphics.hpp>

/*

struct Frame {
    sf::IntRect rect;
    double duration; // in seconds
};

class Animation {
    std::vector<Frame> frames;
    double totalLength;
    double totalProgress;
    sf::Sprite *target;

public:
    Animation(sf::Sprite &target) {
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
        for (auto & frame : frames) {
            progress -= (frame).duration;

            if (progress <= 0.0 || &(frame) == &frames.back()) {
                target->setTextureRect((frame).rect);
                break; // we found our frame
            }
        }
    }
};*/
