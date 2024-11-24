#pragma once
#include "Chain_Base.h"
#include "Card.h"
#include <vector>
#include <stdexcept>


template <typename T>
class Chain : public Chain_Base {
private:
    std::vector<T*> cards; //Store cards of Type T

public:
    // Constructor for loading from a file (istream)
    Chain (std::istream& in, const CardFactory* factory){
        std::string cardName;
        while (in >> cardName){
            T* card = dynamic_cast<T*>(factory->createCard(cardName));
            if (card){
                cards.push_back(card); //insert at back
            }else{
                throw std::invalid_argument("Invalid card type in input stream.");
            }
            }
        }


    Chain<T>& operator+=(Card* card) override{
        T* specificCard =dynamic_cast<T*>(card);
        if (specificCard) {
            cards.push_back(specificCard);//push to back of vector 
        } else {
            throw std::invalid_argument("IllegalType: Card does not match chain type.");
        }
        return *this;
    }

    // Sell the chain
    int sell() const override {
        if (cards.empty()) return 0;

        int cardsPerCoin = cards.front()->getCardsPerCoin(1); //use first card to get rate
        return cards.size() / cardsPerCoin; //divide by size to get chain value
    }

    // printing the chain
    void print(std::ostream& out) const override {
        if (!cards.empty()) {
            out << cards.front()->getName() << " Chain: ";
            for (const auto* card : cards) {
                card->print(out);
                out << " ";
            }
        }
    }

    };

     







