#pragma once
#include <string>

using namespace std;

class Card
{
public:
    Card(int n, string s);
    
    string toString();

    int getNumericValue();
    void setNumericValue(int n);

    string getSuit();
    void setSuit(string s);

    bool equal(Card testCard);

private:
    int cardNumber;
};