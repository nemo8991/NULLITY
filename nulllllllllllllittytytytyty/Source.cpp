#include <time.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <iostream>  
#include <algorithm> 
#include <limits>
#include <cfloat>
#include <stdint.h>


using namespace std;

// A function used to implement the bubblesort algorithm.

void niceView() {
	getchar();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


void bubbleSort(float arr[], int n)
{
	if (n == 0)
	{
		std::cout << "..." << std::endl;
		return;
	}

	// After the first pass, then the largest element is moved to the end. 

	for (int i = 0; i < n - 1; i++)

	{
		if (arr[i] > arr[i + 1])
			swap(arr[i], arr[i + 1]);

		//The largest element in the array  Largest element is fixed, recur for remaining array 
	}

	bubbleSort(arr, n - 1);

}

//Function prints the array of values entered 
void printArray(float arr[], int n)
{
	if (n == 0)
	{
		cout << "There are no elements to be sorted" << endl;
		return;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			printf("%e", arr[i]); //%e” is for floating type number, a series of decimal digits
			printf("\n");
		}

	}
}

int main()
{

	///////////negative zero///////////
	int i;
	float n_zero = (-0.0);
	float zero = (0.0);

	//Case 1: positive infinity and negative infinity  
	std::cout << "Case 1: Can sort data with at least one negative infinity and one positive infinity" << std::endl;

	float arr1[] = { -INFINITY, 255, 332, 444, 11, INFINITY }; //test elements have been pre-inputted into the compiler.
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	printArray(arr1, n1);
	bubbleSort(arr1, n1);
	std::cout << "Sorted array of the elements: \n" << std::endl;
	printArray(arr1, n1);

	niceView();


	//Case 2: Sort elements including minus zero  	
	std::cout << "Case 2: Can sort data with at least one negative zero" << std::endl;
	float arr2[] = {34, (-0.0), 47, 11,(0.0), INFINITY };//test elements have been pre-inputted into the compiler.
	int n2 = sizeof(arr2) / sizeof(arr2[0]);
	bubbleSort(arr2, n2);
	printArray(arr2, n2);
	std::cout << "Sorted array of elements: \n" << std::endl;
	printArray(arr2, n2);

	niceView();
	//Case 3: Sort atleast one negative infinity
	std::cout << "Case 3: Can sort data with at least one negative infinity" << std::endl;
	float arr3[] = { 34, 4, -INFINITY, 66, 110 };//test elements have been pre-inputted into the compiler.
	int n3 = sizeof(arr3) / sizeof(arr3[0]);
	bubbleSort(arr3, n3);
	printArray(arr3, n3);
	std::cout << "Sorted array of elements: \n" << std::endl;
	printArray(arr3, n3);

	niceView();
	//Case 4: Sort atleast one negative infinity
	std::cout << "Case 4: Can sort data with at least one negative infinity" << std::endl;
	float arr4[] = { 4, -114, INFINITY, 66, 1101 };//test elements have been pre-inputted into the compiler.
	int n4 = sizeof(arr4) / sizeof(arr4[0]);
	bubbleSort(arr4, n4);
	printArray(arr4, n4);
	std::cout << "Sorted array of elements: \n" << std::endl;
	printArray(arr4, n4);

	niceView();
	//Case 5:Sort atleast one NaN
	std::cout << "Case 5: Can sort atleast one NaN" << std::endl;
	float arr5[] = { sqrt(-55),-344, -6.4, NAN, 11, INFINITY, -INFINITY };//test elements have been pre-inputted into the compiler.
	int n5 = sizeof(arr5) / sizeof(arr5[0]);
	printArray(arr5, n5);
	bubbleSort(arr5, n5);
	std::cout << "Sorted array of elements: \n" << std::endl;
	printArray(arr5, n5);

	niceView();
	//Case 6:Sort 2 NaNs
	std::cout << "Case 6:Can sort data with at least two different NaNs" << std::endl;
	
	float arr6[] = { sqrt(3),-3, (0.0), 111, NAN*1, NAN*-2, INFINITY, -INFINITY};//test elements have been pre-inputted into the compiler.
	
	int n6 = sizeof(arr6) / sizeof(arr6[0]);
	printArray(arr6, n6);
	bubbleSort(arr6, n6);
	std::cout << "Sorted array of elements: \n" << std::endl;
	printArray(arr6, n6);


	niceView();
	return 0;
}
