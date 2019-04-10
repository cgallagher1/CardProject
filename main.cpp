#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "card.h"
#include "deck.h"
#include "PokerEvaluator.h"

int main()
{
	srand(unsigned(time(0)));
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

	SECTION("Validation")
	{
		Deck deck1;

		REQUIRE(deck1.isUnique() == true);
		REQUIRE(deck1.allThere() == true);
	}
    
}

TEST_CASE("Test Evaluator")
{
	SECTION("Testing setup")
	{

		//create a deck
		PokerEvaluator pe;
		pe.dealHand();

		//7 hand poker check
		REQUIRE(pe.getHand().size() == 7);

		//Testing each hand

	    
		bool retval = false;

		//pairs
		for (int i = 0; i < 5; i++)
		{			
			if (pe.isPair())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//two pair
		for (int i = 0; i < 25; i++)
		{
			if (pe.isTwoPair())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;


		//three OAK
		for (int i = 0; i < 50; i++)
		{
			if (pe.isThreeOfAKind())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;


		//straight
		for (int i = 0; i < 300; i++)
		{
			if (pe.isStraight())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;


		//flush
		for (int i = 0; i < 600; i++)
		{
			if (pe.isFlush())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//full house
		for (int i = 0; i < 800; i++)
		{
			if (pe.isFullHouse())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//four of a kind
		for (int i = 0; i < 5000; i++)
		{
			if (pe.isFourOfAKind())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//Straight flush
		for (int i = 0; i < 80000; i++)
		{
			if (pe.isStraightFlush())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);
		retval = false;

		//Royal Flush
		for (int i = 0; i < 1000000; i++)
		{
			if (pe.isRoyalFlush())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);



		//Evaluate
		vector<Card> testHighCard = {
			Card(2, "Spades"),
			Card(4, "Hearts"),
			Card(6, "Clubs"),
			Card(10, "Clubs"),
			Card(8, "Hearts"),
			Card(9, "Hearts"),
			Card(14, "Diamonds"),
		};

		REQUIRE(pe.evaluate(testHighCard) == "High Card");

		vector<Card> testPair = {
			Card(2, "Spades"),
			Card(4, "Hearts"),
			Card(6, "Clubs"),
			Card(10, "Clubs"),
			Card(8, "Hearts"),
			Card(9, "Hearts"),
			Card(2, "Diamonds"),
		};

		REQUIRE(pe.evaluate(testPair) == "Pair");

		vector<Card> testStraight = {
			Card(2, "Spades"),
			Card(9, "Hearts"),
			Card(6, "Clubs"),
			Card(4, "Clubs"),
			Card(5, "Hearts"),
			Card(3, "Hearts"),
			Card(2, "Diamonds"),
		};

		REQUIRE(pe.evaluate(testStraight) == "Straight");

		vector<Card> testFlush = {
			Card(5, "Hearts"),
			Card(9, "Hearts"),
			Card(6, "Hearts"),
			Card(4, "Clubs"),
			Card(11, "Hearts"),
			Card(3, "Spades"),
			Card(2, "Hearts"),
		};

		REQUIRE(pe.evaluate(testFlush) == "Flush");

		vector<Card> testFullHouse = {
			Card(3, "Hearts"),
			Card(3, "Clubs"),
			Card(4, "Spades"),
			Card(4, "Clubs"),
			Card(11, "Hearts"),
			Card(4, "Hearts"),
			Card(2, "Hearts"),
		};

		REQUIRE(pe.evaluate(testFullHouse) == "Full House");

		vector<Card> testRoyalFlush = {
			Card(10, "Spades"),
			Card(12, "Spades"),
			Card(14, "Spades"),
			Card(4, "Clubs"),
			Card(11, "Spades"),
			Card(13, "Spades"),
			Card(2, "Hearts"),
		};

		REQUIRE(pe.evaluate(testRoyalFlush) == "Royal Flush");
	}
}