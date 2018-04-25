#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// function (named assertEquals) returns void
// void means nothing, means returning nothing
void assertEquals(string expected, string actual, string message); 
string starT(int width, int height); // declare a string function named starT, will return a STRING!
void runTests(void);

string starT(int width, int height){
  string result = "";															// declare empty string named result
	int numSpaces = width/2;												// declare integer that represents the number of spaces to add
	
	if(width < 2 || width%2 == 0 || height < 2){			// if these conditions are not fulfilled, return empty result string
		return result;
	}
	
	for(int i = 0; i < width; i++){									// add the first row of *
		result += "*";
	}
	result += "\n";																	// after first row, start working on other rows
	
	for(int i = 0; i < height-1; i++){							// start to print the other rows. height-1 because we printed first row already
		for(int j = 0; j < numSpaces; j++){						// add the number of spaces to put * in the middle
			result += " ";
		}
		result += "*";																// add the middle *
		for(int j = 0; j < numSpaces; j++){
			result += " ";
		}
		result += "\n";																// move onto the next line
	}

	return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starT34Expected =
    "***\n"
    " * \n"
    " * \n"
    " * \n" ;

  assertEquals(starT34Expected,starT(3,4),"starT(3,4)");

  string starT53Expected =
    "*****\n"
    "  *  \n"
    "  *  \n" ;

  assertEquals(starT53Expected,starT(5,3),"starT(5,3)");

  string starT72Expected =
    "*******\n"
    "   *   \n";

  assertEquals(starT72Expected,starT(7,2),"starT(7,2)");

  assertEquals("",starT(1,2),"starT(1,2)");
 	assertEquals("",starT(5,1),"starT(5,1)");
 	assertEquals("",starT(4,2),"starT(4,2)");
	assertEquals("",starT(6,2),"starT(6,2)");
}

// Test harness

void assertEquals(string expected, string actual, string message="") {
  if (expected==actual) {
    cout << "PASSED: " << message << endl;;
  } else {
    cout << "   FAILED: " << message << endl << "   Expected:[\n" << expected << "] actual = [\n" << actual << "]\n" << endl;
  }
}


// Main function

int main(int argc, char *argv[]){
  if (argc!=3) {
    cerr << "Usage: " << argv[0] << " width height" << endl;
    exit(1);
  }

  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  if (width==-1 && height==-1) {
    runTests();
    exit(2);
  }

  cout << starT(width,height);

  // TODO: Add check for parameters
  // and code to print usage message

  // TODO: Add code to get width and height from command line args
  // code that checks if they are both -1; if so, call runTests()
  // then exit.

  // TODO: Add code that calls the starT function and prints
  // the result on cout (without an extra newline)

  return 0;
}
