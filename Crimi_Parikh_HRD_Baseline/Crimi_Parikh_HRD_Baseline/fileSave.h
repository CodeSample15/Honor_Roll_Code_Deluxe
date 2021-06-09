#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

class fileSave
{
public:
	//constructors
	fileSave();
	fileSave(string fileName);

	//methods
	void saveStudentData(student &data);
	string getStudentData(int studentNum, vector<string>& classes, vector<double>& grades, double& average, bool& disciplineIssue); //returns the full name of the student, as well as filling the classes and grades vectors with the appropriate student data

private:
	string filePath;
};

