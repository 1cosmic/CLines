#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>

#include <experimental/filesystem>
#include <string>
#include <vector>

using namespace std;
namespace fs = experimental::filesystem;

// Dirs for loading.
fs::path cur_path = fs::current_path();
fs::path src_path = cur_path.parent_path() / "images";

// My grab texture collector >:))
vector<SDL_Texture *> loadedTexture;

// Block of texture.
SDL_Texture *tx_bgd;              // background of the game.
vector<SDL_Texture *> tx_star(7); // star texture vector.

SDL_Texture *loadTexture(SDL_Renderer *render, string path) {
  // Load in RAM image of texture.

  SDL_Surface *image = nullptr;
  SDL_Texture *texture = nullptr;

  image = SDL_LoadBMP(path.c_str()); // load image.

  if (image) {
    texture = SDL_CreateTextureFromSurface(render,
                                           image); // convert image -> texture.
    SDL_FreeSurface(image);                        // cleaner.

    loadedTexture.push_back(texture); // mark texture for cleaner.

  } else {
    printf("Texture | %s | is not loaded. Error: %s", path.c_str(),
           SDL_GetError());
  }

  return texture;
}

bool cleanTexture() {
  // Cleaner of texture.

  int i = 0;

  // Very very very long cleaner, its perfect iterator!
  for (vector<SDL_Texture *>::iterator i_texture = loadedTexture.begin();
       i_texture <= loadedTexture.end(); ++i_texture) {
    SDL_DestroyTexture(*i_texture);

    ++i;
  }

  if (i) {
    printf("Null texture list.");
    return false;

  } else {
    printf("%i texture was delete.", i);
    return true;
  }
}

bool initTexture(SDL_Renderer *render) {
  // Load & convert all image in texture.

  tx_bgd = loadTexture(render, src_path);
  string star_path;
  int star_number = 1;

  vector<SDL_Texture *>::iterator i; // iterator vector of texture stars.
  for (i = tx_star.begin(); i <= tx_star.end(); ++i) {

    // star_path = "star_" + (string)star_number + ".bmp";
    // *i = loadTexture(render, src_path / star_number.c_str());
  }
}
