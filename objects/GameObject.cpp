#include "GameObject.h"
#include "../TextureManager.h"

void GameObject::load(SDL_Renderer* pRenderer, int x, int y, int width, int height, std::string ptextureID) {
  m_x = x;
  m_y = y;
  m_width = width;
  m_height = height;
  textureID = ptextureID;
  m_pRenderer = pRenderer;
  m_currentRow = 1;
  m_currentFrame = 1;
}

void GameObject::draw() {
  TextureManager::Instance()->drawFrame(textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, m_pRenderer);
}

void GameObject::update() {
  m_x += 1;
}
