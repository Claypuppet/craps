/*
 * main.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: klei
 */

#include <iostream>
#include "Game.h"
#include "Logger.h"

#define BOOST_TEST_MODULE CrapsTestModule2
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN

#include <boost/config.hpp>
#include <boost/test/unit_test.hpp>

#include <thread>

void playGame(){
	Game g;
	g.play();
}


int main(int argc, char **argv)
{
	Logger::getInstace().log("Craps started!");

//	boost::unit_test::unit_test_main(&init_unit_test, argc, argv);
//	playGame();

	std::array<std::thread, 10> workerThreads;


	for(size_t i = 0; i < workerThreads.size(); ++i)
		workerThreads[i] = std::thread(playGame);

	for (auto& t : workerThreads)
		t.join();


	Logger::getInstace().log("Craps finished!");
}
