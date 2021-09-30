//
// Created by yacopsae on 23/09/2021.
//

#include "music_player.hpp"

MusicPlayer::MusicPlayer() :
	_music(),
	_volume(100)
	{

}

void MusicPlayer::play(const std::string& musicPath) {
	if (_music.openFromFile(musicPath)) {
	  _music.setVolume(_volume);
	  _music.setLoop(true);
	  _current_music = musicPath;
	  _music.play();
	}
}

void MusicPlayer::setPaused(bool paused) {
  if (paused)
	_music.pause();
  else
	_music.play();
}

void MusicPlayer::stop() {
  _music.stop();
}

void MusicPlayer::setVolume(float volume) {
  _music.setVolume(volume);
}

std::string MusicPlayer::getCurrentMusic() const noexcept {
  return _current_music;
}

void MusicPlayer::reset() {
  if (!_current_music.empty()) {
	_music.setPlayingOffset(sf::Time::Zero);
  }
}
