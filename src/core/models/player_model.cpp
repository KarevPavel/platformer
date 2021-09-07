#include <player_model.h>
#include <SFML/Graphics.hpp>

void PlayerModel::idle() {
  head.setPosition(currentPosition.x, currentPosition.y);
  body.setPosition(currentPosition.x, currentPosition.y + (head.getRadius() * 2));
  lhand.setPosition(currentPosition.x - lhand.getSize().x, currentPosition.y + head.getRadius() * 2);
  rhand.setPosition(currentPosition.x + body.getSize().x, currentPosition.y + head.getRadius() * 2);
  rleg.setPosition(currentPosition.x + body.getSize().x - rleg.getSize().x,
				   currentPosition.y + body.getSize().y + head.getRadius() * 2);
  lleg.setPosition(currentPosition.x, currentPosition.y + body.getSize().y + head.getRadius() * 2);

  window.draw(head);
  window.draw(body);
  window.draw(rhand);
  window.draw(lhand);
  window.draw(rleg);
  window.draw(lleg);
}

void PlayerModel::draw() {
  head.setPosition(currentPosition.x, currentPosition.y);
  body.setPosition(currentPosition.x, currentPosition.y + (head.getRadius() * 2));
  lhand.setPosition(currentPosition.x - lhand.getSize().x, currentPosition.y + head.getRadius() * 2);
  rhand.setPosition(currentPosition.x + body.getSize().x, currentPosition.y + head.getRadius() * 2);
  rleg.setPosition(currentPosition.x + body.getSize().x - rleg.getSize().x,
				   currentPosition.y + body.getSize().y + head.getRadius() * 2);
  lleg.setPosition(currentPosition.x, currentPosition.y + body.getSize().y + head.getRadius() * 2);

  window.draw(head);
  window.draw(body);
  window.draw(rhand);
  window.draw(lhand);
  window.draw(rleg);
  window.draw(lleg);
}

void PlayerModel::clear() {
  this->window.clear();
}

void PlayerModel::moveLeftLegFront(PlayerModel *model) {
  model->rleg.rotate(5);
}

void PlayerModel::moveLeftLegBack(PlayerModel *model) {
  model->rleg.rotate(-5);
}

void PlayerModel::moveRightLegFront(PlayerModel *model) {
  model->rleg.rotate(5);
}

void PlayerModel::moveRightLegBack(PlayerModel *model) {
  model->rleg.rotate(-5);
}

void PlayerModel::walk(float elapsed) {

  Animation animation = Animation{*this};
  animation.addFrame({moveLeftLegFront, 0.4});
  animation.addFrame({moveRightLegBack, 0.4});
  animation.addFrame({moveLeftLegBack, 0.4});
  animation.addFrame({moveRightLegFront, 0.4});
  animation.update(elapsed);
}
