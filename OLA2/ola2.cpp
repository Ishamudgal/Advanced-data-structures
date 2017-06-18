//Isha Mudgal
//OLA 2
//Dr Dong
//search and display information of class
//File main.cpp
#include <iostream>
#include <stdlib.h>
#include "Student.h"
#include "Roster.h"

using std::string;
using namespace std;

int main()
{
	string file = "point.dat";

	cout << "Enter c-number: ";
	string cnumber;
	cin >> cnumber;

	Roster courseName(cnumber); //object of class roster

	courseName.readStudentRecord(file);  //call read student records
	courseName.printOneStudent(cnumber);
	courseName.printStudentRecords();    //call print student records

	system("pause");
		return 0;
}