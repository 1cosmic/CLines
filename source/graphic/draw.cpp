#include "coords.cpp"

#include <SDL2/SDL.h>
#include <utility>

void draw_grid(SDL_Renderer *render, int indent) {
  // Draw grid (for separate of stars).

  pair<int, int> start_pos = centerObj(indent * 9, indent * 9);

  int x = start_pos.first;
  int y = start_pos.second;
  int draw = start_pos.second;

  int endLine = start_pos.first + (9 * indent);

  int speed = (endLine - start_pos.first) / 30;

  int line; // index of line.

  for (draw = 0; draw < endLine - start_pos.first; draw += speed) {

    for (line = 1; line < 9; ++line) {

      // Draw vertical line.
      SDL_RenderDrawLine(render, start_pos.first + (indent * line),
                         start_pos.second, x + (indent * line), y + draw);

      // Draw horisontal line.
      SDL_RenderDrawLine(render, start_pos.first,
                         start_pos.second + (indent * line), x + draw,
                         y + (indent * line));
    }

    SDL_RenderPresent(render);
    // speed *= 0.8;

    SDL_Delay(10);
  }
}
