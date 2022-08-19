#include "Game.h"
#include "Game.cpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game* g_game = 0;

int main(int argc, char* argv[]) {
  g_game = new Game();
  g_game->init("Sample name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0, 0);

  while (g_game->running()) {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
  }
  g_game->clean();
  return 0;
}
