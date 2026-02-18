#pragma once

#include "Card.h"
#include "Rank.h"
#include <vector>

class Hand 
{
public:
	std::vector<Card> humanCards;
	std::vector<Card> botCards;

	void addCard(const Card& card, std::vector<Card>& playerCards);

	const std::vector<Card>& getPlayerCards(std::vector<Card> playerCards) const { return playerCards; }
};