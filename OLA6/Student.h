//Isha Mudgal
//OLA 6
//Due: April 12th
//File: Student.h

#include <string>

using namespace std;

class Student
{
	//constructor
	Student(string mnum, string phone, string add);

	//setter and getter for m number
	string getmNum() const;
	string setmNum(string m);

	//setter and getter for phone number
	string getPhone() const;
	string setPhone(string p);

	//setter and getter for address
	string getAddress() const;
	string setAddress(string add);

	//overloading less than operater
	bool operator < (const Student& aStudent);
	//pverloading output operator
	friend std::ostream& operator << (std::ostream&, const Student&);

	//private variables
private:
		string mNum;
	    string phoneNum;
		string address;

};