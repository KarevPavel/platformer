#include <player_model.h>
#include <SFML/Graphics.hpp>

void player_model::idle() {
    head.setPosition(currentPosition.x, currentPosition.y);
    body.setPosition(currentPosition.x, currentPosition.y + (head.getRadius() * 2));
    lhand.setPosition(currentPosition.x - lhand.getSize().x, currentPosition.y + head.getRadius() * 2);
    rhand.setPosition(currentPosition.x + body.getSize().x, currentPosition.y + head.getRadius() * 2);
    rleg.setPosition(currentPosition.x + body.getSize().x - rleg.getSize().x, currentPosition.y + body.getSize().y + head.getRadius() * 2);
    lleg.setPosition(currentPosition.x, currentPosition.y + body.getSize().y + head.getRadius() * 2);

    window.draw(head);
    window.draw(body);
    window.draw(rhand);
    window.draw(lhand);
    window.draw(rleg);
    window.draw(lleg);
}

void player_model::draw(){
    head.setPosition(currentPosition.x, currentPosition.y);
    body.setPosition(currentPosition.x, currentPosition.y + (head.getRadius() * 2));
    lhand.setPosition(currentPosition.x - lhand.getSize().x, currentPosition.y + head.getRadius() * 2);
    rhand.setPosition(currentPosition.x + body.getSize().x, currentPosition.y + head.getRadius() * 2);
    rleg.setPosition(currentPosition.x + body.getSize().x - rleg.getSize().x, currentPosition.y + body.getSize().y + head.getRadius() * 2);
    lleg.setPosition(currentPosition.x, currentPosition.y + body.getSize().y + head.getRadius() * 2);

    window.draw(head);
    window.draw(body);
    window.draw(rhand);
    window.draw(lhand);
    window.draw(rleg);
    window.draw(lleg);
}

void player_model::clear(){
    this->window.clear();
}

void player_model::moveLeftLegFront(player_model *model) {
    model->rleg.rotate(5);
}

void player_model::moveLeftLegBack(player_model *model) {
    model->rleg.rotate(-5);
}

void player_model::moveRightLegFront(player_model *model){
    model->rleg.rotate(5);
}

void player_model::moveRightLegBack(player_model *model){
    model->rleg.rotate(-5);
}

void player_model::walk(float elapsed) {

    Animation animation = Animation{*this};
    animation.addFrame({ moveLeftLegFront, 0.4 });
    animation.addFrame({ moveRightLegBack, 0.4 });
    animation.addFrame({ moveLeftLegBack, 0.4 });
    animation.addFrame({ moveRightLegFront, 0.4 });
    animation.update(elapsed);
}
