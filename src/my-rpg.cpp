#include "Game.h"
#include "../common/Singleton.h"

int main(int argc,char *argv[])
{
    typedef Singleton<Game> Game_Singleton;
    Game_Singleton game;

    game.getInstance()->init("my-rpg",260,260,640,320);
    game.getInstance()->render();
    game.getInstance()->handleEvents();
    game.getInstance()->clean();

    game.clean();
    return 0;
}