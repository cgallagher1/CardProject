#pragma once
#include "card.h"
#include "deck.h"
#include <iostream>
#include <vector>

using namespace std;

class PokerEvaluator 
{
public:
	PokerEvaluator();
	void dealHand();
	vector<Card> getHand();
	bool isPair();
	bool isPair(vector<Card> cards);
	bool isTwoPair();
	bool isTwoPair(vector<Card> cards);
	bool isThreeOfAKind();
	bool isThreeOfAKind(vector<Card> cards);
	bool isStraight();
	bool isStraight(vector<Card> cards);
	bool isFlush();
	bool isFlush(vector<Card> cards);
	bool isFullHouse();
	bool isFullHouse(vector<Card> cards);
	bool isFourOfAKind();
	bool isFourOfAKind(vector<Card> cards);
	bool isStraightFlush();
	bool isStraightFlush(vector<Card> cards);
	bool isRoyalFlush();
	bool isRoyalFlush(vector<Card> cards);

	string evaluate(vector<Card> cards);

	vector<Card> Hand;

private:
	
};