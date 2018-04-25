#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void assertEquals(string expected, string actual, string message);
string starZ(int width);
void runTests(void);

string starZ(int width)
{
  string result="";
  if (width < 3){
    return result;  								// return without printing anything
  }
  int height = width;									// height = width according to problem
  for(int i = 0; i < width; i++){						// print out first line of *
    result += "*";
  }
  result += "\n";
	
  for(int i = 0; i < height-2; i++){						// print out the slash (middle part of Z). Height - 2 
    for(int j = height - 2 - i; j>0;j--){					// because we take out the top level and bottom level 
      result += " ";												// print out this many spaces. Height - 2 because of no top and bottom and then - i
    }																				// because reserve i spaces for * and spaces afterwards
    result += "*";									// Print out single *
    for(int j = 0; j<= i; j++){							// Print out rest of spaces to fill the line
    result += " ";
    }
    result += "\n";									// Go to next line
  }
	
  for(int i = 0; i < width; i++){						// same as printing top layer
    result += "*";
  }
  result += "\n";
  return result;
}

// Test-Driven Development; check expected results against actual

void runTests(void) {

  // The following line works because in C and C++ when string literals
  // are separated only by whitespace (space, tab, newline), they 
  // automatically get concatenated into a single string literal

  string starZ3Expected =
    "***\n"
    " * \n"
    "***\n";

  assertEquals(starZ3Expected,starZ(3),"starZ(3)");

   string starZ4Expected =
    "****\n"
    "  * \n"
    " *  \n"
    "****\n";

  assertEquals(starZ4Expected,starZ(4),"starZ(4)");

  assertEquals("",starZ(0),"starZ(0)");
  assertEquals("",starZ(2),"starZ(2)");
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

int main(int argc, char *argv[])
{

  //  if (argc!=2) {
  //   cerr << "Usage: " << argv[0] << " width" << endl;
  //   exit(1);
  // }
  //
  // int width = stoi(argv[1]);
  // // If the program is executed with parameters -1 -1 unit test
  // // the starL() function using our automated test framework
  // if (width==-1) {
  //   runTests();
  //   exit(0);
  // }
  //
  // cout << starZ(width);
	runTests();
  return 0;

  // TODO: Add check for parameter
  // and code to print usage message

  // TODO: Add code to get width from cmd line arg
  // code that checks if it is -1; if so, call runTests()
  // then exit.

  // TODO: Add code that calls the starZ function and prints
  // the result on cout (without an extra newline)

}
