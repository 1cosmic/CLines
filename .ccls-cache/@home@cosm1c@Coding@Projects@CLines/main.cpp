#include <iostream>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "headers/logic.h"

#define SCR_W 1280
#define SCR_H 720


void initCLines(SDL_Window* window, SDL_Surface* surface) {
    // Initialization chesks.

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize. Error: %s\n", SDL_GetError());
        exit(1);
    } 
    else {
        // Create main window:
        window = SDL_CreateWindow("CLines", 
                                  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                  SCR_W, SCR_H, SDL_WINDOW_SHOWN);
        printf("24\n");

        if (window == NULL) {
            printf("Main window could not be created. Error: %s\n", SDL_GetError());
            exit(1);
        }
        else
            // Create window Surface:
            surface = SDL_GetWindowSurface(window);
    }
}


int main(void) {
    SDL_Window * window = NULL;        // Main window of the window window
    SDL_Surface * mainSurface = NULL;  // Surface contained by the window.

    // Initialization SDL.
    initCLines(window, mainSurface);

    // YOU MAIN LOGIC GAME PUT IN HERE.
    //
    //
    initField();  // Initialization back-end field.
    
    // full check of back-end.
    for(int i = 0; i < 34; ++i) {
        if (checkFreeSpace() > 0) {
            randomColors();
            randomPutStar();
        }
        else
            printf("DANONE NAHUY! i: %i\n", i);
    }

    SDL_Delay(2000);
    SDL_DestroyWindow(window);

    return 0;
}
