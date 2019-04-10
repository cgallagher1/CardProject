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
	//Allows the Program to Randomize
	srand(unsigned(time(0)));
    cout << "Hello World!!!" << endl;

    Catch::Session().run();

    system("pause");

    return 0;
}

//Test Cards will test all the functionallity of the card class
TEST_CASE("Test Cards")
{
	//Creates bad cards
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

	//Makes sure that we are creating all 52 unqiue cards
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
     
	//Makes sure that the card can print itself correctly if needed
    SECTION("Test toString()")
    {
        Card c1(3, "Diamonds");
        Card c2(10, "Hearts");
        Card c3(14, "Spades");

        REQUIRE(c1.toString() == "3 of Diamonds");
        REQUIRE(c2.toString() == "10 of Hearts");
        REQUIRE(c3.toString() == "Ace of Spades");
    }

	//Test to see if two cards are equal
    SECTION("Test equivalence")
    {
        Card c1(3, "Diamonds");
        Card c2(3, "Diamonds");
        Card c3(14, "Spades");

		//3 of Diamonds is equal to 3 of Diamonds
        REQUIRE(c1.equal(c2) == true);
		//3 of Diamonds is not eaul to Ace of Space
        REQUIRE(c1.equal(c3) == false);
    }
}

//Tests all the functionallity of the Deck class
TEST_CASE("Test Deck")
{
	//When a Deck is created, it should have 52 cards in it
    SECTION("Test create Deck")
    {
        Deck deck1;

        //Test Size
        REQUIRE(deck1.getLength() == 52);
    }

	//After being shuffled, two decks should not be the same
    SECTION("Test shuffle Deck")
    {
        Deck deck1;
        Deck deck2;

        //Shuffles deck 2
        deck2.shuffle();
        
        //Test to see if the decks are the same
        REQUIRE(deck1.equal(deck2) == false);
    }

	//After dealing, cards should be removed from the deck
	//For example, after dealing 5 cards a deck of 52 should only have 47
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

	//Checks to make sure there are 52 unique cards in a Deck
	SECTION("Validation")
	{
		Deck deck1;

		REQUIRE(deck1.isUnique() == true);
		REQUIRE(deck1.allThere() == true);
	}
    
}

//Tests the functionallity of the Poker Evaluater Clas
TEST_CASE("Test Evaluator")
{
	SECTION("Testing setup")
	{

		//create a deck
		PokerEvaluator pe;
		pe.dealHand();

		//7 hand poker check
		REQUIRE(pe.getHand().size() == 7);

		//Testing each Deal, to test we set retval to false
		//and we flip it to true if we find our desired Hand
		bool retval = false;

		//Pairs should happen every other hand so we should see
		//one pair in five deals
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

		//Two pair should happen every 21 Hands so we should see
		//a two pair in 25 deals
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


		//Three Of A Kind happens every 47 Hands so we should see
		//Three Of A Kind in 50 deals
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


		//A Straight happens every 254 Hands so we should see
		//a Straight in 300 deals
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


		//A Flush happends every 508 Hands so we should see a Flush
		//in 600 deals
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

		//A Full house happends every 693 Hands so we should see
		//a Flush in 800 deals
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

		//A Four of a kind happends every 4,165 Hands so we should
		//see a Flush in 50000 deals 
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

		//A Straight flush happends every 72,192 Hands so we should
		//see a Straight Flush in 80000 deals
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

		//A Royal Flush happens every 649,740 Hands so we should
		//see a Royal Flush in 1000000 deals
		for (int i = 0; i < 1000000; i++)
		{
			if (pe.isRoyalFlush())
			{
				retval = true;
				break;
			}
		}
		REQUIRE(retval == true);



		//Forces a High Card
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

		//Forces a Pair
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

		//Forces a Straight
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

		//Forces a Flush
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

		//Forces a Full House
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

		//Forces a Royal Flush
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