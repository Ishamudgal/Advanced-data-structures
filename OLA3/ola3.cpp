//Isha Mudgal
//OLA 3
//Dr Dong
//Due: 22 February 2017
//Card Game
//File: main.cpp

#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include <iostream>

using namespace std;

int main()
{
	//creating two objects of class player for two players
	Player player1("Williams");
	Player player2("Computer");
	//creating an object of class deck for new deck
	Deck deck = Deck();
	int counter = 1; //counter to control loop

	cout << "The original deck has the following cards" << endl;
	//print original deck
	cout << deck << endl;
	cout << endl;
	//shuffle and print deck
	deck.Shuffle();
	cout << "After shuffle the deck has following cards" << endl;
	cout << deck << endl << endl;
	//while deck is not empty
	while (deck.isEmpty() != true)
	{	//draw cards
		player1.drawCard(deck);
		player2.drawCard(deck);

		//display player and hand with score
		cout << "************** Hand " << counter << " **************" << endl;
		cout << player1.getName() << "'s hand: " << player1 << " with score " << player1.total() << endl;
		cout << player2.getName() << "'s hand: " << player2 << " with score " << player2.total() << endl << endl;

		Card card1 = player1.playCard();
		Card card2 = player2.playCard();

		cout << player1.getName() << " played card: " << card1 << " --- " << player2.getName() << " played card: " << card2 << endl << endl;
		//compare and declare winner of the round
		if (card1 < card2)
		{
			cout << player2.getName() << " takes this hand " << endl << endl;
			player2.addScore(card2);
		}
		else if (card2 < card1)
		{
			cout << player1.getName() << " takes this hand" << endl << endl;
			player1.addScore(card1);
		}
		else
			cout << "It's a DRAW!" << endl;
		//display hand again
		cout << player1.getName() << "'s hand: " << player1 << " with score " << player1.total() << endl;
		cout << player2.getName() << "'s hand: " << player2 << " with score " << player2.total() << endl << endl;

		++counter;
	}
	int total1 = player1.total();
	int total2 = player2.total();
	//compare total to determine the final winner
	if (total1 > total2)
		cout << player1.getName() << " WINS with a total of " << total1 << endl;
	else if (total2 > total1)
		cout << player2.getName() << " WINS with a total of " << total2 << endl;
	else
		cout << "It's a draw!!" << endl;
}