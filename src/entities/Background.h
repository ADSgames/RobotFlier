/*
 * Background
 * Allan Legemaate
 * Renders game background
 * 12/08/2020
 */
#ifndef ENTITIES_BACKGROUND_H
#define ENTITIES_BACKGROUND_H

#include <afk/entities/GameObject.h>
#include <afk/scene/Scene.h>
#include <afk/textures/Texture.h>

class Background : public GameObject {
 public:
  // Constructor
  explicit Background(Scene& scene);

  // Logic override
  virtual void update() override;

  // Draw
  virtual void draw() override;

 private:
  // Change theme
  void changeTheme(const int theme);

  // Textures
  Texture space;
  Texture parallaxBack;
  Texture groundOverlay;
  Texture groundUnderlay;

  // Position
  int scroll;
};

#endif  // ENTITIES_BACKGROUND_H
