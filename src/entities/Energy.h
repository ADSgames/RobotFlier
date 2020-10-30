/*
 * Energy
 * Gives the player health
 * A.D.S. Games
 */
#ifndef ENTITIES_ENERGY_H
#define ENTITIES_ENERGY_H

#include "../engine/audio/Sound.h"
#include "GameObject.h"

class Energy : public GameObject {
 public:
  // Constructor
  Energy(Scene* scene, const int x, const int y);

  // Logic override
  virtual void update() override;

  // Move towards point
  void moveTowards(const float x, const float y, const float speed);

  void onCollide(const GameObject& other) override;

 private:
  // Load assets
  void loadAssets();

  // Sound effect
  Sound sound_orb;
};

#endif  // ENTITIES_ENERGY_H
