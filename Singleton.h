/*
 * Singleton.h
 *
 *  Created on: 9 Oct 2017
 *      Author: Vuurvlieg
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_


template <typename T>
class Singleton
{
public:
	Singleton() = default;
	Singleton(const Singleton&) = delete;
	static T& getInstace() { static T sInstance; return sInstance; }
};


#endif /* SINGLETON_H_ */
