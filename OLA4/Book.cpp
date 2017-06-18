//Isha Mudgal
//OLA4
//Due: Monday, march 20
//Book.cpp
#include "StoreItem.h"
#include "Book.h"
#include <sstream>
//constructor
Book::Book(std::string title, std::string author, std::string date,
	std::string barcode, double price, int copy, int demand)
	:StoreItem(barcode, price, copy, demand), m_title(title), m_author(author), m_date(date) //call parent class constructor first
{ }
//get title of current object
std::string Book::getTitle()
{
	return m_title;
}
//get author of current object
std::string Book::getAuthor() 
{
	return m_author;
}
//get publish date
std::string Book::getDate() const
{
	return m_date;
}

Book* Book::createFromString(std::string info)
{
	std::stringstream str(info);

	std::string garbage;
	std::getline(str, garbage, DELIMITER);

	std::string type, barcode, title, author, date, price, copies, demand;

	//read every word split by a '|' and store it into appropriate variables
	std::getline(str, type, DELIMITER);
	std::getline(str, barcode, DELIMITER);
	std::getline(str, title, DELIMITER);
	std::getline(str, author, DELIMITER);
	std::getline(str, date, DELIMITER);
	std::getline(str, price, DELIMITER);
	std::getline(str, copies, DELIMITER);
	std::getline(str, demand, DELIMITER);
	//convert numbers from string
	char* endPtr;
	double PRICE = strtod(price.c_str(), &endPtr);
	int COPIES = atoi(copies.c_str());
	int DEMAND = atoi(demand.c_str());
	//create a new pointer to the new object
	Book* newbk = new Book(title, author, date, barcode, PRICE, COPIES, DEMAND);
    return newbk;
}

void Book::printItem()
{
	std::cout << "********************* Book with barcode " << getBarcode() << " *********************" << std::endl;
	std::cout << "Title:        " << getTitle() << std::endl;
	std::cout << "Author:       " << getAuthor() << std::endl;
	std::cout << "Price:        " << getPrice() << std::endl;
	std::cout << "Publish date: " << getDate() << std::endl;
	std::cout << "# of copy:    " << getCopy() << std::endl;
	std::cout << "# of demand:  " << getDemand() << std::endl;
}