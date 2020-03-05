#pragma once

#include <string>

class LoadParams;
class Sprite
{
public:
    virtual void draw()  = 0;
    virtual void update()= 0;
    virtual void clean() = 0;
protected:
    Sprite(const LoadParams *pParams){}
    virtual ~Sprite(){}
};