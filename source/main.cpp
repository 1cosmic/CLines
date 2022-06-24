#include <SDL2/SDL_stdinc.h>
#include <SDL2/SDL_timer.h>

#include <iostream>
#include <stdio.h>
#include <vector>

#include <SDL2/SDL.h>

#include "headers/gui.h"

#include "headers/logic.h"

using namespace std;

int main(void) {
  // Initialization SDL.

  SDL_Event event;                // key-input users.
  const Uint32 FPS = 1000 / 30;   // FPS.
  Uint32 _FPS_Timer;              // for control of frame rate.

  bool quit = false;              // game was close? (main circle).


  vector<star> curStars(3);    // for less backend (field.cpp) & GUI (gui.cpp).

  // Initialize SDL2.
  initCLines();

  // Load textures, draw grid & start play!
  startGame();

  // Initialization back-end field.
  initField();

  // Main circle.
  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {

      // Main case of type user-event.
      switch (event.type) {

        // If game was close, terminate all process & run grub cleaner.
        case SDL_QUIT:
          quit = true;
          break;

        // If u-i = press key:
        case SDL_KEYDOWN:
          switch (event.key.keysym.sym) {

            // If space - generate random star. (DEV FUNC).
            case SDLK_SPACE:

              // Check free space in backend field.
              checkFreeSpace();

              // Generate list of random color.
              randomColors();

              // Insert this colors in backend field.
              randomPutStar();

              // Display star of screen.
              displayStars();

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

