#include "Game.h"
#include "Game.cpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Game* g_game = 0;

int main(int argc, char* argv[]) {
  g_game = new Game();
  g_game->init("Sample name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0, 0);

  const int FPS = 60;
	const int fdelay = 1000 / FPS;

	Uint32 fstart;
	int ftime;

  while (g_game->running()) {
    fstart = SDL_GetTicks();
    g_game->handleEvents();
    g_game->update();
    g_game->render();
    SDL_Delay(10);
    // ftime = SDL_GetTicks() - fstart; // Delay by frames to 60 FPS
		// if (fdelay > ftime){
		// 	SDL_Delay(fdelay - ftime);
		// }
  }
  g_game->clean();
  return 0;
}
