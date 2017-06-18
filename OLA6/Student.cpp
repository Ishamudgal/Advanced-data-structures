//Isha Mudgal
//OLA 6
//Due: April 12th
//File: Student.cpp

#include "Student.h"
#include <string>

using namespace std;

//initializer list
Student::Student(string mnum, string phone, string add)
	:mNum(mnum), phoneNum(phone), address(add)
{ }

//return current student's m number
string Student::getmNum() const
{
	return mNum;
}

//set m number equal to passed value
string Student::setmNum(string m)
{
	return (mNum = m);
}

//return current student's phone number
string Student::getPhone() const
{
	return phoneNum;
}

//set phone equal to passed value
string Student::setPhone(string p)
{
	return (phoneNum = p);
}

//return current student's address
string Student::getAddress() const
{
	return address;
}

//set address equal to passed value
string Student::setAddress(string add)
{
	return (address = add);
}

//implementation for less than operator
bool Student::operator < (const Student& aStudent)
{
	if (mNum < aStudent.mNum)
		return true;
	else
		return false;
}

//implementation for << operator
ostream& operator << (ostream& os, const Student& student)
{
	os << student.mNum << "	"
		<< student.phoneNum << " "
		<< student.address << endl;
	return os;
}
