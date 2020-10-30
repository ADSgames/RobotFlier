#include "Bomb.h"

#include "../../engine/Core.h"

// Constructor
Bomb::Bomb(const Scene& scene, const int x, const int y)
    : Debris(scene, x, y, 10, 1.0f, 0.01f) {
  destroy_sound = Engine::asset_manager.getAudio("bomb");

  if (Engine::settings.get<bool>("christmas", false)) {
    setTexture("bomb_christmas");
  } else {
    setTexture("bomb");
  }
}

void Bomb::onDestroy() {
  // Play sound
  destroy_sound.play();
}