/*
 * Context.h
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#ifndef CONTEXT_H_
#define CONTEXT_H_

#include <memory>
#include <queue>

#include "Event.h"
#include "ConcreteState.h"

typedef std::shared_ptr<State> statePtr;

class Context
{
public:
	Context();
	virtual ~Context();
	const statePtr& getState() const;
	void setState(const statePtr& state);
	void scheduleEvent(const Event& e);
	void run();

protected:
	statePtr currentState;
	std::queue<Event> events;
};

#endif /* CONTEXT_H_ */
