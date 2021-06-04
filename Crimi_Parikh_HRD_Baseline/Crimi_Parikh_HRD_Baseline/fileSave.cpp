#include <iostream> // for giving errors to the user if there are any
#include <fstream>
#include <vector>
#include <string>
#include "fileSave.h"
#include "student.h"

using namespace std;

// constructor method
fileSave::fileSave() 
{
	filePath = "StudentData.txt"; //set to default value to prevent errors
}

fileSave::fileSave(string fileName) 
{
	filePath = fileName;
}

void fileSave::saveStudentData(student& data) 
{
	/*
	*	Order of data saved into file:
	* 
	*	FirstName LastName
	*	Number_Of_Classes_Taken (use this to get the number of lines remaining for that student)
	*	Class1
	*	Grade1
	*	Class2
	*	Grade2
	*	... (rest of the classes)
	*	Average
	*	1 or 0 representing whether or not the student had a disciplinary issue
	*	Student's location in the file for easy retrieval of data
	*/

	//finding out what number student this is


	//get data from student class
	vector<string> classes;
	vector<int> grades;

	string name = data.getName();
	data.getClassAndGradeData(classes, grades);
	double average = data.getAverage();
	bool disciplineIssue = data.getDisciplineIssue();
	
	//open file in append mode
	ofstream fout;
	fout.open(fileSave::filePath, ios::app);

	//save data to file
	fout << name << endl;
	fout << classes.size() << endl;

	//saving all of the classes to the file using a for loop
	for (int i = 0; i < classes.size(); i++) {
		fout << classes[i] << endl;
		fout << grades[i] << endl;
	}

	fout << average << endl;
	fout << (disciplineIssue ? "1" : "0") << endl;
	fout << 

	//close the file stream
}