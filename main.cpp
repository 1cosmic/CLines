#include <iostream>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "headers/gui.h"
#include "headers/logic.h"

int main(void) {
  // Initialization SDL.

  initCLines();

  startGame();

  // YOU MAIN LOGIC GAME PUT IN HERE.
  initField(); // Initialization back-end field.

  // Close game. Destroy main window & others.
  close();

  // full check of back-end.
  int counter = 0;
  srand(time(NULL));

  while (checkFreeSpace()) {
    randomColors();
    randomPutStar();
    ++counter;
  }
  // searchLines(2);

  /* std::cout << counter << std::endl; */
  printField();

  return 0;
}
