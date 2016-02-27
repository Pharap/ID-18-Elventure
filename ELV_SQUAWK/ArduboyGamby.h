#ifndef ArduboyGamby_h
#define ArduboyGamby_h

#include "Arglib.h"
#include <inttypes.h>

#define GAMBY_ICON_HEIGHT 8
#define GAMBY_PAGE_HEIGHT 8

// Inputs
#define DPAD_UP     UP_BUTTON
#define DPAD_LEFT   LEFT_BUTTON
#define DPAD_RIGHT    RIGHT_BUTTON
#define DPAD_DOWN   DOWN_BUTTON
#define DPAD_UP_LEFT            DPAD_UP | DPAD_LEFT
#define DPAD_UP_RIGHT           DPAD_UP | DPAD_RIGHT
#define DPAD_DOWN_LEFT          DPAD_DOWN | DPAD_LEFT
#define DPAD_DOWN_RIGHT         DPAD_DOWN | DPAD_RIGHT
#define DPAD_ANY    DPAD_UP | DPAD_DOWN | DPAD_RIGHT | DPAD_LEFT
#define BUTTON_1    B_BUTTON
#define BUTTON_2    A_BUTTON
#define BUTTON_3    B_BUTTON
#define BUTTON_4    A_BUTTON
#define BUTTON_ANY    BUTTON_1 | BUTTON_2 | BUTTON_3 | BUTTON_4

class GambyGraphicsMode {
public:
  GambyGraphicsMode(Arduboy &arduboy);

  void clearScreen();
  void update();

  void readInputs();

  void setPos(byte, byte);

  static byte column_pos, page_pos;

  void drawSprite(byte x, byte y, byte w, byte h, const byte *);
  void drawSprite(byte, byte, const byte *);
  void drawSprite(byte, byte, const byte *, const byte *);
  void drawSprite(byte, byte, const byte *, byte);
  void drawSprite(byte, byte, const byte *, byte, const byte *, byte);

  void drawIcon(byte w, const byte *);
  void drawIcon(const byte *);
  void drawIcon(const byte *, byte);
  void drawIcon(const byte *, byte, byte);

  static byte inputs;            /**< The D-Pad and button states. Set by readInputs(). */

private:

  Arduboy *arduboy;
};

#endif
