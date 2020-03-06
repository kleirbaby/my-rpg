#include "Player.h"
#include "LoadParams.h"
#include "TextureManager.h"

Player::Player(const LoadParams *pParam)
    :Sprite(pParam)
{
    m_x         = pParam->getX();
    m_y         = pParam->getY();
    m_width     = pParam->getWidth();
    m_height    = pParam->getHeight();
    m_textureId = pParam->getTextureId();

    m_curRow    = 1;
    m_curFrame  = 1;
}

Player::~Player()
{

}

void Player::draw(SDL_Renderer* pRender)
{
    TextureManager_Singleton().getInstance()->drawFrame(m_textureId,m_x,m_y,m_width,m_height,m_curRow,m_curFrame,pRender);
}

void Player::update()
{
    m_x += 1;
    m_curFrame = int((SDL_GetTicks()/100)%6);
}

void Player::clean()
{

}