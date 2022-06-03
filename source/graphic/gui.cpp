#include "draw.cpp"

#include <SDL2/SDL.h>

#include <experimental/filesystem>

#include <exception>
#include <iostream>

#define SCR_W 1280
#define SCR_H 720

using namespace std;

SDL_Window *window = NULL;       // Main window of the window window
SDL_Renderer *render = NULL;     // Renderer of the drawing.
SDL_Surface *mainSurface = NULL; // Surface contained by the window.

bool initCLines(void) {
  // Initialization chesks.

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize. Error: %s\n", SDL_GetError());

    exit(1);

  } else {

    // Create main window:
    SDL_CreateWindowAndRenderer(SCR_W, SCR_H, 0, &window, &render);

    if (window == NULL) {
      printf("Main window could not be created. Error: %s\n", SDL_GetError());

      exit(1);

    } else
      // Create window Surface:
      mainSurface = SDL_GetWindowSurface(window);
  }

  return true;
}

bool showHello(void) {
  // Set up default option of main screen & window.

  SDL_Surface *background;

  char dir_bkgd[] = "background.bmp";

  background = SDL_LoadBMP(dir_bkgd);
  SDL_BlitSurface(background, NULL, mainSurface, NULL);
  SDL_UpdateWindowSurface(window);

  ///
  ///
  ///

  SDL_RenderClear(render); // clear render (nahui?..)

  SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);

  draw_grid(render, 200, 200, 60);

  SDL_Delay(3000);
  SDL_FreeSurface(background);

  return true;
}

void close(void) {
  // Destroy all objects & close window.

  try {
    if (window)
      SDL_DestroyWindow(window); // Destroy window.
    if (render)
      SDL_DestroyRenderer(render); // Destroy renderer.
    if (mainSurface)
      SDL_FreeSurface(mainSurface); // Destroy main (window) surface.

    cout << "All surface & windows was closed." << endl;
  }

  catch (exception &e) {
    cout << "Coudn`t close window. Error: " << e.what() << endl;
  }
}
