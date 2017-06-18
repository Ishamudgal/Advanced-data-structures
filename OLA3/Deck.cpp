//Isha Mudgal
//OLA 3
//Dr Dong
//Due: 22 February 2017
//Card Game
//File: Deck.cpp
#include "Card.h"
#include "Deck.h"

Deck::Deck()
{ //initialize top card
	topCard = 0;
	
	for (int j = 0; j < 13; ++j)
	{
		theDeck[j] = Card(j + 1, clubs,j + 1);  //for first 13 cards of suite club
	}                                           //eg: 0 is saved as card 1 ie: Ace

	for (int j = 13; j < 26; ++j)
	{
		theDeck[j] = Card(j - 12, hearts, j - 12); //for next 13 cards of suite hearts
	}

	for (int j = 26 ; j < 39; ++j)
	{
		theDeck[j] = Card(j - 25, spades, j - 25); //next 13 cards of suit spades
	}

	for (int j =39; j < 52; ++j)
	{
		theDeck[j] = Card(j - 38, diamonds, j - 38); //last 13 cards of suite diamonds
	}											     //value of faceValue and points sent back is 39-38= 1 etc
	
}

Card Deck::dealCard()
{
	Card top = theDeck[topCard];
	topCard++;
	return top;
}

void Deck::Shuffle()
{    //set random value as location in array, and swap it with another element
	for (int i = 0; i < 52; ++i)
	{
		int random = rand() % 52;

		Card temp = theDeck[i];
		theDeck[i] = theDeck[random];
		theDeck[random] = temp;
		
	}
}
//if deal card has run 52 times that means there are no more cards left
bool Deck::isEmpty()
{
	if (topCard == 52)
	    return true;
	else
		return false;
}

ostream& operator << (ostream& os, const Deck& thedeck)
{
	for (int i = 0; i < 52; ++i)
		os << thedeck.theDeck[i] << " ";
	return os;
 }