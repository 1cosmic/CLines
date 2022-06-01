#include <SDL2/SDL.h>

#include <experimental/filesystem>
#include <iostream>

#define SCR_W 1280
#define SCR_H 720

using namespace std;

SDL_Window *window = NULL;       // Main window of the window window
SDL_Surface *mainSurface = NULL; // Surface contained by the window.

bool initCLines(void) {
  // Initialization chesks.

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize. Error: %s\n", SDL_GetError());
    exit(1);
  } else {
    // Create main window:
    window = SDL_CreateWindow("CLines", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCR_W, SCR_H,
                              SDL_WINDOW_SHOWN);

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

  SDL_Delay(1000);
  SDL_FreeSurface(background);

  return true;
}

void close(void) {
  // Destroy all objects.

  SDL_FreeSurface(mainSurface);
  SDL_DestroyWindow(window);

  cout << "All surface & windows was closed." << endl;
}
