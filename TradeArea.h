#pragma once
#include <list>
#include <string>
#include <iostream>
#include "Card.h"
#include "CardFactory.h"

class TradeArea {
private:
    std::list<Card*> tradeCards; // Container for cards in the trade area

public:
    // Constructor recreate tradearea from a file
    TradeArea(std::istream& in, const CardFactory* factory);

    // Add a card to the trade area operator overload
    TradeArea& operator+=(Card* card);

    // Check if a card can be legally added
    bool legal(Card* card) const;

    // Remove and return a card of the specified bean type
    Card* trade(const std::string& type);

    // Get the number of cards in the trade area
    int numCards() const;

    // Serialize all cards in the trade area
    friend std::ostream& operator<<(std::ostream& out, const TradeArea& ta);
};
