/*
 * Game.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#include <algorithm>
#include <iostream>

#include "Game.h"
#include "GameState.h"
#include "core.h"

Game::Game() :
		dice { Dice(), Dice() }, running(false)
{
	TRACE();
}

Game::~Game()
{
	TRACE();
}

void Game::play()
{
	TRACE();
	setStartState();
	gameLoop();
}

void Game::setStartState()
{
	TRACE();
	statePtr sState = std::make_shared<StartState>(*this);
	setState(sState);
}

void Game::end()
{
	TRACE();
	this->running = false;
}

void Game::gameLoop()
{
	TRACE();
	running = true;
	while (running)
	{
		run();
		currentState->doActivity();
	}
}

void Game::throwDice()
{
	TRACE();
	unsigned short diceValue = 0;
	for (auto& d : dice)
	{
		d.roll();
		diceValue += d.getValue();
	}
	Event e(diceValue);
	std::cout << "you rolled total: " << diceValue << std::endl;
	scheduleEvent(e);
}
