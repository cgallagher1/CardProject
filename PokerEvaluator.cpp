#include "PokerEvaluator.h"
#include "deck.h"
#include "card.h"
#include <algorithm>

PokerEvaluator::PokerEvaluator()
{

}

bool compareNumeric(Card a, Card b) {
	return a.getNumericValue() < b.getNumericValue();
}

bool compareSuit(Card a, Card b) {
	return a.getSuit() < b.getSuit();
}

void PokerEvaluator::dealHand()
{
	Deck deck;
	Card card(2,"Spades");
	deck.shuffle();
	Hand.clear();
	for (int i = 0; i < 7; i++)
	{
	
		Hand.push_back(deck.getDeck()[i]);
	}

	sort(Hand.begin(), Hand.end(), compareNumeric);
}



vector<Card> PokerEvaluator::getHand()
{
	return Hand;
}

bool PokerEvaluator::isPair()
{
	dealHand();
	bool retval = false;
	for (int i = 0; i < Hand.size() - 1; i++) {
		if (Hand[i].getNumericValue() == Hand[i + 1].getNumericValue())
		{		
			retval = true;
		}
	}

	return retval;
}

bool PokerEvaluator::isPair(vector<Card> cards)
{
	bool retval = false;
	for (int i = 0; i < cards.size() - 1; i++) {
		if (cards[i].getNumericValue() == cards[i + 1].getNumericValue())
		{
			retval = true;
		}
	}

	return retval;
}

//Checks if the deal is two pair
bool PokerEvaluator::isTwoPair()
{
	dealHand();
	bool retval = false;
	for (unsigned int i = 0; i < Hand.size() - 1; i++)
	{
		//Find first pair
		if (Hand[i].getNumericValue() == Hand[i + 1].getNumericValue())
		{
			Card temp = Hand[i];
			//Finds Second pair and makes sure it's not the same as the first
			for (unsigned int j = 0; j < Hand.size() - 1; j++)
			{
				if (Hand[j].getNumericValue() == Hand[j + 1].getNumericValue() && Hand[j].getNumericValue() != temp.getNumericValue())
				{
					retval = true;
					break;
				}
			}

		}
	}
	return retval;
}

//Checks if the deal is two pair
bool PokerEvaluator::isTwoPair(vector<Card> cards)
{
	bool retval = false;
	for (unsigned int i = 0; i < cards.size() - 1; i++)
	{
		//Find first pair
		if (cards[i].getNumericValue() == cards[i + 1].getNumericValue())
		{
			Card temp = cards[i];
			//Finds Second pair and makes sure it's not the same as the first
			for (unsigned int j = 0; j < cards.size() - 1; j++)
			{
				if (cards[j].getNumericValue() == cards[j + 1].getNumericValue() && cards[j].getNumericValue() != temp.getNumericValue())
				{
					retval = true;
					break;
				}
			}

		}
	}
	return retval;
}

//Checks if the deal is three of a kind
bool PokerEvaluator::isThreeOfAKind()
{
	dealHand();
	bool retval = false;
	//For Three of a kind only need to check up to last 2 spots or else overflows
	for (unsigned int i = 0; i < Hand.size() - 2; i++)
	{
		if (Hand[i].getNumericValue() == Hand[i + 1].getNumericValue() && Hand[i].getNumericValue() == Hand[i + 2].getNumericValue())
		{
			retval = true;
			break;
		}
	}
	return retval;
}

//Checks if the deal is three of a kind
bool PokerEvaluator::isThreeOfAKind(vector<Card> cards)
{
	bool retval = false;
	//For Three of a kind only need to check up to last 2 spots or else overflows
	for (unsigned int i = 0; i < cards.size() - 2; i++)
	{
		if (cards[i].getNumericValue() == cards[i + 1].getNumericValue() && cards[i].getNumericValue() == cards[i + 2].getNumericValue())
		{
			retval = true;
			break;
		}
	}
	return retval;
}

//Checks if the deal is a straight
bool PokerEvaluator::isStraight()
{
	dealHand();
	bool retval = false;
	vector <Card> inStraight;
	inStraight.push_back(Hand[0]);
	for (unsigned int i = 0; i < Hand.size() - 1; i++)
	{
		bool alreadythere = false;
		for (unsigned int j = 0; j < inStraight.size(); j++)
		{
			if (inStraight[j].getNumericValue() == Hand[i + 1].getNumericValue())
			{
				alreadythere = true;
			}
		}
		if (alreadythere == true)
		{
			continue;
		}
		else if (((Hand[i].getNumericValue()) + 1) == (Hand[i + 1].getNumericValue()))
		{
			inStraight.push_back(Hand[i + 1]);
			if (inStraight.size() == 5)
			{
				retval = true;
				break;
			}
		}
		else
		{
			inStraight.clear();
			inStraight.push_back(Hand[i + 1]);
		}
	}

	return retval;
}

bool PokerEvaluator::isStraight(vector<Card> cards)
{
	bool retval = false;
	vector <Card> inStraight;
	inStraight.push_back(cards[0]);
	for (unsigned int i = 0; i < cards.size() - 1; i++)
	{
		bool alreadythere = false;
		for (unsigned int j = 0; j < inStraight.size(); j++)
		{
			if (inStraight[j].getNumericValue() == cards[i + 1].getNumericValue())
			{
				alreadythere = true;
			}
		}
		if (alreadythere == true)
		{
			continue;
		}
		else if (((cards[i].getNumericValue()) + 1) == (cards[i + 1].getNumericValue()))
		{
			inStraight.push_back(cards[i + 1]);
			if (inStraight.size() == 5)
			{
				retval = true;
				break;
			}
		}
		else
		{
			inStraight.clear();
			inStraight.push_back(cards[i + 1]);
		}
	}

	return retval;
}

//Checks if the deal is a flush
bool PokerEvaluator::isFlush()
{
	bool retval = false;
	int counter = 1;
	dealHand();
	sort(Hand.begin(), Hand.end(), compareSuit);
	for (unsigned int i = 0; i < Hand.size() - 1; i++)
	{
		if (Hand[i].getSuit() == Hand[i + 1].getSuit())
		{
			counter++;
			if (counter == 5)
			{
				retval = true;
				break;
			}
		}
		else
		{
			counter = 1;
		}
	}

	return retval;
}

//Checks if the deal is a flush
bool PokerEvaluator::isFlush(vector<Card> cards)
{
	bool retval = false;
	int counter = 1;
	sort(cards.begin(), cards.end(), compareSuit);
	for (unsigned int i = 0; i < cards.size() - 1; i++)
	{
		if (cards[i].getSuit() == cards[i + 1].getSuit())
		{
			counter++;
			if (counter == 5)
			{
				retval = true;
				break;
			}
		}
		else
		{
			counter = 1;
		}
	}

	return retval;
}

//Checks if the deal is a full house
bool PokerEvaluator::isFullHouse()
{
	dealHand();
	bool retval = false;
	if (isTwoPair())
	{
		if (isThreeOfAKind())
		{
			retval = true;
		}
	}
	return retval;
}

//Checks if the deal is a full house
bool PokerEvaluator::isFullHouse(vector<Card> cards)
{
	bool retval = false;
	if (isTwoPair(cards))
	{
		if (isThreeOfAKind(cards))
		{
			retval = true;
		}
	}
	return retval;
}

bool PokerEvaluator::isFourOfAKind()
{
	dealHand();
	bool retval = false;
	for (unsigned int i = 0; i < Hand.size() - 3; i++)
	{
		if (Hand[i].getNumericValue() == Hand[i + 1].getNumericValue())
		{
			if (Hand[i].getNumericValue() == Hand[i + 2].getNumericValue())
			{
				if (Hand[i].getNumericValue() == Hand[i + 3].getNumericValue())
				{
					retval = true;
				}
			}
		}
	}
	return retval;
}


bool PokerEvaluator::isFourOfAKind(vector<Card> cards)
{
	bool retval = false;
	for (unsigned int i = 0; i < cards.size() - 3; i++)
	{
		if (cards[i].getNumericValue() == cards[i + 1].getNumericValue())
		{
			if (cards[i].getNumericValue() == cards[i + 2].getNumericValue())
			{
				if (cards[i].getNumericValue() == cards[i + 3].getNumericValue())
				{
					retval = true;
				}
			}
		}
	}
	return retval;
}

//Checks if the deal is a straight flush
bool PokerEvaluator::isStraightFlush()
{
	dealHand();
	bool retval = false;
	vector <Card> onlyCardsInFlush;
	int counter = 1;
	sort(Hand.begin(), Hand.end(), compareSuit);
	for (unsigned int i = 0; i < Hand.size() - 1; i++)
	{
		onlyCardsInFlush.push_back(Hand[i]);
		if (Hand[i].getSuit() == Hand[i + 1].getSuit())
		{
			counter++;
			onlyCardsInFlush.push_back(Hand[i + 1]);
			if (counter == 5)
			{
				sort(onlyCardsInFlush.begin(), onlyCardsInFlush.end(), compareNumeric);
				if (isStraight(onlyCardsInFlush))
				{
					retval = true;
				}
			}
		}
		else
		{
			counter = 1;
			onlyCardsInFlush.clear();
		}
	}
	return retval;
}

//Checks if the deal is a straight flush
bool PokerEvaluator::isStraightFlush(vector<Card> cards)
{
	bool retval = false;
	vector <Card> onlyCardsInFlush;
	int counter = 1;
	sort(cards.begin(), cards.end(), compareSuit);
	for (unsigned int i = 0; i < cards.size() - 1; i++)
	{
		onlyCardsInFlush.push_back(cards[i]);
		if (cards[i].getSuit() == cards[i + 1].getSuit())
		{
			counter++;
			onlyCardsInFlush.push_back(cards[i + 1]);
			if (counter == 5)
			{
				sort(onlyCardsInFlush.begin(), onlyCardsInFlush.end(), compareNumeric);
				if (isStraight(onlyCardsInFlush))
				{
					retval = true;
				}
			}
		}
		else
		{
			counter = 1;
			onlyCardsInFlush.clear();
		}
	}
	return retval;
}

//Checks if the deal is a royal flush
bool PokerEvaluator::isRoyalFlush()
{
	dealHand();
	bool retval = false;
	sort(Hand.begin(), Hand.end(), compareSuit);
	vector <Card> onlyCardsInFlush;
	int counter = 1;
	for (unsigned int i = 0; i < Hand.size() - 1; i++)
	{
		onlyCardsInFlush.push_back(Hand[i]);
		if (Hand[i].getSuit() == Hand[i + 1].getSuit())
		{
			counter++;
			onlyCardsInFlush.push_back(Hand[i + 1]);
			if (counter == 5)
			{
				sort(onlyCardsInFlush.begin(), onlyCardsInFlush.end(), compareNumeric);
				if (isStraight(onlyCardsInFlush))
				{
					if (onlyCardsInFlush[onlyCardsInFlush.size() - 1].getNumericValue() == 14)
					{
						retval = true;
					}
				}
			}
		}
		else
		{
			counter = 1;
			onlyCardsInFlush.clear();
		}
	}

	return retval;
}

//Checks if the deal is a royal flush
bool PokerEvaluator::isRoyalFlush(vector<Card> cards)
{
	bool retval = false;
	sort(cards.begin(), cards.end(), compareSuit);
	vector <Card> onlyCardsInFlush;
	int counter = 1;
	for (unsigned int i = 0; i < cards.size() - 1; i++)
	{
		onlyCardsInFlush.push_back(cards[i]);
		if (cards[i].getSuit() == cards[i + 1].getSuit())
		{
			counter++;
			onlyCardsInFlush.push_back(cards[i + 1]);
			if (counter == 5)
			{
				sort(onlyCardsInFlush.begin(), onlyCardsInFlush.end(), compareNumeric);
				if (isStraight(onlyCardsInFlush))
				{
					if (onlyCardsInFlush[onlyCardsInFlush.size() - 1].getNumericValue() == 14)
					{
						retval = true;
					}
				}
			}
		}
		else
		{
			counter = 1;
			onlyCardsInFlush.clear();
		}
	}

	return retval;
}

string PokerEvaluator::evaluate(vector<Card> cards) {
	sort(cards.begin(), cards.end(), compareNumeric);
	if (isRoyalFlush(cards))
	{
		return "Royal Flush";
	}
	else if (isStraightFlush(cards))
	{
		return "Straight Flush";
	}
	else if (isFlush(cards))
	{
		return "Flush";
	}
	else if (isFourOfAKind(cards))
	{
		return "Four of a Kind";
	}
	else if (isFullHouse(cards))
	{
		return "Full House";
	}
	else if (isStraight(cards))
	{
		return "Straight";
	}
	else if (isThreeOfAKind(cards))
	{
		return "Three of a Kind";
	}
	else if (isTwoPair(cards))
	{
		return "Two Pair";
	}
	else if (isPair(cards))
	{
		return "Pair";
	}
	else
	{
		return "High Card";
	}
}