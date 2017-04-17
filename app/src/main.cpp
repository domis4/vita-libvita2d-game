#include "game/game-module.h"

int main()
{
	GameModule game;
	game.init();
	game.initRender();
	game.end();
	return 0;
}