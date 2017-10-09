/*
 * Event.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#include <iostream>
#include "Event.h"
#include "core.h"

Event::Event(unsigned short aId) :
		id(aId)
{
	TRACE();
}

Event::Event(const Event& e) :
		id(e.id)
{
	TRACE();
}

Event::~Event()
{
	TRACE();
}

bool Event::operator==(const Event& e)
{
	TRACE();
	return e.id == id;
}

Event Event::operator =(const Event& e)
{
	TRACE();
	if(this != &e){
		id = e.id;
	}
	return *this;
}

unsigned short Event::getId() const
{
	TRACE();
	return id;
}


std::ostream& operator<<(std::ostream& os, const Event& e){
	return os << e.getId();
}



