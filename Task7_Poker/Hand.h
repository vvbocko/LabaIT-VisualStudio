#pragma once

#include "Card.h"
#include "Rank.h"
#include "Deck.h"
#include <unordered_map>
#include <iostream>

class Hand 
{
private:
	std::vector<Card> hand;

public:
	Card drawCard();
	void sortHand();
	void clear() { hand.clear(); }
	const std::vector<Card>& GetCards() const { return hand; }
};