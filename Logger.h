/*
 * Logger.h
 *
 *  Created on: 9 Oct 2017
 *      Author: Vuurvlieg
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <mutex>

#include "Singleton.h"

class Logger : public Singleton<Logger>
{
public:
	Logger();
	virtual ~Logger();
	void log(const std::string& text);
private:
	std::mutex loggerMutex;
};

#endif /* LOGGER_H_ */
