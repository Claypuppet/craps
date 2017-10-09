/*
 * Context.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */
#include <iostream>
#include "Context.h"
#include "core.h"

Context::Context()
{
	TRACE();
}

Context::~Context()
{
	TRACE();
}

const statePtr& Context::getState() const
{
	TRACE();
	return currentState;
}

void Context::setState(const statePtr& aState)
{
	TRACE();
	if (currentState != NULL)
	{
		currentState->exitAction();
	}
	currentState = aState;
	currentState->entryAction();
}

void Context::scheduleEvent(const Event& e)
{
	TRACE();
	events.push(e);
}

void Context::run()
{
	TRACE();
	while(!events.empty()){
		Event e = events.front();
		events.pop();
		currentState->handleEvent(e, *this);
	}
}
