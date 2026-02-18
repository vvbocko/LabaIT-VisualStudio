#pragma once

#include "Card.h"
#include "Rank.h"
#include <unordered_map>
#include <iostream>

class Hand 
{
public:
	std::vector<Card> handCards;

	void addCard(const Card& card);
	Card putBackCard(Card& card);

	void clear() { handCards.clear(); }
	const std::vector<Card>& GetCards() const { return handCards; }
};