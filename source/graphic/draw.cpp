#include "coords.cpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <utility>

SDL_Rect Rect_backbround;

SDL_Rect Rect_field;

SDL_Rect Rect_cells[9][9];

void draw_grid(SDL_Renderer *render, int indent) {
  // Draw grid (for separate of stars).

  const pair<int, int> start_pos = centerObj(indent * 9, indent * 9);

  int x = start_pos.first;
  int y = start_pos.second;
  int draw = start_pos.second; // cursor for drawing.

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

void draw_star(SDL_Renderer *render, int y, int x, SDL_Texture *texture) {
  // Draw sprite of star.

  SDL_RenderCopy(render, texture, &Rect_field, &Rect_cells[y][x]);
  // SDL_RenderCopy(render, texture, &Rect_cells[y][x], &Rect_field);
  SDL_RenderPresent(render);
}

bool initRects() {
  // Initialize of rects ()

  // Init background rect.
  Rect_backbround.x = 0;
  Rect_backbround.y = 0;
  Rect_backbround.w = 1280;
  Rect_backbround.h = 720;

  // Init field rect.
  Rect_field.x = centerObj(9 * 60, 9 * 50).first;
  Rect_field.y = centerObj(9 * 60, 9 * 50).second;
  Rect_field.w = 9 * 60;
  Rect_field.h = 9 * 60;

  // Generate all rects of cells for field.
  int column, cell;

  for (column = 0; column < 9; ++column) {
    for (cell = 0; cell < 9; ++cell) {

      Rect_cells[column][cell].x = 60 * cell + Rect_field.x;
      Rect_cells[column][cell].y = 60 * column + Rect_field.y;
      Rect_cells[column][cell].h = 60;
      Rect_cells[column][cell].w = 60;
    }
  }

  return true;
}
