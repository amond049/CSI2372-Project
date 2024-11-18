
#include "Card.h"
#include <iostream> 
#include <string>   

class Black : public Card {

public:

    int getCardsperCoin(int coins) const override{

        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 5;
            case 4: return 6;
            default: return 0; // Handle invalid input
        }

    

    }

    std::string getName() const override{
        return "Black";
    }

    void print(std::ostream& out) const override {
        out << "b"; // flexible output
    }



};