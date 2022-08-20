#ifndef GameObject_h
#define GameObject_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class GameObject {
public:
  // GameObject(SDL_Renderer* pRenderer, int x, int y, int width, int height, std::string ptextureID);
  // ~GameObject();

  void load(SDL_Renderer* pRenderer, int x, int y, int width, int height, std::string ptextureID);
  void update();
  void draw();
  void clean();

protected:
  SDL_Renderer* m_pRenderer;
  std::string textureID;

  int m_currentRow;
  int m_currentFrame;


  int m_x;
  int m_y;
  int m_height;
  int m_width;
};
#endif
