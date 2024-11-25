#include "DiscardPile.h"

// adds a card to the discard pile
void DiscardPile::addCard(Card* card) {
    pile.push_back(card); // Add card to the end of the vector
}

// views the top card without removing it
Card* DiscardPile::top() const {
    if (pile.empty()) {
        throw std::out_of_range("DiscardPile is empty."); //edge case
    }
    return pile.back(); // Return the top card (last element)
}

// Remove and return the top card
Card* DiscardPile::removeCard() {
    if (pile.empty()){
       throw std::out_of_range("DiscardPile is empty."); //edge case 
    }

    Card* topCard = pile.back(); // top card
    pile.pop_back();             // removes it from the pile
    return topCard;

}

// printing the contents of the discard pile
void DiscardPile::print(std::ostream& out) const {
    for (const auto* card : pile) {
        card->print(out); // Prints each card using the `print` method we defiend
        out << " ";
    }

}

// serialize to output stream
std::ostream& operator<<(std::ostream& out, const DiscardPile& dp) {
    for (const auto* card : dp.pile) {
        card->print(out); // Use `print` to serialize each card
        out << " ";
    }
    return out;
}