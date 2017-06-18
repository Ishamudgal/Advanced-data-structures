//Isha Mudgal
//OLA 5
//Due: 22 March 2017
//Dr Dong - CSCI3110
#include "parameters.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//Find fibonacci number
int fibonacci(int n);

//Calculate sum of n numbers
int sum(int n);

//Find the longest continous series of positive numbers in an array
//index is used to keep track of the position
//current is the sequence of numbers being read
//sequence stores the number of positive numbers in a series that have been read
int longest(const int longarray[], int index=0, int current=0, int sequence=0);

//Find the shortest/smallest word in a given sentence
//word stores the shortest word found 
//length stores the length of the shortest word
int shortest(stringstream &sIn, string word = "", int length=0);

int main()
{   //Use constants from parameters.h to appropriately print solutions
	cout << "Fibonacci (" << FibVal << ") is " << fibonacci(FibVal) <<endl;
	cout << endl;
	cout << "Sum (" << SumVal << ") is " << sum(SumVal) << endl;
	cout << endl;
	cout << "Longest sequence of positive numbers in array: " << longest(LongestVal) << endl;
	cout << endl;
	
	stringstream ss(SentenceVal);
	cout << "Shortest word in the sentence is " << shortest(ss) << endl;
	cout << endl;
	system("pause");
	return 0;
}

int fibonacci(int n)
{   //if n is zero, fibonacci number is zero
	if (n == 0)
		return 0;
	//if n is 1 fibonacci number is 1
	else if (n == 1)
		return 1;
	//otherwise call the function itself and find fibonacci number
	else
		return (fibonacci(n - 2) + fibonacci(n - 1));
}

int sum(int n)
{   //if n is 1, sum is 1
	if (n == 1)
		return 1;
	//otherwise call function itself and add current number to previous sum
	else
		return n + sum(n - 1);
}

int longest(const int longarray[], int index, int current, int sequence)
{   //if index reaches the end then return the variable sequence
	if (index == 20)
		return sequence;
	
	//if the number is negative
	if (longarray[index] <= 0)
	{   //current sequence has more count than sequence of positive numbers than use value of current as sequence
		if (current > sequence)
			longest(longarray, index + 1, 0, current);

		else
			longest(longarray, index + 1, 0, sequence); //else reset current and retain sequence
	}

	//if the number is positive
	else if (longarray[index] > 0)
	{   //current is either greater or equal to value of sequence then both values are made current + 1 for next function call
		if (current >= sequence)
			longest(longarray, index + 1, current + 1, current + 1);

		else   
			longest(longarray, index + 1, current + 1, sequence); //otherwise retain sequence 

	}

}

int shortest(stringstream &sIn, string word, int length)
{
	string word2; //variable to store word length of streaming words
	getline(sIn, word2, ' '); //read one word


	if (word2.empty()) //if string ends then return the legth of shortest number
		return length;

	if ((word2.length() > word.length()) && !(word.empty())) //if word length of current word is more than word length of shortest word yet
		return	shortest(sIn, word, length);  //then do nothing
	
	else if (word2.length() <= word.length() || word.empty()) //else
	{
		length = word2.length(); //make length same as length of new shortest word
		return shortest(sIn, word2, length); //pass word2 as new shorter word
	}
			
}