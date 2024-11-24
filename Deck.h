#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class Deck : public std::vector<Card*> {
public:
    // reconstruct the deck from an input stream
    Deck(std::istream& in, const CardFactory* factory);

    // draw the top card from the deck
    Card* draw();

    // Friend operator<< to print the entire deck
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
};
