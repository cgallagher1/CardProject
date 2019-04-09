#include <iostream>
#include<algorithm>
#include <vector>
#include "card.h"
#include "deck.h"
#include <map>
#include<ctime>
#include<cstdlib>

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

void Deck::shuffle()
{
	//call algorithm's random_shuffle method to shuffle the vector of Cards 
	random_shuffle(DeckOfCards.begin(), DeckOfCards.end());
}

bool Deck::equal(Deck testDeck)
{
    bool retval = true;

    if(testDeck.DeckOfCards.size() != DeckOfCards.size())
    {
        retval = false;
    }
    else
    {
        for(int i = 0; i < DeckOfCards.size(); i++)
        {
            if(DeckOfCards.at(i).equal(testDeck.DeckOfCards.at(i)) == false)
            {
                retval = false;
                break;
            }
        }
        
    }

    return retval;
}

void Deck::deal(int totalToDeal)
{
	try {
		if (DeckOfCards.size() < totalToDeal) {
			throw "Not enough cards";
		}
		else 
		{
			for (int i = 0; i < totalToDeal; i++) 
			{
				DeckOfCards.pop_back();
			}
		}
	}
	catch (string e){
		cout << "Error in Dealing: " << e << endl;
	}
}

bool Deck::isUnique()
{
	map<string, int> uniqueMap;


	for (int i = 0; i < DeckOfCards.size(); i++)
	{
		if (uniqueMap[DeckOfCards[i].toString()] == 1) {
			return false;
		}
		uniqueMap[DeckOfCards[i].toString()]++;
	}
	return true;
}

bool Deck::allThere()
{
	map<string, int> allThereMap;
	string key;
	string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
	for (int i = 0; i < 4; i++)
	{
		for (int num = 2; num <= 14; num++)
		{
			Card c(num, suits[i]);
			allThereMap[c.toString()]++;
		}
	}

	for (int i = 0; i < DeckOfCards.size(); i++) 
	{
		allThereMap[DeckOfCards[i].toString()]++;
	}

	for (map<string, int>::iterator it = allThereMap.begin(); it != allThereMap.end(); ++it) 
	{
		if (it->second != 2)
		{
			return false;
		}
	}
	return true;
}

vector<Card> Deck::getDeck()
{
	return DeckOfCards;
}


