#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "TextureManager.h"
#include "../common/Singleton.h"

class Sprite;
class Game
{
public:
    Game();
    ~Game();

    bool init(std::string title,int x,int y,int w,int h,int flags = SDL_WINDOW_SHOWN);
    void render();
    void update();
    void draw();
    void handleEvents();
    void clean();
    void exit();

    inline SDL_Renderer* getRenderer()const { return m_pRender;}
private:
    SDL_Window     *m_pWnd       = nullptr;
    SDL_Renderer   *m_pRender    = nullptr;
    bool            m_bExit      = false;

    std::vector<Sprite*>     m_spriteVec;
};

typedef Singleton<Game> Game_Singleton;