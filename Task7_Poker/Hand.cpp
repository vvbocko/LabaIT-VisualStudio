#include "Hand.h"
#include <vector>
#include <iostream>


//Hand::Hand()
//{
//
//}

void Hand::addCard(const Card& card)
{
    if (handCards.size() < 5)
    {
        handCards.push_back(card);
    }
}

Card Hand::putBackCard(Card& card)
{
	handCards.push_back(card);
	return card;
}


// Vector.push_back(6);					--> dodawanie na koncu vectora
// Vector.pop_back();					--> usuwanie z konca vectora
// Vector.back();						--> wez ostatnia karte z vectora
// Vector.begin();						--> 
// Vector.end();						--> 
// Vector.erase(it);					-->
// Vector.insert(Vector.begin(), 0);	--> dodawanie do vectora na dowolnej pozycji