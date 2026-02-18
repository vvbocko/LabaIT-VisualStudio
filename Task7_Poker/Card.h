#pragma once
#include <ostream>
#include <string>
#include "CardType.h"
#include "CardSuit.h"

class Card 
{
private:
	CardSuit suit; 
	CardType type;

public:
	Card(CardSuit suit, CardType type);

	CardSuit getSuit() const { return suit; }
	CardType getType() const { return type; }

	std::string toString() const;
};