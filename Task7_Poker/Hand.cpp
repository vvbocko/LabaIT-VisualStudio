#include "Hand.h"
#include <vector>
//Hand::Hand()
//{
//
//}

void Hand::addCard(const Card& card, std::vector<Card>& playerCards)
{
    if (playerCards.size() < 5)
    {
        playerCards.push_back(card);
    }
}

// Vector.push_back(6);					--> dodawanie na koncu vectora
// Vector.pop_back();					--> usuwanie z konca vectora
// Vector.back();						--> wez ostatnia karte z vectora
// Vector.begin();						--> 
// Vector.end();						--> 
// Vector.erase(it);					-->
// Vector.insert(Vector.begin(), 0);	--> dodawanie do vectora na dowolnej pozycji