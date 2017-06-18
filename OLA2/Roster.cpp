//Isha Mudgal
//OLA 2
//Dr Dong
//search and display information of class
//File Roster.cpp
#include "Roster.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
using std::string;

Roster::Roster(std::string courseName)
{
	m_courseName = courseName;
	m_studentNum = 0;
}

void Roster::printStudentRecords()
{
	cout << "     ID   CLA   OLA   Quiz   Homework   Exam   Bonus   Total   FinalGrade   " << endl;
	for (int i = 0; i < m_studentNum; ++i)     //traverse through array m_students
	{
		cout << m_students[i].getID() << setw(7);  //getID function in student class
		//using getScore to get scores in each category of enum
		cout << m_students[i].getScore(Student::CLA) << setw(5); 
		cout << m_students[i].getScore(Student::OLA) << setw(5);
		cout << m_students[i].getScore(Student::QUIZ) << setw(10);
		cout << m_students[i].getScore(Student::HOMEWORK) << setw(10);
		cout << m_students[i].getScore(Student::EXAM) << setw(8);
		cout << m_students[i].getScore(Student::BONUS) << setw(7);
		cout << m_students[i].getTotal() << setw(8); //get total function in student class
		cout << m_students[i].setLetterGrade() << endl; //set letter grade in student class
	}
}

void Roster::printOneStudent(std::string courseName)
{
	
	cout << courseName << setw(7);
	for (int i = 0; i < m_studentNum; ++i)  //find the specific c number and print info
	{
		string id=m_students[i].getID();
		if (id == courseName)
		{
			cout << m_students[i].getScore(Student::CLA) << setw(5);
			cout << m_students[i].getScore(Student::OLA) << setw(5);
			cout << m_students[i].getScore(Student::QUIZ) << setw(10);
			cout << m_students[i].getScore(Student::HOMEWORK) << setw(10);
			cout << m_students[i].getScore(Student::EXAM) << setw(8);
			cout << m_students[i].getScore(Student::BONUS) << setw(7);
			cout << m_students[i].getTotal() << setw(8); //get total function in student class
			cout << m_students[i].setLetterGrade() << endl; //set letter grade in student class
		}
	}
}

void Roster::readStudentRecord(std::string file)
{
	ifstream input;
	string firstLine;
	//open and input from file
	input.open(file);
	getline(input, firstLine);
	int info; //data from file
	string id;
	input >> id;

	cout << firstLine << endl;

	while (input) //input info line by line
	{  //set ID
		m_students[m_studentNum].setID(id);

		// change scores in all categories of enum
		input >> info;
		m_students[m_studentNum].changeScore(Student::CLA, info);
		
		input >> info;
		m_students[m_studentNum].changeScore(Student::OLA, info);

		input >> info;
		m_students[m_studentNum].changeScore(Student::QUIZ, info);

		input >> info;
		m_students[m_studentNum].changeScore(Student::HOMEWORK, info);

		input >> info;
		m_students[m_studentNum].changeScore(Student::EXAM, info);

		input >> info;
		m_students[m_studentNum].changeScore(Student::BONUS, info);
		//calculate total using calculate total function
		m_students[m_studentNum].calculateTotal();
		
		++m_studentNum;
		input >> id; //increment with read
	}
}