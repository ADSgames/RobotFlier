/**
 * UIHandler
 * Danny Van Stemp and Allan Legemaate
 * Manages UI
 * 24/09/2017
 **/

#ifndef ENGINE_UI_UIHANDLER_H
#define ENGINE_UI_UIHANDLER_H

#include <string>
#include <vector>

#include "UIElement.h"

class UIHandler {
 public:
  UIHandler();
  virtual ~UIHandler();
  void addElement(UIElement* newUIElement);
  void draw();
  void update();
  bool isHovering();

  void createButton(const int x,
                    const int y,
                    std::string text,
                    std::string id,
                    ALLEGRO_FONT* font);
  void createAnchoredButton(std::string text,
                            ALLEGRO_FONT* font,
                            std::string anchorID,
                            std::string id);

  UIElement* getElementById(std::string id);

  std::vector<UIElement*> getUIElements();

 private:
  // Container for UI Elements
  std::vector<UIElement*> ui_elements;

  // Cursor image
  ALLEGRO_BITMAP* ui_cursor;

  // Element in focus
  int focusedElement;
};

#endif  // ENGINE_UI_UIHANDLER_H
