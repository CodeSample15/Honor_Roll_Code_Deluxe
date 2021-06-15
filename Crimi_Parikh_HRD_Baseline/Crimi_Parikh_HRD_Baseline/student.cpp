#include "student.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "GetData.h"

#include "fileSave.h"
using namespace std;

// Constructor Method
student::student()
{
    
}

student::student(string name, vector<string> classes, vector<int> grades, double average, bool disciplineIssue)
{
    student::full_name = name;
    student::classes = classes;
    student::grades = grades;
    student::mean_pre_rounded = average;
    student::discipline_issue = disciplineIssue;
}
// Public methods

void student::honor_roll_eligibility_checker()
{
    cout << "Would you like to load student data from a file, or import it into the console now?\nSay console to type it in, otherwise the system will load it from a file.\n";
    string userChoice = " ";
    getline (cin,userChoice);
    if (userChoice == "console" || userChoice == "Console")
    {
        // running methods to get name, and amount of classes and make sure they fit requirements
        collectingUserData();
        // Running methods to get course names, grades, overall grade, and generate discipline issue with 5% chance
        getCourses(); //Luke's code
        getGrades(); //Luke's code

        //course_names();
        //course_grades();
        //mean_grade();
        discipline_issue_method();

    
        // Checking for honor roll eligbiity
        honor_roll_eligbility = false;
    }
    else
    {
        cout << "Enter index of which student you want to load?\n";
        // need to also make sure no negatives are allowed
        int index = getValidInt(index);
        //fileSave::getStudentData(index,classes,grades,average,discipline_issue);
    }

    // Checking if mean is above 90, user taking more than 5 courses and there is no discipline
    // issue
    if (student::average >= 90 && student::numberOfCourses >= 5 && discipline_issue == "no")
    {
        honor_roll_eligbility = true;
    }
    else
    {
        honor_roll_eligbility = false;
    }

    // Based on the results above and the methods, will print user name, class and grades
    // and overall average grade. Then prints out if eligiable for honor roll or not
    cout << endl << endl;
    cout << full_name << endl;
    printf("%-20s%-5s\n", "Class", "Grade");
    for (int i = 0; i < student::numberOfCourses; i++) {
        string first = classes[i];
        int second = grades[i];
        string second_as_string;
        second_as_string = second;
        printf("%-20s%-5d \n", first.c_str(), second);
    }
    cout << endl;
    cout << endl << "Average: " << student::average << endl;

    cout << "Disciplinary Infraction: " << discipline_issue << endl;

    // Printing if elgiable for honor roll or not\

    if (honor_roll_eligbility == true)
    {
        cout << "Congratulations "<< full_name << "! You have made the honor roll.\n";
    }
    else
    {
        cout << "I'm sorry " << full_name << " but you didn't qualify for honor roll\n";
    }
}
void student::collectingUserData()
{
    // Method to collect user name
    student::userName();
    
    // Method to see how many courses user is enrolled in as well as checkign to make sure they fit parametrs
    //student::courses_enrolled_in();
    
}

// Private Methods
void student::getGrades(void)
{
    std::cout << std::endl;
    std::cout << std::endl;

    int MAX_GRADE = 120; //setting the max grade

    if (student::classes.size() > 0) {
        //print only if the user acutally entered 
        std::cout << "Please enter your grades in integer form (minimum: 0, maximum: " << MAX_GRADE << "): " << std::endl;
    }

    //loop through the number of courses and ask the user for a grade for each class
    for (int i = 0; i < student::classes.size(); i++) {
        //defining variables
        float input; //making the variable a string variable just in case the user tries to enter a string value instead of a number

        //looping until the user enters a valid grade number
        while (true) {
            std::cout << "Enter grade for " << student::classes[i] << ": ";
            std::cin >> input;

            if (!std::cin.fail() && ceil(input) == input /*to check if the number entered is an integer, the ceiling of the number should be the same as the number*/) {
                //valid integer entered

                if (input < 0 || input > MAX_GRADE) {
                    //integer is out of bounds
                    std::cout << "Grade entered was outside the allowed range!" << std::endl;
                    continue;
                }
                else {
                    //the user entered a valid input, the loop is broken
                    break;
                }
            }
            else {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cout << "Invalid input!" << std::endl;
                continue;
            }
        }

        student::average += (int)input; //for calculating the average
        student::grades.push_back((int)input);
    }

    //finding the average
    student::average /= student::numberOfCourses;
}

void student::getCourses(void)
{
    //Declaring variables
    std::string courseName = ""; //declaring a variable to hold the string name and grade
    int numCourses = 0;
    bool goodInput = false;

    //getting number of courses from the user
    do {
        std::cout << "Enter the number of courses you are taking (minimum: 1, maximum: 8): ";
        std::cin >> numCourses;

        if (!std::cin.fail()) {
            //valid integer entered
            goodInput = !(numCourses < 1 || numCourses > 8);

            if (!goodInput)
                std::cout << "Number entered was out of bounds!" << std::endl;
        }
        else {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Invalid input!" << std::endl;
            continue;
        }
    } while (!goodInput);

    student::numberOfCourses = numCourses; //setting the object variable for later use

    //for neat output
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Please enter course names " << std::endl;
    std::cout << "Course names will be truncated to 20 characters." << std::endl;
    std::cin.ignore(1000, '\n');

    for (int i = 0; i < numCourses; i++) {
        //getting user input
        do {
            std::cout << "Enter name of course #" << (i + 1) << ": ";
            std::getline(std::cin, courseName);
        } while (courseName.length() == 0 || courseName == " ");

        //checking to see how long the name is
        if (courseName.length() > 20) {
            //make the course name 20 characters long
            std::cout << "Course name too long! Shortened version recorded instead." << std::endl;
            courseName = courseName.substr(0, 20);
        }


        student::classes.push_back(courseName);
    }
}

void student::userName()
{

    // collects user name and test if it is 0,1 or larger length
    cout << "Enter your full name: ";
    getline(cin, full_name);
    // if character length is 0,then it will ask user to enter their name
    name_size = full_name.length();
    if (name_size == 0)
    {
        while (name_size == 0)
        {
            cout << "You entered nothing. Please enter your name: ";
            getline (cin, full_name);
            name_size = full_name.length();
        }
    }

    // If character length is 1, will ask user for confirmation
    cout << endl; // a bit of spacing for easier to read output

    string choice;
  
    if (name_size == 1)
    {
        cout << "Are you sure that you entered your name correct? It has a length of one chracter (" << full_name << ")" << endl;
        cout << "Enter yes if you are sure and no if you want to correct it: ";
        // Extra Thing (allows user to correct input if they have 1 character)
        getline(cin, choice);
        if (choice == "no")
        {
            cout << "Enter your full name: ";
            getline (cin,full_name);
        }
        else
        {
            cout << "Your name will be used in the program: ";
        }
    }
}

void student::courses_enrolled_in()
{
    cout << endl; //for easier to read output

    int i = 0;
    int count = 0;
    while (true)
    {
        // test condition to check for int status works for strings and doubles
        cout << "How many courses do you want to take?\nIf this is not the first time you are seeing this prompt,\nthat means you entered a faulty input. Enter a number \nbetween 1 and 8: ";
        getline(cin,courses);

        // Iteratres to every character checking if it is a digit or not
        // this deduces whether user inputted integer or something else
        for (i = 0; i < courses.length(); i++) 
        {
            if (isdigit(courses[i]) == false) 
            {
                count=1;
                break;
            }
            else
                count=0;
     
        } if(count==0)
        {
           // cout << "Number inputted is an Integer\n";
            courses_int = std::stoi(courses);
            if (courses_int >= 1 && courses_int <= 8)
            {
                break;
            }
        }
  
        else
            cout << " ";
    }
}

void student::course_names()
{
    cout << endl;

    // Variables and while loops to store classes in an array
    string course_name_input;
    int j = 0;
    // Clearing cin but need it done only once
    //cin.ignore();
    // Run until user enters amount that corresponds with number of courses
    while (true) 
    {
        if (j >= courses_int)
        {
            break;
        }
        j++;
        // error checking to make sure user inputs course name less than 20
        do 
        {
            cout << "Enter a course name. It must be greater than 0 characters and less than 20 characters: ";
            
            getline(cin,course_name_input);
            if (course_name_input.length() > 20 || course_name_input.length() == 0)
            {
                cout << "You entered a course that either has 0 characters or more than 20. Please try again" << endl;
            }
            else
            {
                cout << "The course name fits the criteria." << endl;
                classes[j - 1] = course_name_input;
            }
        } while (course_name_input.length() > 20 || course_name_input.length() <=0);
    }
}

void student::course_grades()
{
    cout << endl; //for better output
    // Grades for each class

    for (int o = 0; o < courses_int; o++)
    {
        // checking if negative or non integer or above max
        int count = 0;
        do
        {
            // test condition to check for int status works for strings and doubles
            cout << "Enter your grade for class " << classes[o] << ". It must be greater than 0 and no more than " << MAX_GRADE << ". Also it must not be a negative number and must be an integer.\n If you are seeing this again, then you have failed one of these conditions.\n\n";
            string tempary = "";
            getline(cin,tempary);
            int triggered = 0;

            // Iteratres to every character checking if it is a digit or not
            // this deduces whether user inputted integer or something else
            for (int p = 0; p < tempary.length(); p++) 
            {
                if (isdigit(tempary[p]) == false) 
                {
                    count=1;
                    triggered = 1;
                }
                else
                    count=0;
     
            } if(count==0)
            {
                //cout << "Number inputted is an Integer\n";
                grades[o] = std::stoi(tempary);
                if (grades[o] >= 1 && grades[o] <= 8)
                {
                    cout << "";
                }
            }
  
            else
                cout << " ";
            if (triggered == 1)
            {
                cout << "You can not enter a string or a double.\n";
                count = 1;
            }
            // Checking if number is negative or above max grade
            if (grades[o] < 0)
            {
                cout << "You can't have a negative grade.\n Please enter a positive integer\n";
                count = 1;
            }
            if (grades[o] > MAX_GRADE)
            {
                cout << "You can not have a grade greater than " << MAX_GRADE << ". Please fix your input\n";
                count = 1;
            }
        } while (count == 1);
    }
}

void student::mean_grade()
{
    // Figuring out the overall Grade Average
    double added_up = 0;
    for (int w = 0; w < courses_int; w++)
    {
        double transfer = grades[w];
        added_up = added_up + transfer;
    }
    mean_pre_rounded = added_up/courses_int;

    // std::round to round up if .5 or above and round down if .4 or below
    mean = round(mean_pre_rounded);
}

void student::discipline_issue_method()
{
    // 5% chance for disicpline issue
    int max;
    max = 100; //set the upper bound to generate the random number
    srand(time(0));
    int chance = rand()%max;
    if (chance <= 5)
    {
        discipline_issue = "yes";
    }
    else
    {
        discipline_issue = "no";
    }
}

void student::printData()
{
    cout << endl << endl;
    cout << full_name << endl;
    printf("%-20s%-5s\n", "Class", "Grade");
    for (int i = 0; i < student::classes.size(); i++) {
        string first = student::classes[i];
        int second = student::grades[i];
        string second_as_string;
        second_as_string = second;
        printf("%-20s%-5d \n", first.c_str(), second);
    }
    cout << endl;
    cout << endl << "Average: " << student::average << endl;

    cout << "Disciplinary Infraction: " << discipline_issue << endl;

}

//for other programs to access private data
string student::getName()
{
    return full_name;
}

void student::getClassAndGradeData(vector<string>& classNames, vector<int>& classGrades)
{
    classNames = classes;
    classGrades = grades;
}

double student::getAverage() 
{
    //TODO: make this the non-rounded mean
    return (double)mean;
}

bool student::getDisciplineIssue()
{
    return discipline_issue == "yes";
}