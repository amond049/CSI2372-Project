#pragma once
#include <string>
#include <iostream>

using namespace std

class Card {
	virtual int getCardsperCoin(int coins) = 0;
	virtual string getName() = 0;
	virtual void print(ostream& out) = 0;
};