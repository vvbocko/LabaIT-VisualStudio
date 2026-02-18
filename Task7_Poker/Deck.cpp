// size of 52 cards    4 x 13 
// 
#include "Deck.h"

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

Deck::Deck()
{
	cardDeck.reserve(52);

	for (int s = 0; s < 4; s++)
	{
		for (int t = 2; t <= 14; t++)
		{
			cardDeck.push_back(Card((CardSuit)s, (CardType)t));
		}
	}
}

void Deck::shuffleDeck()
{
	int rng = rand();
	std::shuffle(cardDeck.begin(), cardDeck.end(), rng);
}

Card Deck::GetCard()
{
	Card card = cardDeck.back();
	cardDeck.pop_back();
	return card;
}



// Vector.push_back(6);					--> dodawanie na koncu vectora
// Vector.pop_back();					--> usuwanie z konca vectora
// Vector.back();						--> wez ostatnia karte z vectora
// Vector.begin();						--> 
// Vector.end();						--> 
// Vector.erase(it);					-->
// Vector.insert(Vector.begin(), 0);	--> dodawanie do vectora na dowolnej pozycji


