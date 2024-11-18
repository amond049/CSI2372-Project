
#include "Card.h"
#include <iostream> 
#include <string>   

class Green : public Card {

public:

    int getCardsperCoin(int coins) const override{

        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 6;
            case 4: return 7;
            default: return 0; // Handle invalid input
        }

    

    }

    std::string getName() const override{
        return "Green";
    }

    void print(std::ostream& out) const override {
        out << "G"; // flexible output
    }



};