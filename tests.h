/*
 * tests.h
 *
 *  Created on: Sep 29, 2017
 *      Author: klei
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <iostream>
#include <memory>
#include <stdexcept>

#include "GameState.h"
#include "Event.h"
#include "Game.h"

typedef std::logic_error fail;

void testDirectWin()
{
	Game c;
	c.setStartState();
	Event e1(7); // rolled 7 (win)
	c.scheduleEvent(e1);
	c.run();
	if (dynamic_cast<WinState*>(c.getState().get()) == NULL)
	{
		throw fail(__PRETTY_FUNCTION__);
	}
}

void testDirectLose()
{
	Game c;
	c.setStartState();
	Event e1(12); // rolled 12 (lose)
	c.scheduleEvent(e1);
	c.run();
	if (dynamic_cast<LoseState*>(c.getState().get()) == NULL)
	{
		throw fail(__PRETTY_FUNCTION__);
	}
}

void testIndirectWin()
{
	Game c;
	c.setStartState();
	Event e1(4); // rolled 4
	Event e2(1); // rolled 1
	Event e3(11); // rolled 11
	Event e4(4); // rolled 4 (win)
	c.scheduleEvent(e1);
	c.scheduleEvent(e2);
	c.scheduleEvent(e3);
	c.scheduleEvent(e4);
	c.run();
	if (dynamic_cast<WinState*>(c.getState().get()) == NULL)
	{
		throw fail(__PRETTY_FUNCTION__);
	}
}

void testIndirectLose()
{
	Game c;
	c.setStartState();
	Event e1(3); // rolled 3
	Event e2(1); // rolled 1
	Event e3(11); // rolled 11
	Event e4(7); // rolled 7 (lose)
	c.scheduleEvent(e1);
	c.scheduleEvent(e2);
	c.scheduleEvent(e3);
	c.scheduleEvent(e4);
	c.run();
	if (dynamic_cast<LoseState*>(c.getState().get()) == NULL)
	{
		throw fail(__PRETTY_FUNCTION__);
	}
}

void testScore8State()
{
	Game c;
	c.setStartState();
	Event e1(8); // rolled 8
	c.scheduleEvent(e1);
	c.run();
	if (dynamic_cast<Score8State*>(c.getState().get()) == NULL)
	{
		throw fail(__PRETTY_FUNCTION__);
	}
}

void executeTests()
{
	testDirectWin();
	testIndirectWin();
	testDirectLose();
	testIndirectLose();
	testScore8State();
	std::cout << "ALL TESTS SUCCESS" << std::endl;
}


#endif /* TESTS_H_ */
