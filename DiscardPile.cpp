#include "DiscardPile.h"

// Constructor
DiscardPile::DiscardPile(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        Card* card = factory->createCard(cardName); //might need refactoring, placeholder as of now
        if (card) {
            pile.push_back(card);
        }
    }
}

// Add a card to the discard pile
DiscardPile& DiscardPile::operator+=(Card* card) {
    pile.push_back(card);
    return *this;
}

// Remove and return the top card
Card* DiscardPile::pickUp() {
    if (pile.empty()) {
        throw std::out_of_range("DiscardPile is empty.");
    }
    Card* topCard = pile.back();
    pile.pop_back();
    return topCard;
}

// Return the top card WITHOUT removing it
Card* DiscardPile::top() const {
    if (pile.empty()) {
        throw std::out_of_range("DiscardPile is empty.");
    }
    return pile.back();
}

// Print all cards in the discard pile
void DiscardPile::print(std::ostream& out) const {
    for (const auto* card : pile) {
        card->print(out);
        out << " ";
    }
}

// serialize the top card to outstream
std::ostream& operator<<(std::ostream& out, const DiscardPile& dp) {
    if (!dp.pile.empty()) {
        dp.pile.back()->print(out);
    }
    return out;
}
