//Isha Mudgal
//OLA4
//Due: Monday, march 20
//StoreItem.cpp
#include "StoreItem.h"

using namespace std;

//constructor
StoreItem::StoreItem(std::string barcode, double price, int copy, int demand)
: m_barcode(barcode), m_price(price), m_copy(copy), m_demand(demand)
{}

//function definitions for member functions of StoreItem class
string StoreItem::getBarcode(void) const
{
	return m_barcode; //return barcode of current object
}

double StoreItem::getPrice(void) const
{
	return m_price; //return price of current object
}

int StoreItem::getCopy(void) const
{
	return m_copy;  //return number of copies of current object
}

int StoreItem::getDemand(void) const
{
	return m_demand;  //return number of copies to be ordered of current object
}

//increas copies if they are more than or equal to zero
void StoreItem::increaseCopy(void)
{
	if (m_copy >= 0)
		m_copy++;
}
//decrease copies if the are more than zero
void StoreItem:: decreaseCopy(void)
{
	if (m_copy > 0)
		m_copy--;
}
//increase copies to be ordered if no copy of object is available
void StoreItem::increaseDemand(void)
{
	if (m_copy == 0)
		m_demand++;
}

void StoreItem::decreaseDemand(void)
{
	if (m_demand > 0)
		m_demand--;
}

//overload == operator
bool StoreItem::operator == (const StoreItem& rhs) const
{
	return(m_barcode == rhs.m_barcode);
}
//overload < operator
bool StoreItem::operator < (const StoreItem& rhs) const
{
	return(m_barcode < rhs.m_barcode);
}

std::string StoreItem::getAuthor()
{
	return "";
}