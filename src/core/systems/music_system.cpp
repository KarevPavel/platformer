//
// Created by yacopsae on 12/10/2021.
//

#include "music_system.hpp"
#include "engine.hpp"

MusicSystem::MusicSystem() = default;

void MusicSystem::onInit() {
  eventDispatcher->sink<SoundEvent::MusicStart>().connect<&MusicSystem::receiveMusicStart>(this);
  eventDispatcher->sink<SoundEvent::MusicStop>().connect<&MusicSystem::receiveMusicStop>(this);
}
void MusicSystem::receiveMusicStart(const SoundEvent::MusicStart &event) {
  engine->getMusicPlayer().play(event.musicPath);
}
void MusicSystem::receiveMusicStop(const SoundEvent::MusicStop &event) {
  engine->getMusicPlayer().stop();
}