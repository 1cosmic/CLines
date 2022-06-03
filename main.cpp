#include <iostream>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "headers/gui.h"
#include "headers/logic.h"

int main(void) {
  // Initialization SDL.

  initCLines();

  showHello();

  // YOU MAIN LOGIC GAME PUT IN HERE.
  initField(); // Initialization back-end field.

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

  // Close game. Destroy main window & others.
  close();

  return 0;
}
