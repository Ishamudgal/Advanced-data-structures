//Isha Mudgal
//OLA4
//Due: Monday, march 20
//Movie.cpp
#include "StoreItem.h"
#include "Movie.h"
#include <sstream>
#include <iostream>

//initialize using initializer list
Movie::Movie(std::string title, std::string director,
	std::string barcode, double price, int copy, int demand)
	:StoreItem(barcode, price, copy, demand), m_title(title), m_director(director) //call parent class constructor first
{ }

//return title of a movie
std::string Movie::getTitle() 
{
	return m_title;
}

//return director's name for a movie
std::string Movie::getDirector() const
{
	return m_director;
}

Movie* Movie:: createFromString(const std::string info)
{
	std::stringstream str(info);

	std::string garbage;
	std::getline(str, garbage, DELIMITER);

	std::string type, barcode, title, director, price, copies, demand;
	//read every word split by a '|' and store it into appropriate variables
	std::getline(str, type, DELIMITER);
	std::getline(str, barcode, DELIMITER);
	std::getline(str, title, DELIMITER);
	std::getline(str, director, DELIMITER);
	std::getline(str, price, DELIMITER);
	std::getline(str, copies, DELIMITER);
	std::getline(str, demand, DELIMITER);
	//convert numbers from string
	char* endPtr;
	double PRICE = strtod(price.c_str(), &endPtr);
	int COPIES = atoi(copies.c_str());
	int DEMAND = atoi(demand.c_str());
	//create a new pointer to the new object
	Movie* newMov = new Movie(title, director, barcode, PRICE, COPIES, DEMAND);
	return newMov;
}
//print info of the current item
void Movie::printItem()
{
	std::cout << "********************* Movie with barcode " << getBarcode() << " *********************" <<std::endl;
	std::cout << "Title:       " << getTitle() <<std::endl;
	std::cout << "Director:    " << getDirector() << std::endl;
	std::cout << "Price:       " << getPrice() << std::endl;
	std::cout << "# of copy:   " << getCopy() << std::endl;
	std::cout << "# of demand: " << getDemand() << std::endl;
}