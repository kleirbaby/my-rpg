#include "Player.h"
#include "LoadParams.h"

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

void Player::draw()
{

}

void Player::update()
{

}

void Player::clean()
{

}