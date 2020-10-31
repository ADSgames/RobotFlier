/**
 * DefaultAudioService
 * Allan Legemaate
 * Implementation of audio service
 * 30/10/2020
 **/

#ifndef ENGINE_AUDIO_DEFAULT_AUDIO_SERVICE_H
#define ENGINE_AUDIO_DEFAULT_AUDIO_SERVICE_H

#include <string>

#include "AudioService.h"
#include "Sound.h"
#include "Stream.h"

class DefaultAudioService : public AudioService {
 public:
  // Play audio
  void playSound(const std::string& key, const PlaySoundConfig& config);

  // Stop sound
  void stopSound(const std::string& key);

  // Play stream
  void playStream(const std::string key, const bool loop = false);

  // Stop stream
  void stopStream(const std::string& key);
};

#endif  // ENGINE_AUDIO_DEFAULT_AUDIO_SERVICE_H