//Isha Mudgal
//OLA 2
//Dr Dong
//search and display information of class
//File student.cpp
#include "Student.h"
#include <iostream>

using namespace std;
using std::string;

Student::Student()
{
	
}

string Student::getID() const
{
	return m_id;
}

void Student::setID(string id)
{
	m_id = id;
}

void Student::changeScore(const ScoreType type, const int score)
{
	m_score[type] = score;
}

int  Student::getScore(const ScoreType type) const
{
	return m_score[type];
}
//calculate total
void Student::calculateTotal()
{
	int total = 0;

	for (int i = 0; i < 6; ++i)
	    total += getScore((ScoreType) i);

	m_total = total;
}

int Student::getTotal() const
{
	return m_total;
}

//calculate letter grade based on total
char Student::setLetterGrade() 
{
	if (m_total >= 90)
		m_letterGrade = 'A';

	else if (m_total >= 80)
		m_letterGrade = 'B';

	else if (m_total >= 70)
		m_letterGrade = 'C';

	else if (m_total >= 60)
		m_letterGrade = 'D';

	else if (m_total < 60)
		m_letterGrade = 'F';
	return m_letterGrade;
}