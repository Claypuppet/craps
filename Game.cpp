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

Game::Game() :
		dice
		{ Dice(), Dice() }, running(false)
{
}

Game::~Game()
{
	// TODO Auto-generated destructor stub
}

void Game::play()
{
	setStartState();
	gameLoop();
}

void Game::setStartState()
{
	statePtr sState = std::make_shared<StartState>(*this);
	setState(sState);
}

void Game::setRunning(bool running)
{
	this->running = running;
}

void Game::gameLoop()
{
	running = true;
	while (running)
	{
		run();
		currentState->doActivity();
	}
}

void Game::throwDice()
{
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
