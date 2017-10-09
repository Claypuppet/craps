/*
 * Game.h
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#ifndef GAME_H_
#define GAME_H_

#include <array>

#include "Context.h"
#include "Dice.h"

class Game: public Context
{
public:
	Game();
	virtual ~Game();
	void play();
	void throwDice();
	void end();
	void setStartState();
private:
	std::array<Dice, 2> dice;
	bool running;
	void gameLoop();
};

#endif /* GAME_H_ */
