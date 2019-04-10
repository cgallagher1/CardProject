#include "PokerEvaluator.h"
#include "deck.h"
#include "card.h"
#include <algorithm>

//Construct the PokerEvaluator(PE)
PokerEvaluator::PokerEvaluator()
{

}

//Sort by numbers
bool compareNumeric(Card a, Card b) {
	return a.getNumericValue() < b.getNumericValue();
}

//Sort Alphabetically
bool compareSuit(Card a, Card b) {
	return a.getSuit() < b.getSuit();
}

//dealHands creates a deck, shuffles it, and then draws 7 cards and
//adds those 7 cards to the vector of Cards called Hand
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


//Returns the Hand
vector<Card> PokerEvaluator::getHand()
{
	return Hand;
}

//Is Pair without a parameter simply returns true
//if the private member Hand has a Pair
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

//Is Pair with a parameter returns true
//if the cards that were passed in have a pair in them
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

//Is Two Pair without a parameter simply returns true
//if the private member Hand has Two Pair
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

//Is Two Pair with a parameter returns true
//if the cards that were passed in have Two Pair
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

//Is Three Of A Kind without a parameter simply returns true
//if the private member Hand has Three Of A Kind
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

//Is Three Of A Kind with a parameter returns true
//if the cards passed in have a Three Of A Kind
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

//Is Straight without a parameter simply returns true
//if the private member Hand has a Straight
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

//Is Straight with a parameter simply true
//if the cards passed in have a Straight
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

//Is Flush without a parameter simply returns true
//if the private member Hand has a Flush
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

//Is Flush with a parameter returns true
//if the cards passed in have a Flush
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

//Is Full House without a parameter simply returns true
//if the private member Hand has a Full House
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

//Is Full House with a parameter returns true
//if the cards passed in have a Full House
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

//Is Four of a Kind without a parameter returns true
//if the private member Hand has a Flush
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

//Is Four of a Kind with a parameter returns true
//if the cards passed in have Four Of A Kind
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

//Is Four of a Kind without a parameter returns true
//if the private member Hand has a Flush
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

//Is Straigh Flush with a parameter returns true
//if the passed in cards have a Straight Flush
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

//Is Royal Flush without a parameter simply returns true
//if the private member Hand has a Royal Flush
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

//Is Royal Flush with a parameter returns true
//if the cards passed in have a Royal Flush
bool PokerEvaluator::isRoyalFlush(vector<Card> cards)
{
	bool retval = false;
	sort(cards.begin(), cards.end(), compareSuit);
	vector <Card> onlyCardsInFlush;
	int counter = 1;

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i].getNumericValue() < 10) {
			cards.erase(cards.begin() + i);
			i--;
		}
	}

	if (cards.size() < 5) {
		return false;
	}

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

//Evaluates the 7 cards passed in and starts at the top at the heiarchy
//and returns the best hand
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