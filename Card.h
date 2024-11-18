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

		 // Global stream insertion operator using the idiom mentioned in the instructions (operator override)
    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out); // call the virtual print() function
        return out;
    }
};


