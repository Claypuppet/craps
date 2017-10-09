/*
 * GameEventHandler.cpp
 *
 *  Created on: Oct 2, 2017
 *      Author: klei
 */

#include "GameEventHandler.h"
#include "GameState.h"
#include "core.h"

GameEventHandler::GameEventHandler()
{
	TRACE();
}

GameEventHandler::GameEventHandler(const GameEventHandler& original)
{
	TRACE();
}

bool GameEventHandler::handleEvent(Context& c, const Event& e)
{
	TRACE();
	Game* g = dynamic_cast<Game*>(&c);
	return (g) ? handleEvent(*g,e) : false;
}

StartEventHandler::StartEventHandler()
{
	TRACE();
}

bool StartEventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 2:
	case 3:
	case 12:
		game.setState(std::make_shared<LoseState>(game));
		return true;
	case 4:
		game.setState(std::make_shared<Score4State>(game));
		return true;
	case 5:
		game.setState(std::make_shared<Score5State>(game));
		return true;
	case 6:
		game.setState(std::make_shared<Score6State>(game));
		return true;
	case 7:
		game.setState(std::make_shared<WinState>(game));
		return true;
	case 8:
		game.setState(std::make_shared<Score8State>(game));
		return true;
	case 9:
		game.setState(std::make_shared<Score9State>(game));
		return true;
	case 10:
		game.setState(std::make_shared<Score10State>(game));
		return true;
	case 11:
		game.setState(std::make_shared<Score11State>(game));
		return true;
	default:
		return false;
	}
}

LoseEventHandler::LoseEventHandler()
{
	TRACE();
}

bool LoseEventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	return false;
}

WinEventHandler::WinEventHandler()
{
	TRACE();
}

bool WinEventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	return false;
}

Score4EventHandler::Score4EventHandler()
{
	TRACE();
}

bool Score4EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 4:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Score5EventHandler::Score5EventHandler()
{
	TRACE();
}

bool Score5EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 5:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Score6EventHandler::Score6EventHandler()
{
	TRACE();
}

bool Score6EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 6:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Score8EventHandler::Score8EventHandler()
{
	TRACE();
}

bool Score8EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 8:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Score9EventHandler::Score9EventHandler()
{
	TRACE();
}

bool Score9EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 9:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Score10EventHandler::Score10EventHandler()
{
	TRACE();
}

bool Score10EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 10:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Score11EventHandler::Score11EventHandler()
{
	TRACE();
}

bool Score11EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 11:
		game.setState(std::make_shared<WinState>(game));
		return true;
	default:
		return false;
	}
}

Lose7EventHandler::Lose7EventHandler()
{
	TRACE();
}

bool Lose7EventHandler::handleEvent(Game& game, const Event& e)
{
	TRACE();
	switch(e.getId()){
	case 7:
		game.setState(std::make_shared<LoseState>(game));
		return true;
	default:
		return false;
	}
}

