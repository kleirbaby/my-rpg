#pragma once

#include <string>
#include <SDL2/SDL.h>

namespace SDL2
{
class LoadParams;
class Sprite
{
public:
    virtual void draw(SDL_Renderer* pRender)  = 0;
    virtual void update()= 0;
    virtual void clean() = 0;
protected:
    Sprite(const LoadParams *pParams){}
    virtual ~Sprite(){}
};
}