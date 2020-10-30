#include "Energy.h"

#include "../constants/globals.h"
#include "../engine/Core.h"
#include "../helpers/tools.h"
#include "Robot.h"

// Constructor
Energy::Energy(Scene* scene, const int x, const int y)
    : GameObject(scene, x, y) {
  loadAssets();
}

void Energy::loadAssets() {
  if (Engine::settings.get<bool>("christmas", false)) {
    setTexture("energy_christmas");
  } else {
    setTexture("energy");
  }

  sound_orb = Engine::asset_manager.getAudio("orb");
}

void Energy::onCollide(const GameObject& other) {
  try {
    auto robot = dynamic_cast<const Robot&>(other);
    robot.addHealth(1);

    score += 5;
    stats[STAT_ENERGY] += 1;

    if (robot.getHealth() < 100) {
      robot.addHealth(1);
    }

    sound_orb.play();

    isDead = true;
  } catch (...) {
    // Nope!
  }
}

// Game logic
void Energy::update() {
  x -= motion;
}

// Move towards robot
void Energy::moveTowards(const float x, const float y, const float speed) {
  this->x += (speed * (x - this->x)) / 20000;
  this->y += (speed * (y - this->y)) / 20000;
}
