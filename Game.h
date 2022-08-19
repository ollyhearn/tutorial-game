#ifndef Game_h
#define Game_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running(){ return m_bRunning; }

private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

};

#endif
