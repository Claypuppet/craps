/*
 * Dice.h
 *
 *  Created on: Sep 22, 2017
 *      Author: klei
 */

#ifndef DICE_H_
#define DICE_H_

#include <ostream>

typedef unsigned char dice_t;

class Dice
{
public:
	Dice(dice_t aSides = 6);
	Dice(const Dice& aDice);
	virtual ~Dice();
	void roll();
	dice_t getSides() const;
	dice_t getValue() const;
	unsigned long operator+(const Dice& aDice);
	bool operator==(const Dice& aDice);

private:
	dice_t sides;
	dice_t value;
};

std::ostream& operator <<(std::ostream& os, const Dice& dice);

#endif /* DICE_H_ */
