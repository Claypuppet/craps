/*
 * Context.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */
#include <iostream>
#include "Context.h"

Context::Context()
{
}

Context::~Context()
{
}

const statePtr& Context::getState() const
{
	return currentState;
}

void Context::setState(const statePtr& aState)
{
	if (currentState != NULL)
	{
		currentState->exitAction();
	}
	currentState = aState;
	currentState->entryAction();
}

void Context::scheduleEvent(const Event& e)
{
	events.push(e);
}

void Context::run()
{
	while(!events.empty()){
		Event e = events.front();
		events.pop();
		currentState->handleEvent(e, *this);
	}
}
