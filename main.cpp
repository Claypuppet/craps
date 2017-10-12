/*
 * main.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: klei
 */

#include "../cs_common/Config.hpp"
#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/smart_ptr.hpp>
#include "../cs_common/Message.hpp"
#include "../cs_common/Session.hpp"
#include "CrapsServer.h"

// This object represents the OS I/O service.
// There should be at least 1 object of this type in the program.
// TODO: find if there *should* be only one
boost::asio::io_service io_service;
// global accessor
boost::asio::io_service& getIOService()
{
	return io_service;
}

#include "Logger.h"



int main(int argc, char **argv)
{
	Logger::getInstace().log("Craps server started!");

	try
	{
		// Create the server object. This must be alive while the program runs
		MessageASIO::Server server(getIOService(), 12345);

		// Run the service until further notice
		getIOService().run();
	}

	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(...)
	{
		std::cout << "Unknown exception" << std::endl;
	}

	Logger::getInstace().log("Craps server closed!");
}
