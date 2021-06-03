#include "fileSave.h"
#include "student.h"
using namespace std;

// constructor method
fileSave::fileSave() {

}
// method to write to file
void fileSave::writingFile() {
	// needs to import data
	// is it possiable to make the name of the file a variable as well and pass that in?
	ofstream write;
	write.open("variable_name")
		for (int a : vector_name) {
			write << a << endl;
	}
}