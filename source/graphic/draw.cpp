#include <SDL2/SDL.h>

void draw_grid(SDL_Renderer *render, int start_x, int start_y, int indent) {
  // Draw grid (for separate of stars).

  int x = start_x;
  int y = start_y;
  int draw = start_y;

  int endLine = start_x + (9 * indent);

  int speed = (endLine - start_x) / 60;

  int line; // index of line.

  for (draw = 0; draw < endLine - start_x; draw += speed) {

    for (line = 1; line < 9; ++line) {

      // Draw vertical line.
      SDL_RenderDrawLine(render, start_x + (indent * line), start_y,
                         x + (indent * line), y + draw);

      // Draw horisontal line.
      SDL_RenderDrawLine(render, start_x, start_y + (indent * line), x + draw,
                         y + (indent * line));
    }

    SDL_RenderPresent(render);
    // speed *= 0.8;

    SDL_Delay(10);
  }
}
