// size of 52 cards    4 x 13 
// 
#include "Deck.h"

#include <vector>
#include <iostream>
#include <random>
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
	random_device rd;
	mt19937_64 rng(rd());
	std::shuffle(cardDeck.begin(), cardDeck.end(), rng);
}

Card Deck::GetCard()
{
	Card card = cardDeck.back();
	cardDeck.pop_back();
	return card;
}

bool Deck::hasCards()
{
	if (cardDeck.size() < 5 && !cardDeck.empty())
	{
		return true;
	}
	else { return false; }
}



// Vector.push_back(6);					--> dodawanie na koncu vectora
// Vector.pop_back();					--> usuwanie z konca vectora
// Vector.back();						--> wez ostatnia karte z vectora
// Vector.begin();						--> 
// Vector.end();						--> 
// Vector.erase(it);					-->
// Vector.insert(Vector.begin(), 0);	--> dodawanie do vectora na dowolnej pozycji


