#ifndef GameObject_h
#define GameObject_h

class GameObject {
public:
  GameObject();
  ~GameObject();

  void update();
  void draw();
  void clean();

protected:
  int m_x;
  int m_y;
};
#endif
