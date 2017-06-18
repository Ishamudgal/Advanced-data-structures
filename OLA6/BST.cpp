//Isha Mudgal
//OLA 6
//Due: April 12th
//File: BST.cpp

#include "BST.h"

void BST::traversal()
{
	while (it != bst.end())
	{
		cout << it->first;
		it++;
	}
}