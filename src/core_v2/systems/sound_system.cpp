//
// Created by yacopsae on 12/10/2021.
//

#include "sound_system.hpp"
#include "engine.hpp"

SoundSystem::SoundSystem() = default;

void SoundSystem::onInit() {
  eventDispatcher->sink<SoundEvent::MusicStart>().connect<&SoundSystem::receiveMusicStart>(this);
  eventDispatcher->sink<SoundEvent::MusicStop>().connect<&SoundSystem::receiveMusicStop>(this);
}
void SoundSystem::receiveMusicStart(const SoundEvent::MusicStart & event) {
  	engine->getMusicPlayer().play(event.musicPath);
}
void SoundSystem::receiveMusicStop(const SoundEvent::MusicStop &event) {
  engine->getMusicPlayer().stop();
}