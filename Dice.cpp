/*
 * Dice.cpp
 *
 *  Created on: Sep 22, 2017
 *      Author: klei
 */

#include <random>

#include "Dice.h"
#include "core.h"


Dice::Dice(dice_t aSides) : sides(aSides)
{
	TRACE();
	roll();
}

Dice::Dice(const Dice& aDice)
{
	TRACE();
	sides = aDice.sides;
	roll();
}

Dice::~Dice()
{
	TRACE();
}

dice_t Dice::getSides() const
{
	TRACE();
	return sides;
}

void Dice::roll()
{
	TRACE();
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_real_distribution<> dis(0,1);
	value = (dis(gen) * sides) + 1;
}

unsigned long Dice::operator +(const Dice& aDice)
{
	TRACE();
	return value + aDice.value;
}

bool Dice::operator ==(const Dice& aDice)
{
	TRACE();
	return value == aDice.value;
}

dice_t Dice::getValue() const
{
	TRACE();
	return value;
}

std::ostream& operator <<(std::ostream& os, const Dice& dice){
	return os << "(1-" << static_cast<int>(dice.getSides()) << ")\t" << static_cast<int>(dice.getValue());
}

