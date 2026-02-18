#pragma once

#include "Card.h"

#include <vector>
#include <iostream>

class Deck
{
private:
	std::vector<Card> cardDeck;

public:
	Deck();
	void shuffleDeck();
	bool hasCards();
	Card GetCard();
};