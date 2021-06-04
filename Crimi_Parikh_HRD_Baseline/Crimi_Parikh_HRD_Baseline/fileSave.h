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
	void getStudentData(int studentNum, vector<string>& classes, vector<double>& grades);

private:
	string filePath;
};

