/*
  Elventure: http://www.team-arg.org/elv-manual.html

  Arduboy version 0.1:  http://www.team-arg.org/elv-downloads.html

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2011 - TRODOSS originaly coded for Arduino/Video Game Shield
  2013 - TRODOSS coded for the Gamby Game Shield
  2016 - ... art by CASTPIXEL

  License: MIT : https://opensource.org/licenses/MIT

*/

#include <Arduboy.h>
#include <ArduboyExtra.h>
#include <sprites.h>
#include <simple_buttons.h>
#include "menu.h"
#include "game.h"
#include "inputs.h"


//determine the game
#define GAME_ID 37

Arduboy arduboy;

typedef void (*FunctionPointer) ();
FunctionPointer mainGameLoop[] = {
  stateMenuIntro,
  stateMenuMain,
  stateMenuHelp,
  stateMenuPlay,
  stateMenuInfo,
  stateMenuSoundfx,
  stateGamePlaying,
};

byte gameState;

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  gameState = STATE_MENU_INTRO;
  if (EEPROM.read(EEPROM_AUDIO_ON_OFF)) soundYesNo = true;
  menuSelection = STATE_MENU_PLAY;
}

void loop()
{
  if (!(arduboy.nextFrame())) return;
  buttons.poll();
  if (soundYesNo == true) arduboy.audio.on();
  else arduboy.audio.off();
  arduboy.clearDisplay();
  mainGameLoop[gameState]();
  arduboy.display();
}

