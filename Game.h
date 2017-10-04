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
	void setRunning(bool running);
	void setStartState();
private:
	bool running;
	void gameLoop();
	std::array<Dice, 2> dice;
};

#endif /* GAME_H_ */
