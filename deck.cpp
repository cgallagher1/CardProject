#include <iostream>
#include <vector>
#include "card.h"
#include "deck.h"

using namespace std;

using namespace std;

Deck::Deck()
{
	for (unsigned int i = 2; i < 15; i++)
	{
		Card TempCard(i, "Hearts");
		DeckOfCards.push_back(TempCard);
	}

	for (unsigned int i = 2; i < 15; i++)
	{
		Card Tempcard(i, "Spades");
		DeckOfCards.push_back(Tempcard);
	}

	for (unsigned int i = 2; i < 15; i++)
	{
		Card Tempcard(i, "Clubs");
		DeckOfCards.push_back(Tempcard);
	}

	for (unsigned int i = 2; i < 15; i++)
	{
		Card Tempcard(i, "Diamonds");
		DeckOfCards.push_back(Tempcard);
	}

}

int Deck::getLength()
{
    return DeckOfCards.size();
}