/*
 * State.h
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#ifndef CONCRETESTATE_H_
#define CONCRETESTATE_H_

#include <memory>

#include "Event.h"

class Context;

class State
{
public:
	State() = default;
	virtual ~State() = default;
	virtual void entryAction() = 0;
	virtual void doActivity() = 0;
	virtual void exitAction() = 0;
	virtual bool handleEvent(const Event& e){return false;};
};



#endif /* CONCRETESTATE_H_ */
