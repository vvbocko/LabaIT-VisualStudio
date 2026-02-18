#pragma once

#include "Card.h"
#include "Rank.h"
#include "Hand.h"
#include <unordered_map>
#include <string>

class ScoreLogic
{
private:
	//int score = 0;

public:
	ScoreLogic();
	Rank checkHandRank(const Hand& hand);
	std::string toString(Rank& rank) const;
	//int countScore(Rank rank);
};