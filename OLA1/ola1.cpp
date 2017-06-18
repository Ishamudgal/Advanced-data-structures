//Isha Mudgal
//c1002335
//OLA1
//Due: January 30, 2017
//Program to output class information (scores) of one or all students

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//structure student
struct student
{
	string ID;
	float CLA, OLA, quiz, homework, exam, bonus, total;
	char FinalGrade;
};

//Function declarations
void readFile(student[], string&);      //declaration of Function to read data into an array of struct
void printOne(student[], string);      //function that prints information of ONE student
void printAll(student[], string);      //function that prints information of ALL students

int main()
{
	student roster[17];
	string firstLine;  //first line of input file

	readFile(roster, firstLine); //call read file function
	printOne(roster, firstLine); //call function to output info of one student
	printAll(roster, firstLine); //call print All function

	system("pause");
	return 0;
}

//function definitions

void readFile(student roster[], string& firstLine)
{
	ifstream input;
	int i = 0;  //counter
				//file input
	input.open("point.dat");

	//initiate read
	getline(input, firstLine);
	input >> roster[0].ID;

	while (input) //till end of the file
	{
		float sum = 0; //variable for sum of scores
		input >> roster[i].CLA;
		sum = sum + roster[i].CLA;

		input >> roster[i].OLA;
		sum = sum + roster[i].OLA;

		input >> roster[i].quiz;
		sum = sum + roster[i].quiz;

		input >> roster[i].homework;
		sum = sum + roster[i].homework;

		input >> roster[i].exam;
		sum = sum + roster[i].exam;

		input >> roster[i].bonus;
		sum = sum + roster[i].bonus;
		//calculate total
		roster[i].total = sum;
		//Calculate grade
		int percent = (roster[i].total / 110) * 100;

		if (percent >= 90)
			roster[i].FinalGrade = 'A';
		else if (percent >= 80 && percent <90)
			roster[i].FinalGrade = 'B';
		else if (percent >= 70 && percent <80)
			roster[i].FinalGrade = 'C';
		else if (percent >= 60 && percent <70)
			roster[i].FinalGrade = 'D';
		else
			roster[i].FinalGrade = 'F';
		i++; //increment counter
		input >> roster[i].ID;  //prompt file read 
	}
}

void printOne(student roster[], string firstLine)
{
	string id;
	cout << "Please enter the student's c-number:";
	cin >> id;
	int i = 0;
	while (id != roster[i].ID) //compare student id with id in array
	{
		i++;
	}
	cout << firstLine << endl;
	cout << roster[i].ID << setw(7) << roster[i].CLA << setw(5) << roster[i].OLA << setw(5) << roster[i].quiz << setw(10) << roster[i].homework
		<< setw(10) << roster[i].exam << setw(8) << roster[i].bonus << setw(7) << roster[i].total << setw(8) << roster[i].FinalGrade << endl;
}

void printAll(student roster[], string firstLine)
{
	cout << firstLine << endl;
	for (int i = 0; i < 17; i++)
	{
		cout << roster[i].ID << setw(7) << roster[i].CLA << setw(5) << roster[i].OLA << setw(5) << roster[i].quiz << setw(10) << roster[i].homework
			<< setw(10) << roster[i].exam << setw(8) << roster[i].bonus << setw(7) << roster[i].total << setw(8) << roster[i].FinalGrade << endl;
	}
}

