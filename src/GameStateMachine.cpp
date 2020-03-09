#include "GameStateMachine.h"
#include "GameState.h"

void GameStateMachine::pushState(GameState* pState)
{
    m_gameStates.push_back(pState);
    pState->onEnter();
}

void GameStateMachine::changeState(GameState* pState)
{

}

void GameStateMachine::popState()
{
    if(!m_gameStates.empty()){
        if(m_gameStates.back()->onExit()){
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}