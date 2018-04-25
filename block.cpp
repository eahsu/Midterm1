// block.cpp
// Esther Hsu
// 9819525

#include <iostream>
using namespace std;

int main(){
	int rows, cols; //declare rows and cols are integer
	int checkifrowsisnotzero = 0;
	while (checkifrowsisnotzero == 0){
		cout << "Enter number of rows and columns: " << endl;
		cin >> rows >> cols; //enter rows, then a space, then cols
		if (rows > 0){
			for (int i = 0; i < rows; i++ ){
				for (int j = 0; j < cols ; j++ ){
					cout << "X.";
				}
				cout << endl;
			}
		}	
		else {
			checkifrowsisnotzero = 1;
		}
	}
	return 0;
}
