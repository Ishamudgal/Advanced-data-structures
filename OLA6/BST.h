//Isha Mudgal
//OLA 6
//Due: April 12th
//File: BST.h

#include "Student.h"
//Isha Mudgal
//OLA 6
//Due: April 12th
//File: BST.cpp

#include <unordered_map>
#include <iostream>

using namespace std;

class BST
{
	struct TreeNode {
		Student	item;
		string		left_child_Mnum;
		string		right_child_Mnum;
	};

	unordered_map <string, TreeNode> bst;
	std::unordered_map<string, TreeNode>::iterator it = bst.begin();

	//traversal
	void traversal();
	
	//search by m number

	//insert
	//delete by m number

};