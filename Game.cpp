#include "Game.h"
#include "TextureManager.h"
#include "TextureManager.cpp"

#include "objects/Player.h"
// #include "objects/GameObject.h"
// #include "objects/GameObject.cpp"

Game::Game() {}
Game::~Game() {}

int m_currentFrame;
Player pekar;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0 && IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == (IMG_INIT_PNG | IMG_INIT_JPG)) {
		printf("%s\n", "libs inited");
		if (fullscreen) {
			flags = SDL_WINDOW_FULLSCREEN;
		}
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) {
			printf("%s\n", "window created");
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != 0) {
				printf("%s\n", "renderer created");
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
				// m_textureManager = new TextureManager();
				TextureManager::Instance()->load("assets/pekar.png", "pekar", m_pRenderer);
				pekar.load(m_pRenderer, 100, 100, 128, 256, "pekar");
			}
			else {
				printf("%s\n", "renderer not created");
				return false;
			}
		}
		else {
			printf("%s\n", "window not created");
			return false;
		}
	}
	else {
		printf("%s: %s\n%s\n", "libs not inited, check if SDL2 and SDL2_image installed", IMG_GetError(), SDL_GetError());
		return false;
	}
printf("%s\n", "init succsess");
m_bRunning = true;
return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	// TextureManager::Instance()->draw("pekar", 0, 0, 128, 256, m_pRenderer);
	// TextureManager::Instance()->drawFrame("pekar", 100, 100, 128, 256, 1, m_currentFrame, m_pRenderer);
	pekar.draw();
	SDL_RenderPresent(m_pRenderer);
}

void Game::clean() {
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	printf("%s\n", "quit the game");
	IMG_Quit();
	SDL_Quit();
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_bRunning = false;
			break;

			default:
			break;
		}
	}
}

void Game::update() {
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	pekar.update();
}
