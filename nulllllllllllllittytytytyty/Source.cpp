#include <time.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include<conio.h>
#include<time.h>
#include <iostream>  
#include <algorithm> 
#include <limits>
#include <cfloat>
#include <stdint.h>
#include <vector>

using namespace std;

//### DATA

// Constants
static float
n_zero = (-0.0),
zero = (0.0);

// Values
vector<float> float_array, nan_array;


void niceView() {
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void switch_vals(float &a, float &b) {
	float temp = a;
	a = b;
	b = temp;
}

void nanRemove() {
	for (int i = 0; i < float_array.size(); i++) {
		if (float_array[i] != float_array[i]) {
			nan_array.push_back(float_array[i]);
			float_array.erase(float_array.begin() + i);
		}
	}
}

void bubbleSort()
{
	nanRemove();
	for (int i = 0; i < float_array.size(); i++)
		for (int j = 0; j < float_array.size() - i - 1; j++)
			if (float_array[j] > float_array[j + 1])
				switch_vals(float_array[j], float_array[j + 1]);
}

//Function prints the array of values entered 
void printArray()
{
	printf("\nFloats : [[[");
	for (int i = 0; i < float_array.size(); i++)
		printf("%e, ", float_array[i]);
	printf("\nNANs   : [[[");
	for (int i = 0; i < nan_array.size(); i++)
		printf("%e, ", nan_array[i]);
}



void verbose_sort(vector<float> values) {
	// Clear
	float_array.clear();
	nan_array.clear();
	// Fill Array and Print
	float_array = values;
	printArray();
	bubbleSort();
	printf("\nSorted!");
	printArray();
	niceView();
}

void checkVals(float a, float b) {
	printf("\n\n%f < %f : %s", a, b, a < b ? "True" : "False");
}

int main()
{
	printf("\n\n\n\n\n\n\n\n\nWelcome to Neyma's NULLITY\nPress enter to continue...");
	niceView();
	printf("%s", "Tim's Testing :)");

	// Test 1
	checkVals(-INFINITY, INFINITY);
	checkVals(-INFINITY, NAN);
	checkVals(INFINITY, NAN);
	checkVals(-INFINITY, -NAN);
	checkVals(INFINITY, -NAN);



	niceView();

	///////////negative zero///////////


	//Case 1: positive infinity and negative infinity  
	std::cout << "Case 1: Can sort data with at least one negative infinity and one positive infinity" << std::endl;
	verbose_sort({ -INFINITY, 255, 332, 444, 11, INFINITY }); //test elements have been pre-inputted into the compiler.


	//Case 2: Sort elements including minus zero  	
	std::cout << "Case 2: Can sort data with at least one negative zero" << std::endl;
	verbose_sort({ 34, (-0.0), 47, 11,(0.0), INFINITY });//test elements have been pre-inputted into the compiler.

	//Case 3: Sort atleast one negative infinity
	std::cout << "Case 3: Can sort data with at least one negative infinity" << std::endl;
	verbose_sort({ 34, 4, -INFINITY, 66, 110 });//test elements have been pre-inputted into the compiler.

	//Case 4: Sort atleast one negative infinity
	std::cout << "Case 4: Can sort data with at least one negative infinity" << std::endl;
	verbose_sort({ 4, -114, INFINITY, 66, 1101 });//test elements have been pre-inputted into the compiler.

	//Case 5:Sort atleast one NaN
	std::cout << "Case 5: Can sort atleast one NaN" << std::endl;
	verbose_sort({ (float)sqrt(-55),-344, -6.4, NAN, 11, INFINITY, -INFINITY });//test elements have been pre-inputted into the compiler.

	//Case 6:Sort 2 NaNs
	std::cout << "Case 6:Can sort data with at least two different NaNs" << std::endl;
	verbose_sort({ (float)sqrt(3),-3, (0.0), 111, NAN * 1, NAN*-2, INFINITY, -INFINITY });//test elements have been pre-inputted into the compiler.

	return 0;
}
