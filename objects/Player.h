#include "GameObject.h"
#include "GameObject.cpp"

class Player : public GameObject {
  // using GameObject::GameObject;//(SDL_Renderer* pRenderer, int x, int y, int width, int height, std::string ptextureID);
public:
  // Player::Player() {}
  // ~Player() {}
  void load(SDL_Renderer* pRenderer, int x, int y, int width, int height, std::string ptextureID) {
    GameObject::load(pRenderer, x, y, width, height, ptextureID);
  }
  void draw() { GameObject::draw(); }
  // void update() { GameObject::update(); }
  void clean() { GameObject::clean(); }

  void update() {
    m_x += 1;
  }
};
