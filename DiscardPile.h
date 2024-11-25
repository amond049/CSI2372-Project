#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include <stdexcept>

class DiscardPile{
    private:
        std::vector<Card*> pile; // Container to hold discarded cards

    public:
        //add card to pile

        void addCard (Card* card);

        //view the top card of the discard pile but don't remove it

        Card* top() const;

        // remove and return the top card

        Card* removeCard();

        //print discard pile contents

        void print (std::ostream& out) const;

        //Friend operator << for serialization
        friend std::ostream& operator<<(std::ostream& out, const DiscardPile& dp);






};

