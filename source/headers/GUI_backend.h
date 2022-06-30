#pragma once

#ifndef GUI_BACKEND_H
#define GUI_BACKEND_H

#include <SDL2/SDL.h>

#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <filesystem>
#include <iostream>
#include <utility>
#include <string>
#include <vector>


// backend.cpp

bool cleanTexture();
bool initTexture(SDL_Renderer *render);


// draw.cpp
extern SDL_Rect Rect_backbround;
void draw_grid(SDL_Renderer *render, int indent);
void draw_star(SDL_Renderer *render, int y, int x, SDL_Texture *texture);
bool initRects();

#endif // GUI_BACKEND_H
