#include <iostream>
using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "card.h"
#include "deck.h"

int main()
{
    cout << "Hello World!!!" << endl;

    Catch::Session().run();

    system("pause");

    return 0;
}

TEST_CASE("Test Cards")
{
    SECTION("Test create bad cards")
    {
        Card c1(-10, "Hearts");
        Card c2(10, "Fish");
        Card c3(-10, "Fish");

        REQUIRE(c1.getNumericValue() == 2);
        REQUIRE(c1.getSuit() == "Hearts");
        REQUIRE(c2.getNumericValue() == 10);
        REQUIRE(c2.getSuit() == "Clubs");
        REQUIRE(c3.getNumericValue() == 2);
        REQUIRE(c3.getSuit() == "Clubs");
    }

    SECTION("Test create 52 cards")
    {
        string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
        for (int i = 0; i < 4; i++)            
        {
            for (int num = 2; num <= 14; num++)
            {
                Card c(num, suits[i]);
                REQUIRE(c.getNumericValue() == num);
                REQUIRE(c.getSuit() == suits[i]);
            }
        }        
    }  
     
    SECTION("Test toString()")
    {
        Card c1(3, "Diamonds");
        Card c2(10, "Hearts");
        Card c3(14, "Spades");

        REQUIRE(c1.toString() == "3 of Diamonds");
        REQUIRE(c2.toString() == "10 of Hearts");
        REQUIRE(c3.toString() == "Ace of Spades");
    }

    SECTION("Test equivalence")
    {
        Card c1(3, "Diamonds");
        Card c2(3, "Diamonds");
        Card c3(14, "Spades");

        REQUIRE(c1.equal(c2) == true);
        REQUIRE(c1.equal(c3) == false);
    }
}

TEST_CASE("Test Deck")
{
    SECTION("Test create Deck")
    {
        Deck deck1;

        //Test Size
        REQUIRE(deck1.getLength() == 52);
    }

    SECTION("Test shuffle Deck")
    {
        Deck deck1;
        Deck deck2;

        //Shuffles deck 2
        deck2.shuffle();
        
        //Test to see if the decks are the same
        REQUIRE(deck1.equal(deck2) == false);
    }

    SECTION("Test Dealing")
    {
        Deck deck1;
        deck1.deal(5);

        REQUIRE(deck1.getLength() == 47);

		deck1.deal(7);

		REQUIRE(deck1.getLength() == 40);

		Deck deck2;

		REQUIRE(deck2.getLength() == 52);

    }
    
}

TEST_CASE("Test Evaluator")
{
	SECTION("Testing setup")
	{

		//create a deck
		PokerEvaluator pe;
		pe.dealCards();
		
		//7 hand poker check
		REQUIRE(pe.Hand.size() == 7);

		//Testing each hand

	    
		bool retval = false;

		//pairs
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//two pair
		for (int i = 0; i < ; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;


		//three OAK
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;


		//straight
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;


		//flush
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//full house
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//four of a kind
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//Straight flush
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//Royal Flush
		for (int i = 0; i < 5; i++)
		{
			pe.dealCards();
			if (pe.isPair(pe.Hand))
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;
}