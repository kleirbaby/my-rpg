#include "Sprite.h"

class LoadParams;
class Player:public Sprite
{
public:
    Player(const LoadParams *pParam);
    ~Player();

    void draw(SDL_Renderer* pRender);
    void update();
    void clean();
private:
    std::string m_textureId;
    int         m_curFrame;
    int         m_curRow;
    int         m_x;
    int         m_y;
    int         m_width;
    int         m_height;
};