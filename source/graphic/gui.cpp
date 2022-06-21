#include "backend.cpp"
#include "draw.cpp"

#include <SDL2/SDL.h>

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <exception>
#include <iostream>
#include <vector>

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

      mainSurface = SDL_GetWindowSurface(window);
  }

  return true;
}

bool startGame(void) {
  // Set up default option of main screen & window.

  // Initialization star images from system.
  initTexture(render);     // load & convert to texture.
  initRects();             // create rect for render this texture.
  SDL_RenderClear(render); // clear render (nahui?..)
  SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);

  SDL_RenderCopy(render, tx_bgd, NULL, &Rect_backbround);

  draw_grid(render, 60); // draw grid.

  // SDL_RenderPresent(render);

  return true;
}

void displayStars(vector<int[3]> *stars) {
  // Put stars in field.

  vector<int[3]>::iterator star;

  // For star in stars[] do -> draw.
  for (star = stars->begin(); star != stars->end(); ++star) {

    draw_stars(render, star[1], star[2], tx_star[star[3]]);
    cout << "Star: " << star[1] << star[2] << star[3] << endl;
  }
}

void close(void) {
  // Destroy all objects & close window.

  if (cleanTexture())
    cout << "All texture was delete." << endl;
  else
    cout << "Texture don`t removed!" << endl;

  try {
    if (mainSurface)
      SDL_FreeSurface(mainSurface); // Destroy main (window) surface.
    if (render)
      SDL_DestroyRenderer(render); // Destroy renderer.
    if (window)
      SDL_DestroyWindow(window); // Destroy window.

    cout << "All surface & windows was closed." << endl;
  }

  catch (exception &e) {
    cout << "Coudn`t close window. Error: " << e.what() << endl;
  }
}
