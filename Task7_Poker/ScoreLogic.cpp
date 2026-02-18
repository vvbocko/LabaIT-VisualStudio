#include "ScoreLogic.h"
#include <map>
#include <iostream>

using namespace std;

ScoreLogic::ScoreLogic() 
{
	int score = 0;
}

Rank ScoreLogic::checkHandRank(const Hand& hand)
{
    std::map <CardType, int> typeCounts;
    std::map <CardSuit, int> suitCounts;

    for (const Card& card : hand.GetCards()) //go through every card in deck and increment int by caardType
    {
        typeCounts[card.GetType()]++;
        suitCounts[card.GetSuit()]++;
    }

    //the same
    int pairCount = 0;
    bool threeAKind = false;
    bool fourAKind = false;
    
    for (const pair<const CardType, int>& element1 : typeCounts)
    {
        if (element1.second == 4) fourAKind = true;       // element.first -> cardtype | element.second -> ilosc
        if (element1.second == 3) threeAKind = true;
        if (element1.second == 2) pairCount++;

    }

    //squence
    bool hasAce = false;
    bool straight = false;
 
    for (const pair<const CardType, int>& element : typeCounts)
    {
        if (typeCounts.size() == 5) 
        {
            int first = (int)typeCounts.begin()->first;
            int last = (int)typeCounts.rbegin()->first;

            if (last - first == 4) 
            {
                straight = true;
            }
            if (last == 14)
            { 
                hasAce = true; 
            }
        }
    }
    
    //same suits
    int suitCount = 0;
    bool flush = false;
  
    for (const pair<const CardSuit, int>& element : suitCounts)
    {
        if (element.second == 5) 
        {
            flush = true;
        }
    }

    if (hasAce && straight && flush)
    {
        return Rank::RoyalFlush;
    }
    if (straight && flush)
    {
        return Rank::StraightFlush;
    }
    else if (straight)
    {
        return Rank::Straight;
    }
    else if (flush) 
    {
        return Rank::Flush;
    }
    if (fourAKind) 
    { 
        return Rank::FourOfAKind; 
    }
    if (threeAKind && pairCount >= 1) 
    { 
        return Rank::FullHouse; 
    }
    if (threeAKind) 
    { 
        return Rank::ThreeOfAKind; 
    }
    if (pairCount == 2) 
    { 
        return Rank::TwoPair; 
    }
    if (pairCount == 1) 
    { 
        return Rank::OnePair; 
    }
    else 
    { 
        return Rank::HighCard; 
    }
}