#include "Game.h"
#include "../common/Commondef.hpp"
#include "TextureManager.h"
#include "Sprite.h"

Game::Game()
{

}

Game::~Game()
{
    m_textureMgr.clean();
}

bool Game::init(std::string title,int x,int y,int w,int h,int flags /*= SDL_WINDOW_SHOWN*/)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        dPrint("sdl init fail\n");
        return false;
    }
    
    m_pWnd = SDL_CreateWindow(title.c_str(),x,y,w,h,flags);
    if(m_pWnd == NULL){
        dPrint("create window fail\n");
        return false;
    }

    m_pRender = SDL_CreateRenderer(m_pWnd,-1,0);
    if(m_pRender == NULL){
        dPrint("create renderer fail\n");
        return false;
    }

    //set default color
    SDL_SetRenderDrawColor(m_pRender,175,175,175,50);

    //fixed me
    if(!m_textureMgr.getInstance()->load("../assets/meinv3.jpeg","beauty",m_pRender)){
        dPrint("texture manager load fail\n");
        return false;
    }

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRender);

    //fixed me
    m_textureMgr.getInstance()->draw("beauty",50,40,220,140,m_pRender);

    SDL_RenderPresent(m_pRender);
}

void Game::update()
{
    for(std::vector<Sprite*>::size_type i = 0;i < m_spriteVec.size();++i){
        m_spriteVec[i]->update();
    }
}

void Game::draw()
{
    for(std::vector<Sprite*>::size_type i = 0;i < m_spriteVec.size();++i){
        m_spriteVec[i]->draw();
    }
}

void Game::handleEvents()
{
    while(!m_bExit){

        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type)
            {
            case SDL_QUIT:
                exit();
                break;
            default:
                break;
            }
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow(m_pWnd);
    SDL_DestroyRenderer(m_pRender);
    SDL_Quit();
}

void Game::exit()
{
    m_bExit = true;
}