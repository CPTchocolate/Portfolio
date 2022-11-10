//********************************************************
//* Programmer: Holden Madriaga                          *
//* Date      : 7 November 2022                          *
//*                                                      *
//* Function  : Create a solution to the spinout puzzle  *
//*                                                      *
//* Pseudocode: Get the number of gates that are in the  *
//* Puzzle.                                              *
//* If the gate number is 1 or 2, output simple solution.*
//* If gate is greater than 3, first copy the index of   *
//* Array1 to solution array.                            *
//* Next turn the nth knobb on solution array            *
//* reverese  aray1 and send it to solution array        *
//* copy array2 and send it to solution array            *
//* last output solution                                 *
//********************************************************

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{  
	//build default Array 1, 2, 3 and set variables
	int FN2 = 1, SN2[4000] = { 0, 1 };
	int FN1 = 2, SN1[4000] = { 0, 2 ,1 };
	int FN, SN[4000] = { 0 };
	int index1, index2;
	int numberOfGatesRequested;
	//finished building default Array 1, 2, 3 and setting variables

	cout << "Please enter the number of gates in your puzzle: ";
	cin >> numberOfGatesRequested;
	// prompt solutions for gates 1 and 2
	if (numberOfGatesRequested <= 2) {
		if (numberOfGatesRequested == 1) {
			cout << "Turn gate 1." << endl;;
		}
		else cout << "Turn gate 2." << endl << "Turn gate 1." << endl;
	}
	// if program is greater than 2, use formula for solutions.
	else {
		for (index1 = 3; index1 <= numberOfGatesRequested; index1++) {
			// Copy the array1 to solution puzzle
			for (index2 = 1; index2 <= FN2; index2++) {
				SN[index2] = SN2[index2];
			}
			FN = FN2 + 1;
			SN[FN] = index1;
			//REVERSE THE STEPS IN array 1 and send it to solution
			for (index2 = FN2; index2 > 0; index2--) {
				FN += 1;
				SN[FN] = SN2[index2];
			}
			//copy the index of array 2 to solution array
			for (index2 = 1; index2 <= FN1; index2++) {
				FN = FN + 1;
				SN[FN] = SN1[index2];
			}
			FN2 = FN1;
			FN1 = FN;
			//move arrays down for next run
			for (index2 = 1; index2 < 4000; index2++) {
				SN2[index2] = SN1[index2];
				SN1[index2] = SN[index2];
			}
		}
		cout << "solution: " << endl;
		for (index1 = 1; index1 <= FN; index1++) {
			cout << "Turn Gate " << SN[index1]  << "." << endl;
		}
	}
	cout << "Puzzle solved.";
	return 0;
}