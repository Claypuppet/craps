/*
 * tests.h
 *
 *  Created on: Sep 29, 2017
 *      Author: klei
 */

#ifndef CRAPSTEST_CPP_
#define CRAPSTEST_CPP_

#include <iostream>
#include <memory>
#include <boost/test/unit_test.hpp>

#include "GameState.h"
#include "Event.h"
#include "Game.h"


#define BOOST_TEST_DYN_LINK


#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE( CrapsTestModule1 )


BOOST_AUTO_TEST_CASE( testDirectWin ){
	Game g;
	Event e(7); // rolled 7 (win)
	StartState s(g);
	s.handleEvent(e, g);
	BOOST_CHECK(dynamic_cast<WinState*>(g.getState().get()));
}

BOOST_AUTO_TEST_CASE( testDirectLose ){
	Game g;
	Event e(12); // rolled 12 (lose)
	StartState s(g);
	s.handleEvent(e, g);
	BOOST_CHECK(dynamic_cast<LoseState*>(g.getState().get()));
}

BOOST_AUTO_TEST_CASE( testIndirectWin ){
	Game g;
	Event e(4); // rolled 4 (win)
	Score4State s(g);
	s.handleEvent(e, g);
	BOOST_CHECK(dynamic_cast<WinState*>(g.getState().get()));
}

BOOST_AUTO_TEST_CASE( testIndirectLose ){
	Game g;
	Event e(7); // rolled 7 (lose)
	Score4State s(g);
	s.handleEvent(e, g);
	BOOST_CHECK(dynamic_cast<LoseState*>(g.getState().get()));
}


BOOST_AUTO_TEST_SUITE_END()


#endif /* CRAPSTEST_CPP_ */
