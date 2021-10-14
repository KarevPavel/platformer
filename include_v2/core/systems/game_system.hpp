//
// Created by yacopsae on 14/10/2021.
//

#pragma once

#include <base_system.hpp>
#include <game_events.hpp>
#include <tmxlite/Tileset.hpp>
#include <tmxlite/TileLayer.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <map>

// TODO: ВООБЩЕ НАФИГ ВСЁ НЕПРАВИЛЬНО!!!!

class GameSystem: public BaseSystem {

  void onInit() override;

 public:
  GameSystem();

  void receiveGameStart(const GameEvent::GameStart &event);
  bool LoadFromFile(const std::string &filepath);
  std::vector<tmx::Tileset> usedTiles(const std::vector<tmx::Tileset> &tileSets,
									  const std::vector<tmx::TileLayer::Tile> &tiles);
  sf::Texture textureFromImage(const std::string &imagePath);
  void loadAndSaveTextures(const std::vector<tmx::Tileset> &usedTileSets);

 private:
  std::map<std::string , std::unique_ptr<sf::Texture>> textureResource_2;
  std::map<std::pair<std::uint32_t, std::uint32_t>, std::unique_ptr<tmx::Tileset>> textureResource_test;
  std::vector<sf::Sprite*> spriteList;

  void update(float dt) override;
};


