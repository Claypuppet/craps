/*
 * GameState.h
 *
 *  Created on: Sep 29, 2017
 *      Author: klei
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <vector>
#include <memory>

#include "Game.h"
#include "ConcreteState.h"
#include "GameEventHandler.h"


class GameState: public State
{
public:
	virtual ~GameState();
	virtual void entryAction() = 0;
	virtual void doActivity() = 0;
	virtual void exitAction() = 0;
protected:
	GameState(Game& aGame);
	Game& game;
};

class StartState : public GameState
{
public:
	StartState(Game& aGame);
	virtual ~StartState();
	virtual void entryAction() override;
	virtual void doActivity() override;
	virtual void exitAction() override;
};

class LoseState: public GameState
{
public:
	LoseState(Game& aGame);
	virtual ~LoseState();
	virtual void entryAction() override;
	virtual void doActivity() override;
	virtual void exitAction() override;
};

class WinState: public GameState
{
public:
	WinState(Game& aGame);
	virtual ~WinState();
	virtual void entryAction() override;
	virtual void doActivity() override;
	virtual void exitAction() override;
};

class GameScoreState: public GameState {
public:
	virtual ~GameScoreState() = default;
	virtual void entryAction() = 0;
	virtual void doActivity() override;
	virtual void exitAction() = 0;
protected:
	GameScoreState(Game& aGame);
};

class Score4State: public GameScoreState
{
public:
	Score4State(Game& aGame);
	virtual ~Score4State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

class Score5State: public GameScoreState
{
public:
	Score5State(Game& aGame);
	virtual ~Score5State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

class Score6State: public GameScoreState
{
public:
	Score6State(Game& aGame);
	virtual ~Score6State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

class Score8State: public GameScoreState
{
public:
	Score8State(Game& aGame);
	virtual ~Score8State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

class Score9State: public GameScoreState
{
public:
	Score9State(Game& aGame);
	virtual ~Score9State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

class Score10State: public GameScoreState
{
public:
	Score10State(Game& aGame);
	virtual ~Score10State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

class Score11State: public GameScoreState
{
public:
	Score11State(Game& aGame);
	virtual ~Score11State();
	virtual void entryAction() override;
	virtual void exitAction() override;
};

#endif /* GAMESTATE_H_ */
