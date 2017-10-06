/*
 * main.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: klei
 */

#include <iostream>

#include "Game.h"


#define BOOST_TEST_MODULE CrapsTestModule1
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/test/unit_test.hpp>


void playGame(){
	Game g;
	g.play();
}


int main(int argc, char **argv)
{
	std::cout << "Craps started" << std::endl << std::endl;


	boost::unit_test::unit_test_main( &init_unit_test, argc, argv );
//	playGame();

	std::cout << std::endl << "Craps finished" << std::endl;
}
