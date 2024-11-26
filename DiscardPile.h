#pragma once
#include <vector>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class DiscardPile {
private:
    std::vector<Card*> pile; // Container for cards in the discard pile

public:
    // constructor to reconstruct DiscardPile from file
    DiscardPile(std::istream& in, const CardFactory* factory);

    // Add a card to the discard pile
    DiscardPile& operator+=(Card* card);

    //remove and return the top card from the discard pile
    Card* pickUp();

    // return (but do not remove) the top card from the discard pile
    Card* top() const;

    // Print all cards in the discard pile
    void print(std::ostream& out) const;

    // serialize the top card in the discard pile
    friend std::ostream& operator<<(std::ostream& out, const DiscardPile& dp);
};
