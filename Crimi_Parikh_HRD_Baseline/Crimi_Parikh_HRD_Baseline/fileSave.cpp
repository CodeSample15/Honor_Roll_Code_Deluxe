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
	*	'-' symbol indicating the start of a new student section
	*	FirstName LastName
	*	Number_Of_Classes_Taken (use this to get the number of lines remaining for that student)
	*	Class1
	*	Grade1
	*	Class2
	*	Grade2
	*	... (rest of the classes)
	*	Average
	*	1 or 0 representing whether or not the student had a disciplinary issue
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
	fout << '-' << endl;
	fout << name << endl;
	fout << classes.size() << endl;

	//saving all of the classes to the file using a for loop
	for (int i = 0; i < classes.size(); i++) {
		fout << classes[i] << endl;
		fout << grades[i] << endl;
	}

	fout << average << endl;
	fout << (disciplineIssue ? "1" : "0") << endl;

	//close the file stream
	fout.close();
}

string fileSave::getStudentData(int studentNum, vector<string>& classes, vector<int>& grades, double& average, bool& disciplineIssue)
{
	//opening the file in read mode
	ifstream fin;
	fin.open(fileSave::filePath, ios::in);

	/*Logic for the get student data algorithm*/
	//loop through the file and search for the data of the correct student
		//finds the right number student (if there is one) and reads the data from the file
	
	//for keeping track what student the program is currently reading
	int currentStudent = 0;
	bool foundStudent = false;
	string studentName = ""; //for recording the name of the found student

	getline(fin, studentName); //reading the first line of the file

	if (fin.is_open())
	{
		while (!fin.eof()) {
			if (currentStudent == studentNum) {
				getline(fin, studentName); //recording the student's name
				foundStudent = true;
				break;
			}
			else {
				string currentLine = "";
				currentStudent++;
				do {
					getline(fin, currentLine);
				} while (currentLine != "-" && !fin.eof());
			}
		}


		//returns empty data if the studentNum is invalid
		//else the method returns the name of the student and fills the two vectors with the appropriate data
		if (foundStudent) {
			//record the data
			string classNumber;
			getline(fin, classNumber); //reading how many classes the student took
			int numberOfClasses = stoi(classNumber);

			//getting the classnames
			classes.clear();
			grades.clear();
			string lineData = "";
			int grade = 0;

			for (int i = 0; i < numberOfClasses; i++) {
				//class names
				getline(fin, lineData);
				classes.push_back(lineData);

				//grades
				getline(fin, lineData);
				grade = stoi(lineData); //converting the string data to an integer
				grades.push_back(grade);
			}

			//getting the average and if there is a discipline issue with the student

			//average
			string averageString = "";
			getline(fin, averageString);
			average = stod(averageString);

			//disipline issue
			string issue = "";
			getline(fin, issue);
			disciplineIssue = issue == "1";

			//closing the file
			fin.close();

			//return the name of the student found
			return studentName;
		}
	}
	
	return "";
}
