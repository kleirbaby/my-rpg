#pragma once

#include "GameState.h"

namespace SDL2
{
class PlayState:public GameState
{
public:
    virtual void update();
    virtual void render();
    virtual bool onEnter();
    virtual bool onExit();
    inline virtual std::string getStateId()const{ return s_playId; }
private:
    static const std::string s_playId;
};
}