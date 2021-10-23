//
// Created by yacopsae on 23/09/2021.
//

#include "music_player.hpp"

MusicPlayer::MusicPlayer() :
	music(),
	volume(4) {

}

void MusicPlayer::play(const std::string &musicPath) {
  if (music.openFromFile(musicPath)) {
	music.setVolume(volume);
	music.setLoop(true);
	current_music = musicPath;
	music.play();
  }
}

void MusicPlayer::setPaused(bool paused) {
  if (paused)
	music.pause();
  else
	music.play();
}

void MusicPlayer::stop() {
  music.stop();
}

void MusicPlayer::setVolume(float volume) {
  music.setVolume(volume);
}

std::string MusicPlayer::getCurrentMusic() const noexcept {
  return current_music;
}

void MusicPlayer::reset() {
  if (!current_music.empty()) {
	music.setPlayingOffset(sf::Time::Zero);
  }
}
