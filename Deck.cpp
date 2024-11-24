#include "Deck.h"
#include "CardFactory.h"

//TREATING BACK OF VECTOR OF CARD AS THE "TOP" OF THE DECK

// Constructor to reconstruct the deck from a file
Deck::Deck(std::istream& in, const CardFactory* factory) {
    std::string cardName;
    while (in >> cardName) {
        Card* card = factory->createCard(cardName);
        if (card) {
            this->push_back(card); // Add the card to the deck
        }
    }
}

// Draw a card from the top of the deck
Card* Deck::draw() {
    if (this->empty()) {
        throw std::out_of_range("Deck is empty. No more cards to draw.");
    }
    Card* topCard = this->back(); // get the top card
    this->pop_back();             // Remove it from the deck
    return topCard;
}

// Friend insertion operator<< to print all cards in the deck
std::ostream& operator<<(std::ostream& out, const Deck& deck) {
    for (const auto* card : deck) {
        card->print(out);
        out << " ";
    }
    return out;
}
