/**
 *Rohan Parikh
 *17 February 2021 - 18 February 2021
 *Honor Roll OOP
 *Extra Thing: If user enters a name with a length less than 1, option is given to correct it
 */

#include <vector>
#include <string>
#include <iostream>
#include "student.h"
#include "fileSave.h"
using namespace std;

int main()
{
    cout << "How many students would you like to enter?\n";
    // to be data validated
    int amount = 0;
    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        student Student1;
        Student1.honor_roll_eligibility_checker();
        fileSave File;
        File.saveStudentData(Student1);
    }

    //give the user the menu
    cout << "Menu:" << endl;
    cout << "1. Show output for each student" << endl;
    cout << "2. Show output for a particular student" << endl;
    cout << "3. Show name and GPA for all students" << endl;
    cout << "4. Show GPA for a certain student" << endl;
    cout << "5. Show list of students with disciplinary issue" << endl;

    //ask the user for their choice


    //do different actions depending on their choice


    /* Order for loading data from file: 
    fileSave saver;
    vector<string> names;
    vector<int> grades;
    double average;
    bool disciplineIssue;

    string studentName = saver.getStudentData(2, names, grades, average, disciplineIssue);
    cout << studentName << endl;
    
    cout << names.size() << endl;
    cout << grades[0] << endl;
    */
}
