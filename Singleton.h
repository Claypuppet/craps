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
	Singleton(const Singleton&) = delete;
	Singleton& getInstace() { return sInstance; }
private:

	static Singleton sInstance;
};


#endif /* SINGLETON_H_ */
