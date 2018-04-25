// pi.cpp
//infinite loop

#include <iostream> //cin and cout are in iostream
#include <cmath>

using namespace std;

int main(){

	int n=0; //initialize n
	double pi;

	while (n >= 0){ //need to initialize n before calling it

		double result = 0.00; //double is DECIMAL

		cout << "Enter the value of the parameter 'n' in the Leibniz formula (or -1 to quit):\n";
		cin >> n;

		if (n < 0){
			break;
		}

		for (int i = 0; i <= n; i++){
			result += (pow(-1,i)/(2*i+1));
		}

		pi = 4 * result;

		cout.setf(ios::fixed); 	   // Display in fixed point notation. For example, display 1e-1 as 0.1
		cout.setf(ios::showpoint); // Always display the decimal point.
		cout.precision(3);         // Set the number of digits to display after the decimal point to

		if (n == 0){ //NO n=0, n == 0 means IF n IS EQUAL TO ZERO?, IF YES, DO THE FOLLOWING THINGS
			cout << "The approximate value of pi using "<< (n+1) << " term is: " << pi << endl;
		}
		else {
			cout << "The approximate value of pi using "<< (n+1) << " terms is: " << pi << endl;
		}
	}
	return 0;
}