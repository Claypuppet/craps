/*
 * EventHandler.h
 *
 *  Created on: Oct 2, 2017
 *      Author: klei
 */

#ifndef CONCRETEEVENTHANDLER_H_
#define CONCRETEEVENTHANDLER_H_

#include "Event.h"
class Context;

class EventHandler
{
public:
	EventHandler() = default;
	virtual ~EventHandler() = default;
	virtual bool handleEvent(Context& c, const Event& e) = 0;
};

#endif /* CONCRETEEVENTHANDLER_H_ */
