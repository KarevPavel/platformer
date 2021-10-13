//
// Created by yacopsae on 12/10/2021.
//

#include "sound_system.hpp"
#include "engine.hpp"

SoundSystem::SoundSystem() = default;

void SoundSystem::onInit() {
  eventDispatcher->sink<GameEvent::MusicStart>().connect<&SoundSystem::receiveMusicStart>(this);
  eventDispatcher->sink<GameEvent::MusicStop>().connect<&SoundSystem::receiveMusicStop>(this);
}
void SoundSystem::receiveMusicStart(const GameEvent::MusicStart & event) {
  	engine->getMusicPlayer().play(event.musicPath);
}
void SoundSystem::receiveMusicStop(const GameEvent::MusicStop &event) {
  engine->getMusicPlayer().stop();
}