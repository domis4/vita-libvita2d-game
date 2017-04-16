#include "game/game-module.h"

int main()
{
	GameModule game;
	game.init();

	while (1) {
		game.render();
		game.update();
	}

	game.end();

	return 0;
}