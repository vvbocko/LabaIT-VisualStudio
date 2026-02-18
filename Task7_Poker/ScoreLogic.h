#pragma once

#include "Card.h"
#include "Rank.h"
#include "Hand.h"
#include <unordered_map>

class ScoreLogic
{
private:
	//int score = 0;

public:
	Rank checkHandRank(const Hand& hand);
	int countScore(Rank rank);
};