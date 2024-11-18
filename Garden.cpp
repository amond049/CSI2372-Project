
#include "Card.h"
#include <iostream> 
#include <string>   

class Garden : public Card {

public:

    int getCardsperCoin(int coins) const override{

        switch (coins) {
            case 2: return 2;
            case 3: return 3;
            default: return 0; // Handle invalid input
        }

    

    }

    std::string getName() const override{
        return "Garden";
    }

    void print(std::ostream& out) const override {
        out << "g"; // flexible output
    }



};