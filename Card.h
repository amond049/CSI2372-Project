#pragma once
#include <string>
#include <iostream>

using namespace std;

class Card {
	public:
		virtual ~Card() {} // virt destructor for proper cleanup
		virtual int getCardsperCoin(int coins) const = 0;
		virtual string getName() const = 0;
		virtual void print(ostream& out) const = 0;
};


