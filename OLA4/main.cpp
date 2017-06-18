//Isha Mudgal
//OLA4
//Due: Monday, march 20
//MAIN.cpp
#include <iostream>
#include "StoreItem.h"
#include "Movie.h"
#include "Book.h"
#include <fstream>
#include <list>
#include <iomanip>
using namespace std;

int main()
{   //create objects of movie class and book class
	Movie defaultMovie;
	Book defaultBook;
	string info; //string information of text file
	list<StoreItem*> sList; //list of items
	list<StoreItem*>::iterator it = sList.begin(); //iterator for traversing the list of items

	std::ifstream inventory;
	StoreItem* itemPtr;
	//open text file
	inventory.open("inventory.txt");
	//save info in list according to movie or book
	while (getline(inventory, info))
	{
		if (info[1] == 'M')
			itemPtr = defaultMovie.createFromString(info);

		else
			itemPtr = defaultBook.createFromString(info);

		sList.insert(it, itemPtr);
	}
	//variable for user choice
	char ch;

	do
	{   //display menue
		cout << setw(35) << "MiniMovie store" << endl;
		cout << "******************************************************" << endl;
		cout << "*           Command Description                      *" << endl;
		cout << "* M              Inquire a movie by title            *" << endl;
		cout << "* B              Inquire a book by author            *" << endl;
		cout << "* L              List inventory                      *" << endl;
		cout << "* R              Return one movie                    *" << endl;
		cout << "* C              Check out                           *" << endl;
		cout << "* Q              Quit the main menu                  *" << endl;
		cout << "******************************************************" << endl; 
		//user input
		cout << "Please enter your command (M, B, L, R, C, Q): ";
		
		cin >> ch;
		//if choice is M then display item according to title
		if (ch == 'M' || ch == 'm')
		{
			cout << "Please enter the movie title: ";
			string title;
			bool found = false;
			getline(cin, title); //first getline reads blank
			getline(cin, title);
			for (it = sList.begin(); it != sList.end(); ++it) //iterate through the list to find movie with matching title
			{
				if ((*it)->getTitle() == title) //if title of movie matches a movie in the  list
				{
					(*it)->printItem(); //print item 
				    found = true;
				}
			}
			if (!found)
				cout << "Item not found!" << endl;
		} 

		//if choice is B search book according to author name
		else if (ch == 'B' || ch == 'b')
		{
			cout << "Please enter author name:" << endl;
			string author; bool found = false;
			getline(cin, author); //first getline reads garbage
			getline(cin, author);
			for (it = sList.begin(); it != sList.end(); ++it) //iterate through the list to find movie with matching title
			{
				if ((*it)->getAuthor() == author)  //if title of movie matches a movie in the  list
				{
					(*it)->printItem(); //print item
					found = true;
				}
			}
			if (!found)
				cout << "Item not found!" << endl;
		}
		//if choice is L iterate through list and print every item
		else if (ch == 'L' || ch == 'l')
		{
			for (it = sList.begin(); it != sList.end(); ++it)
			{
				(*it)->printItem();
			}
						
		}
		//if choice is C decrease the number of copies and check out item
		else if (ch == 'C' || ch == 'c')
		{
			bool found = false;
			string barcode;

			cout << "Please enter the item barcode: ";
			cin >> barcode;

			for (it = sList.begin(); it != sList.end(); ++it)
			{
				if ((*it)->getBarcode() == barcode) //look for matching barcode
				{
					found = true;
					if ((*it)->getCopy() == 0)   //if no copy is available for check out then increase demand
						(*it)->increaseDemand();
					else
						(*it)->decreaseCopy();

					cout << "The item with barcode " << barcode << " has been checked out successfully!" << endl;
				}
			}
				if (!found)
				{
					cout << "Cannot find item with barcode " << barcode << endl;
				}
			}

		//if choice is R the return the book and increase available copies by one
		else if (ch == 'R' || ch == 'r')
		{
			bool found = false;
			string barcode;

			cout << "Please enter the item barcode: ";
			cin >> barcode;
			for (it = sList.begin(); it != sList.end(); ++it)
			{
				if ((*it)->getBarcode() == barcode)  //look for matching barcode
				{
					found = true;
					(*it)->increaseCopy();  //increase copies

					cout << "The item with barcode " << barcode << " has been returned successfully!" << endl;
					}
			}
			if (!found)
			{
				cout << "Cannot find item with barcode " << barcode << endl;
				}

			} 
		//if choice is Q then exit
		if (ch == 'Q' || ch == 'q')
			break;
		system("pause");
		system("cls");
	} while (ch != 'Q' || ch != 'q');
	
	return 0;
}