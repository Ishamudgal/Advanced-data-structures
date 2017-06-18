//Isha Mudgal
//OLA 3
//Dr Dong
//Due: 22 February 2017
//Card Game
//File: Player.cpp
#include "Player.h"
#include "Card.h"
#include "Deck.h"

//define constructor
Player::Player(string name)
{
	Player::name = name;
	Player::score = 0;
	//intialize played array to true for first hand
	for (int i = 0; i < Max_Cards; ++i)
	{
		played[i] = true;
	}
}

Card Player::playCard()
{
	//play random card
	int random = rand() % 3;
	
		Card playCard = hand[random];
		//set the location in played array true
		played[random] = true;

		return playCard;
		
}

void Player::drawCard(Deck& dk)
{ 
	for (int i = 0; i < Max_Cards; ++i)
		if (played[i])
		{ //deal a card in the hand that was just played
			hand[i] = dk.dealCard();
			played[i] = false;
		}
}

//add scores
void Player::addScore(Card acard)
{
	score = score + acard.getPointValue();
}

int Player::total() const
{
	return score;
}

string Player::getName() const
{
	return name;
}

bool Player::emptyHand() const
{
	bool empty = true;
	for (int i = 0; i < Max_Cards; ++i)
	{
		if (played[i] == false) //if player still hasnt played that card
			empty = false;  //then not empty
	}
	return empty;
}

ostream& operator << (std::ostream& os, const Player& player)
{
	for (int i = 0; i < Player::Max_Cards; ++i)
	{
		if (player.played[i])
			os << " ____ ";   //display blank for no hand
	else
		os << player.hand[i] << " ";
	}
	return os;
}