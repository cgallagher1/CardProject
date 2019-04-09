#pragma once
#include <iostream>
#include "card.h"
#include <vector>
#include <string>

using namespace std;

class Deck
{
public:
    Deck();
    
    int getLength();

    void shuffle();

    bool equal(Deck testDeck);

    void deal(int totalToDeal);

	bool isUnique();

	bool allThere();

	vector<Card> getDeck();

private:
vector <Card> DeckOfCards;
};
