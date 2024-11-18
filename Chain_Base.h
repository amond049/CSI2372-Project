#pragma once
#include <iostream>
#include <string>
#include "Card.h"



//abstract chain  interface

class Chain_Base{
    public:
        virtual ~Chain_Base() = default; // Virtual destructor for proper cleanup

        // Add a card to the chain
        virtual Chain_Base& operator+=(Card* card) = 0;

        //sell chain and calculate total value
        virtual int sell() const = 0;

        //print the chain
        virtual void print (std::ostream& out) const = 0;

        // Friend insertion operator for printing
    friend std::ostream& operator<<(std::ostream& out, const Chain_Base& chain) {
        chain.print(out); // delegate to the derived class's print() method
        return out;
    }

};