#pragma once
#include "CardType.h"
#include "CardSuit.h"

class Card 
{
private:
	CardSuit suit; 
	CardType type;

public:
	Card(CardSuit suit, CardType type);

	CardSuit GetSuit() const { return suit; }
	CardType GetType() const { return type; }
};