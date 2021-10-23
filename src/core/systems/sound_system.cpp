//
// Created by yacopsae on 20/10/2021.
//

#include "sound_system.hpp"

#include "engine.hpp"

SoundSystem::SoundSystem() = default;

void SoundSystem::onInit() {
  eventDispatcher->sink<SoundEvent::MusicStart>().connect<&SoundSystem::playSound>(this);
}
void SoundSystem::playSound(const SoundEvent::MusicStart &event) {
  engine->getMusicPlayer().play(event.musicPath);
}