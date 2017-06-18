#pragma once
#include <string>
#include "StoreItem.h"

class Book : public StoreItem
{
public:
	//default constructor setting every thing to empty or 0
	Book(std::string title = "", std::string author = "", std::string date ="",
		std::string barcode = "", double price = 0, int copy = 0, int demand = 0);

	std::string getTitle() override;

	std::string getAuthor() override;

	std::string getDate() const;
	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	Book* createFromString(const std::string info) override;

	//Print current item to the screen
	void printItem() override;

private:
	std::string m_title;        // book title
	std::string m_author;     // book authors
	std::string m_date;       //publish date
};
