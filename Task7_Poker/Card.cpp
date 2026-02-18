#include "Card.h"

Card::Card(CardSuit s, CardType t) : suit(s) , type(t)
{

}

std::string Card::toString() const
{
    std::string ranks[] = { "", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    std::string suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    return ranks[(int)type] + " of " + suits[(int)suit];

}