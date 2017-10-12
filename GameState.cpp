/*
 * GameState.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: klei
 */


#include <iostream>

#include "GameState.h"
#include "core.h"

GameState::GameState(Game& aGame): game(aGame)
{
	TRACE();
}

GameState::~GameState()
{
	TRACE();
}

/* Start state */

StartState::StartState(Game& aGame) : GameState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<StartEventHandler>());
}

StartState::~StartState()
{
	TRACE();
}

void StartState::entryAction()
{
	TRACE();
}

void StartState::doActivity()
{
	TRACE();
	game.throwDice();
}

void StartState::exitAction()
{
	TRACE();
}


/* End start state */

/* Lose state */

LoseState::LoseState(Game& aGame) : GameState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<LoseEventHandler>());
}

LoseState::~LoseState()
{
	TRACE();
}

void LoseState::entryAction()
{
	TRACE();
	Logger::getInstace().log("YOU LOSE!!");
	game.end();
}

void LoseState::doActivity()
{
	TRACE();
}

void LoseState::exitAction()
{
	TRACE();
}


/* End lose state */

/* Win state */

WinState::WinState(Game& aGame) : GameState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<WinEventHandler>());
}

WinState::~WinState()
{
	TRACE();
}

void WinState::entryAction()
{
	TRACE();
	Logger::getInstace().log("YOU WIN!!");
	game.end();
}

void WinState::doActivity()
{
	TRACE();
}

void WinState::exitAction()
{
	TRACE();
}

/* End win state */

/* Default score state */

GameScoreState::GameScoreState(Game& aGame) : GameState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Lose7EventHandler>());
}

void GameScoreState::doActivity()
{
	TRACE();
	game.throwDice();
}


/* End default score state */

/* Score 4 state */

Score4State::Score4State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score4EventHandler>());
}

Score4State::~Score4State()
{
	TRACE();
}

void Score4State::entryAction()
{
	TRACE();
}

void Score4State::exitAction()
{
	TRACE();
}


/* End score 4 state */

/* Score 5 state */

Score5State::Score5State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score5EventHandler>());
}

Score5State::~Score5State()
{
	TRACE();
}

void Score5State::entryAction()
{
	TRACE();
}


void Score5State::exitAction()
{
	TRACE();
}


/* End score 5 state */

/* Score 6 state */

Score6State::Score6State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score6EventHandler>());
}

Score6State::~Score6State()
{
	TRACE();
}

void Score6State::entryAction()
{
	TRACE();
}


void Score6State::exitAction()
{
	TRACE();
}

/* End score 6 state */

/* Score 8 state */

Score8State::Score8State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score8EventHandler>());
}

Score8State::~Score8State()
{
	TRACE();
}

void Score8State::entryAction()
{
	TRACE();
}

void Score8State::exitAction()
{
	TRACE();
}

/* End score 8 state */

/* Score 9 state */

Score9State::Score9State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score9EventHandler>());
}

Score9State::~Score9State()
{
	TRACE();
}

void Score9State::entryAction()
{
	TRACE();
}


void Score9State::exitAction()
{
	TRACE();
}

/* End score 9 state */

/* Score 10 state */

Score10State::Score10State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score10EventHandler>());
}

Score10State::~Score10State()
{
	TRACE();
}

void Score10State::entryAction()
{
	TRACE();
}

void Score10State::exitAction()
{
	TRACE();
}

/* End score 10 state */

/* Score 11 state */

Score11State::Score11State(Game& aGame) : GameScoreState(aGame)
{
	TRACE();
	eventHandlers.push_back(std::make_shared<Score11EventHandler>());
}

Score11State::~Score11State()
{
	TRACE();
}

void Score11State::entryAction()
{
	TRACE();
}

void Score11State::exitAction()
{
	TRACE();
}

/* End score 11 state */
