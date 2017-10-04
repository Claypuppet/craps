/*
 * Event.cpp
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#include <iostream>
#include "Event.h"

Event::Event(unsigned short aId) :
		id(aId)
{
}

Event::Event(const Event& e) :
		id(e.id)
{

}

Event::~Event()
{
}

bool Event::operator==(const Event& e)
{
	return e.id == id;
}

Event Event::operator =(const Event& e)
{
	if(this != &e){
		id = e.id;
	}
	return *this;
}

unsigned short Event::getId() const
{
	return id;
}


std::ostream& operator<<(std::ostream& os, const Event& e){
	return os << e.getId();
}



