/**
 *Rohan Parikh
 *17 February 2021 - 18 February 2021
 *Honor Roll OOP
 *Extra Thing: If user enters a name with a length less than 1, option is given to correct it
 */

#include "student.h"
#include "fileSave.h"
using namespace std;

int main()
{
    student Student1;
    Student1.honor_roll_eligibility_checker();
    fileSave File;
    File.saveStudentData(Student1);
}
