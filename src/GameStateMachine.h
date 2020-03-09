#pragma once

#include <vector>

namespace SDL2
{
class GameState;
class GameStateMachine
{
public:
    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();
private:
    std::vector<GameState*> m_gameStates;
};
}