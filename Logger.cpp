/*
 * Logger.cpp
 *
 *  Created on: 9 Oct 2017
 *      Author: Vuurvlieg
 */

#include <iostream>
#include <chrono>
#include <thread>

#include "Logger.h"

Logger::Logger()
{
	// TODO Auto-generated constructor stub

}

Logger::~Logger()
{
	// TODO Auto-generated destructor stub
}

void Logger::log(const std::string& text)
{
	loggerMutex.lock();
	static clock_t start = std::clock();
	std::cout << std::this_thread::get_id() << "\t" << std::clock() - start << "\t" << text << std::endl;
	loggerMutex.unlock();
}
