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

    string getSuit();

    void deal(int totalToDeal);

private:
vector <Card> DeckOfCards;
};
