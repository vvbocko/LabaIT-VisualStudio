#pragma once

#include "Card.h"

#include <vector>
#include <iostream>

class Deck
{
private:
	std::vector<Card> cardDeck;

public:
	void shuffleDeck();
	Card GetCard();
};