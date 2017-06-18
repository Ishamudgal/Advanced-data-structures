//Isha Mudgal
//OLA 3
//Dr Dong
//Due: 22 February 2017
//Card Game
//File: Card.cpp
#include "Card.h"
#include <iostream>

using namespace std;

//default constructor
Card::Card()
{

}
//value constructor
Card::Card(int faceValue, suite type, int pointValue)
{//values returned from deck class are stored in appropriate variables
	Card::faceValue = faceValue;
			
	Card::type = type;
	//set points according to the game
	if (pointValue == 1)
		Card::pointValue = 15; //15 pts for ace
	else if (2 <= pointValue && pointValue <= 10)
		Card::pointValue = pointValue; //arithmetic equal pt for numbers
	else if (11 <= pointValue && pointValue <= 13)
		Card::pointValue = 10; //10 pts for face cards	
}

ostream& operator << (ostream& os, const Card& cd)
{
	 //print face value for ace king queen and J specifically according to number
	if (cd.faceValue == 1)
		os << 'A';
	else if (2 <= cd.faceValue && cd.faceValue <= 10)
		os << cd.faceValue;
	else if (cd.faceValue == 11)
		os << 'J';
	else if (cd.faceValue == 12)
		os << 'Q';
	else if (cd.faceValue == 13)
		os << 'K';
	//print characters for suites
	if (cd.type == clubs)
		os << (char(0x05));
	else if (cd.type == hearts)
		os << (char(0x03));
	else if (cd.type == spades)
		os << (char(0x06));
	else
		os << (char(0x04));
	//point value for the cards
	os << '[' << cd.pointValue << "] ";

	
	return os;
}
//overload operators
bool Card::operator < (const Card& cd) const
{
	return (pointValue < cd.pointValue);
}

bool Card::operator > (const Card& cd) const
{
	return (pointValue < cd.pointValue);
}

bool Card::operator == (const Card& cd) const
{
	return (pointValue == cd.pointValue);
}

int Card::getPointValue() const
{
	return pointValue;
}

