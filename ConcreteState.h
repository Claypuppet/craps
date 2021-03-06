/*
 * State.h
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#ifndef CONCRETESTATE_H_
#define CONCRETESTATE_H_

#include <vector>
#include <memory>

#include "Event.h"
#include "ConcreteEventHandler.h"

class Context;
typedef std::vector<std::shared_ptr<EventHandler>> eventList;


class State
{
public:
	State() = default;
	virtual ~State() = default;
	virtual void entryAction() = 0;
	virtual void doActivity() = 0;
	virtual void exitAction() = 0;
	virtual bool handleEvent(const Event& e, Context& c)
	{
		for(eventList::iterator itr = eventHandlers.begin(); itr != eventHandlers.end(); ++itr)
			if((*itr)->handleEvent(c, e))
				return true;
		return false;
	};
protected:
	eventList eventHandlers;
};



#endif /* CONCRETESTATE_H_ */
