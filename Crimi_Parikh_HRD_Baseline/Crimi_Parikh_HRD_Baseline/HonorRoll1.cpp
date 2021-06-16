/**
 *Rohan Parikh
 *17 February 2021 - 18 February 2021
 *Honor Roll OOP
 *Extra Thing: If user enters a name with a length less than 1, option is given to correct it
 * 
 * Known issues: Menu system isn't finished
 * Known issues: User can only enter one student
 */

#include <vector>
#include <string>
#include <iostream>
#include "student.h"
#include "fileSave.h"
#include "GetData.h"
using namespace std;

int main()
{
    fileSave saver;

    // data validated to ask user for number of students
    int amount = 0;
    do {
        cout << "Enter the number of students: ";
    } while (!getValidInt(amount));
    //TODO: Make algorithm to take data for multiple students

    // initilizing gradebook object
    student gradeBook;

    // running honor roll eigibility method
    // saving results to file
    for (int i = 0; i < amount; i++) {
        gradeBook.honor_roll_eligibility_checker();
        saver.saveStudentData(gradeBook);

        cout<<endl;
        cout<<endl; //some spacing in between each student
    }

    //give the user the menu
    cout << endl;
    cout << endl;
    cout << endl; //some spacing for easier to read output

    cout << "Menu:" << endl;
    cout << "A. Show output for each student" << endl;
    cout << "B. Show output for a particular student" << endl;
    cout << "C. Show name and GPA for all students" << endl;
    cout << "D. Show GPA for a certain student" << endl;
    cout << "E. Show list of students with disciplinary issue" << endl;

    //get input from the user
    bool dataGood = false;
    char firstLetter = ' ';

    // while the data isn't good (except for first time run), the user is asked to choose their menu option and the first character is taken (A,B,C,D,E) is choosen
    // When this happens, they are allowed to leave the loop
    do {
        cout << endl;
        cout << "Enter selection: ";
        string userChoice = "";
        getline(cin, userChoice);

        //data validation

        //take the first letter that the user entered and treat it as a character
        firstLetter = toupper(userChoice[0]); //convert to uppercase for easy comparison

        if (firstLetter == 'A' || firstLetter == 'B' || firstLetter == 'C' || firstLetter == 'D' || firstLetter == 'E') {
            dataGood = true; //break the loop, user entered good data
        }
        else {
            //continue the loop, user entered bad data
            cout << "Please enter a valid option!" << endl;
        }
    } while (!dataGood);

    //variables for user options
    int numberOfStudents = saver.numberOfStudents();
    vector<string> names;
    vector<int> grades;
    double average;
    bool disciplineIssue;


    // KNOWN ISSUES: At this time, only Case A works. The other cases do not work.
    
    //do different actions depending on their cahoice
    switch (firstLetter) 
    {
        case 'A':
            for(int i=0; i<numberOfStudents; i++)
            {
                string name = saver.getStudentData(i, names, grades, average, disciplineIssue);
                student print(name, names, grades, average, disciplineIssue);
                print.printData();
            }
            break;

        case 'B':
            break;

        case 'C':
            break;

        case 'D':
            break;

        case 'E':
            break;
    }

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
