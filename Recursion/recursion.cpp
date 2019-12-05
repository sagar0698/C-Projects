#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Routine that prints contents of array of strings
*/
void printarray(int array[], int count) {
	int i;
	for (i = 0; i < count - 1; i++) {
		cout << array[i] << ", ";
	}
	cout << array[i];
	cout << endl;
}

int countPositive(int* array, int first, int last) {
	if (first > last)  //base case
		return 0;
	if (array[first] > 0)   //recursive function 
		return 1 + countPositive(array, first + 1, last);
	else
		return 0 + countPositive(array, first + 1, last);
}

int countRange(int* array, int first, int last) /*# of values between 20 - 30*/
{
	if (first > last)  //base case
		return 0;
	if (array[first] <= 20 && array[first] >= 30)
		return 1 + countRange(array, first +  1, last);
	else
		return array[first] + countRange(array, first +  1, last);
}

int getMaximum(int* array, int first, int last)
{
	if (first > last)  //invalid case     
		return 0;
	if (first == last)  //base case
		return array[first];
	if (array[first] > array[last])  //recursive case 
		return getMaximum(array, first, last - 1);
	else
		return getMaximum(array, first + 1, last);
}

int getMinimum(int* array, int first, int last)
{
	if (first > last)  //invalid case
		return 0;
	if (first == last)  //base case
		return array[first];
	if (array[first] > array[last])  //recursive case
		getMinimum(array, first + 1, last);
	else
		getMinimum(array, first, last - 1);
}

int getSum(int* array, int first, int last)
{
	if (first > last)  //invalid case
		return 0;
	if (first == last)  //base case
		return array[first];
	return array[first] + getSum(array, first + 1, last);  //recursion
}

int getProduct(int* array, int first, int last)
{
	if (first > last)  //invalid case
		return 0;
	if (first == last)  //base case
		return array[first];
	return array[first] * getProduct(array, first + 1, last);  //recursion
}

#define SIZE_OF_ARRAY 12

int main()
{
	int test_array[SIZE_OF_ARRAY] = { 5,1,-1,1,24,1,-1,1,1,1,-10,29 };
	int prod_array[SIZE_OF_ARRAY] = { 5,1,-1,1,20,1,1,1,1,1,-1,10 };


	// print opening meessage

	cout << endl << "Array to be used contains:" << endl;

	printarray(test_array, SIZE_OF_ARRAY);

	cout << "Result of countPositive: " << countPositive(test_array, 0, SIZE_OF_ARRAY - 1) << endl;

	cout << "Result of countRange: " << countRange(test_array, 0, SIZE_OF_ARRAY - 1) << endl;

	cout << "Result of getMaximum: " << getMaximum(test_array, 0, SIZE_OF_ARRAY - 1) << endl;

	cout << "Result of getMinimum: " << getMinimum(test_array, 0, SIZE_OF_ARRAY - 1) << endl;

	cout << "Result of getSum: " << getSum(test_array, 0, SIZE_OF_ARRAY - 1) << endl;

	cout << "Result of getProduct: " << getProduct(test_array, 0, SIZE_OF_ARRAY - 1) << endl;

	system("pause");
}
