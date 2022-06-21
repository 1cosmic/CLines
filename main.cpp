#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

#include <iostream>
#include <stdio.h>
#include <vector>

#include <SDL2/SDL.h>

#include "headers/gui.h"
#include "headers/logic.h"
#include "headers/u_input.h"

using namespace std;

int main(void) {
  // Initialization SDL.

  SDL_Event event;
  const Uint32 FPS = 1000 / 30;
  Uint32 _FPS_Timer;

  bool quit = false;

  initCLines();

  startGame();

  // YOU MAIN LOGIC GAME PUT IN HERE.
  initField(); // Initialization back-end field.

  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {

      switch (event.type) {

      case SDL_QUIT:
        quit = true;
        break;

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {

        case SDLK_SPACE:

          // Check free space in backend field.
          checkFreeSpace();

          // Generate list of random color.
          randomColors();

          // Insert this colors in backend field.
          randomPutStar();

          // Display star of screen.
          displayStars(star);
        }
      }
    }

    // Frame Rate controls.
    if (SDL_GetTicks() - _FPS_Timer < FPS) {
      SDL_Delay(FPS - SDL_GetTicks() + _FPS_Timer);
    }
    _FPS_Timer = SDL_GetTicks();
  }

  // Close game. Destroy main window & others.
  close();

  // full check of back-end.
  // srand(time(NULL));
  // while (checkFreeSpace()) {
  //   randomColors();
  //   randomPutStar();
  //   ++counter;
  // }
  // searchLines(2);

  /* std::cout << counter << std::endl; */
  // printField();

  return 0;
}
