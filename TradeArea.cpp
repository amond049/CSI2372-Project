#include "TradeArea.h"

// Constructor to reconstruct the trade area from a file
TradeArea::TradeArea(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        Card* card = factory->createCard(cardName); //might need refactoring, placeholder as of now
        if (card) {
            tradeCards.push_back(card);
        }
    }
}

// Add a card to the trade area
TradeArea& TradeArea::operator+=(Card* card) {
    tradeCards.push_back(card);
    return *this;
}

bool TradeArea::legal(Card* card) const {
    for (const auto* tradeCard : tradeCards) {
        if (tradeCard->getName() == card->getName()) { // Check if a card can be legally added
            return true;
        }
    }
    return false;
}

// Remove and return a card of the specified type
Card* TradeArea::trade(const std::string& type) {
    for (auto it = tradeCards.begin(); it != tradeCards.end(); ++it) { //iterate through container tradeCard look for match to type string
        if ((*it)->getName() == type) {
            Card* card = *it;
            tradeCards.erase(it);
            return card;
        }
    }
    return nullptr; // Card not found
}

// Get num of cards
int TradeArea::numCards() const {
    return tradeCards.size();
}

// Serialize all cards in the trade area
std::ostream& operator<<(std::ostream& out, const TradeArea& ta) {
    for (const auto* card : ta.tradeCards) {
        card->print(out);
        out << " ";
    }
    return out;
}
