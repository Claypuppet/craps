/*
 * GameEventHandler.h
 *
 *  Created on: Oct 2, 2017
 *      Author: klei
 */

#ifndef GAMEEVENTHANDLER_H_
#define GAMEEVENTHANDLER_H_

#include "ConcreteEventHandler.h"
#include "Game.h"

/* Game event handler */

class GameEventHandler : public EventHandler
{
public:
	GameEventHandler(const GameEventHandler& original);
	virtual ~GameEventHandler() = default;
	virtual bool handleEvent(Context& c, const Event& e) final;
	virtual bool handleEvent(Game& g, const Event& e) = 0;
protected:
	GameEventHandler();
};

/* End game event handler */

/* Start event handler */

class StartEventHandler : public GameEventHandler
{
public:
	StartEventHandler();
	virtual ~StartEventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End start event handler */

/* Lose event handler */

class LoseEventHandler : public GameEventHandler
{
public:
	LoseEventHandler();
	virtual ~LoseEventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Lose event handler */

/* Win event handler */

class WinEventHandler : public GameEventHandler
{
public:
	WinEventHandler();
	virtual ~WinEventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Win event handler */

/* Score 4 event handler */

class Score4EventHandler : public GameEventHandler
{
public:
	Score4EventHandler();
	virtual ~Score4EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 4 event handler */

/* Score 5 event handler */

class Score5EventHandler : public GameEventHandler
{
public:
	Score5EventHandler();
	virtual ~Score5EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 5 event handler */

/* Score 6 event handler */

class Score6EventHandler : public GameEventHandler
{
public:
	Score6EventHandler();
	virtual ~Score6EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 6 event handler */

/* Lose 7 event handler */

class Lose7EventHandler : public GameEventHandler
{
public:
	Lose7EventHandler();
	virtual ~Lose7EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Lose 7 event handler */

/* Score 8 event handler */

class Score8EventHandler : public GameEventHandler
{
public:
	Score8EventHandler();
	virtual ~Score8EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 8 event handler */

/* Score 9 event handler */

class Score9EventHandler : public GameEventHandler
{
public:
	Score9EventHandler();
	virtual ~Score9EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 9 event handler */

/* Score 10 event handler */

class Score10EventHandler : public GameEventHandler
{
public:
	Score10EventHandler();
	virtual ~Score10EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 10 event handler */

/* Score 11 event handler */

class Score11EventHandler : public GameEventHandler
{
public:
	Score11EventHandler();
	virtual ~Score11EventHandler() = default;
	virtual bool handleEvent(Game& g, const Event& e) override;
};

/* End Score 11 event handler */


#endif /* GAMEEVENTHANDLER_H_ */
