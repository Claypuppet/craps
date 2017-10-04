/*
 * main.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: klei
 */

#include <iostream>

#include "Game.h"
#include "tests.h"

void playGame(){
	Game g;
	g.play();
}

void testGame(){
	executeTests();
}

void calculateWinPercentage(){
	Game g;
	int won = 0;
	size_t games = 10000;
	for(size_t i = 0; i < games; ++i){
		g.play();
		if(dynamic_cast<WinState*>(g.getState().get()))
			++won;
	}
	std::cout << "Win chance: " << 100 * (static_cast<float>(won) / games) << "%!" << std::endl;

}

int main(int argc, char **argv)
{
	std::cout << "Craps started" << std::endl << std::endl;

	playGame();

	std::cout << std::endl << "Craps finished" << std::endl;
}
