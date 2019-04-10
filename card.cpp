#include "Card.h"
#include <iostream>

using namespace std;

//Card Constructor should take a value and string that should be
//Hearts, Clubs, Spades, or Diamonds
Card::Card(int n, string s)
{
    cardNumber = 0;
    setNumericValue(n);
    setSuit(s);
}

//Allows tells the Card how to "print" itself
string Card::toString()
{
    string retVal;
    int cardNumber = getNumericValue();
    //If cardnumber > 10 then we need to change to J,Q,K,A
    if (cardNumber <= 10)
    {
        retVal = to_string(cardNumber);
    }
    else if(cardNumber == 11)
    {
        retVal = "Jack";
    }
    else if (cardNumber == 12)
    {
        retVal = "Queen";
    }
    else if (cardNumber == 13)
    {
        retVal = "King";
    }
    else if (cardNumber == 14)
    {
        retVal = "Ace";
    }

    retVal = retVal + " of " + getSuit();

    return retVal;
}
//Returns the numericValue
int Card::getNumericValue()
{
    return (cardNumber % 13) + 2;
}
//Sets the numericValue
void Card::setNumericValue(int n)
{
    int suitStart = cardNumber / 13;
    if (n >= 2 && n <= 14)
    {
        cardNumber = suitStart + n - 2;
    }
    else
    {
        cardNumber = suitStart;
    }
}
//Returns the Cards suit
string Card::getSuit()
{
    string suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    return suits[cardNumber / 13];
}
//Sets the Suit
void Card::setSuit(string s)
{
    if (s == "Clubs") 
    {
        cardNumber = getNumericValue() - 2;
    }
    else if (s == "Diamonds")
    {
        cardNumber = 13 + getNumericValue() - 2;
    }
    else if (s == "Hearts")
    {
        cardNumber = 26 + getNumericValue() - 2;
    }
    else if (s == "Spades")
    {
        cardNumber = 39 + getNumericValue() - 2;
    }
    else
    {
        cardNumber = getNumericValue() - 2;
    }
}

//To check if two cards are equal they need to have the same
//value and suit
bool Card::equal(Card testCard)
{
    bool retval = true;
    
    if(testCard.getSuit() != getSuit())
    {
        retval = false;
    }
    if(testCard.getNumericValue() != getNumericValue())
    {
        retval = false;
    }

    return retval;
}

