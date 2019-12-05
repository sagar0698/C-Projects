#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int find(int valueToSearchFor, int array[], int validNumberofEntries)
{
	for (int i = 0; i < validNumberofEntries; i++)
		if (array[i] == valueToSearchFor)
			return i;
	return -1;
}

int main() 
{
	//Ask user to enter numbers in a array
	//Keep track of many numbers were read in
	int table[10];
	cout << "Enter the number of integers there should be in the array (between 5 and 10):  ";
	cout << "Enter -1 to stop the program " << endl;
	for (int i = 0; i < 5; i++)
		cin >> table[i];

	int count = 5;
	while (count <= 10)
	{
		cin >> table[count];
		if (table[count] < 0)
			break;
		count++;
	}
	
	/*Print how many numbers were read in, and then print out all the numbers that 
	were stored in the array*/
	cout << "Total numbers read in the array is: " << count << ". \n";
	cout << "The numbers are: " << endl;
	for (int i = 0; i < count; i++) 
	{
		cout << table[i] << "  ";
	}
	cout << endl;

	/*Find and print the average. The find and print how many of the numbers are less 
	than the average calculated aobve, how many are exactly the samme value as the 
	average, and how many were greater than the average. Test and make sure it works*/
	double average = 0;
	for (int i = 0; i < count; i++)
		average += table[i];
	average /= count;
	cout << "The average of the above number is: " << average << endl;
	int numberLessThanAverage = 0;
	int numberGreaterThanAverage = 0;
	int numberEqualAverage = 0;
	for (int i = 0; i < count; i++)
		if (table[i] < average)
			numberLessThanAverage++;
		else if (table[i] > average)
			numberGreaterThanAverage++;
		else
			numberEqualAverage++;

	cout << "Total numbers less than average is: " << numberLessThanAverage << endl;
	cout << "Total numbers greater than average is: " << numberGreaterThanAverage << endl;
	cout << "Total numbers equaling to the average is: " << numberEqualAverage << endl;

	// Asking the user to run the program again
	int again;
	do
	{
		cout << "Enter a value to search for: ";
		int search;
		cin >> search;

		int found = find(search, table, count);
		if (found != -1)
			cout << "Not found " <<  endl;
		else
			cout << "Found at" << found << endl;
		cout << "Would you like to search another value " << endl;
		cout << "Enter 1 for Yes, and any other value would be No: ";
		cin >> again;
		if (again != -1)
			break;
	} 
	while (true);
}
