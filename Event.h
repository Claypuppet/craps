/*
 * Event.h
 *
 *  Created on: Sep 25, 2017
 *      Author: klei
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <ostream>

class Event
{
public:
	Event(unsigned short aId);
	Event(const Event& e);
	virtual ~Event();
	Event operator=(const Event& e);
	bool operator==(const Event& e);
	unsigned short getId() const;

private:
	unsigned short id;
};

std::ostream& operator<<(std::ostream& os, const Event& e);

#endif /* EVENT_H_ */
