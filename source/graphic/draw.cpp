#include <SDL2/SDL.h>

void draw_grid(SDL_Renderer *render, int start_x, int start_y, int indent) {
  // Draw grid (for separate of stars).

  int x = start_x;
  int y = start_y;

  int endLine = start_x + (9 * indent);

  int speed = (endLine - start_x) / 100;

  for (x = start_x; x < endLine; x += speed) {
    SDL_RenderDrawLine(render, start_x, start_y, x, y);
    SDL_RenderPresent(render);

    // speed *= 0.9;

    SDL_Delay(10);
  }
}
