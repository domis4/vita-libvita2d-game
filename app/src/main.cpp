#include "game/game-module.h"
#include "game/atlas/atlas.h"

Atlas* atlas = new Atlas();

int main() {
	GameModule game;
	game.init();
	game.initRender();
	game.end();
	return 0;
}