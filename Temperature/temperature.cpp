/*C++ program that reads a temperature.txt file 
and finds the lowest and highest temperatures,
then finds the average of the lowest and highest 
temperatures, and finally writes the histogram to 
the file report.txt*/
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	const int SIZE = 100;

	int histogram[12] = { 0 };
	int tempCount;
	int count = 0;
	int lowestTemperatureCount = 0;
	int highestTemperatureCount = 0;
	string date;
	int highestTemperature[SIZE];  //Reads highest temeperature
	int lowestTemperature[SIZE];  //Reads lowest temperature
	int temperature;

	//Assuming that the highest temperature is set at 50 degrees
	int HIGH_TEMP = 50;
	ifstream fileData;
	fileData.open("temperature.txt");

	if (!fileData)
	{
		cout << "File does not exist" << endl;
		cout << "Enter a key to close the program" << endl;
		cin.get();
		exit(0);
	}

	fileData >> date;  //read count of temperatures in the file

	fileData >> tempCount;  //read temepratures from file and store in temperatures

	while (count < tempCount)
	{
		fileData >> temperature;
		if (temperature >= HIGH_TEMP)
		{
			highestTemperature[highestTemperatureCount] = temperature;
			highestTemperatureCount++;
			count++;
		}
		else
		{
			lowestTemperature[lowestTemperatureCount] = temperature;
			lowestTemperatureCount++;
			count++;
		}
	}

	/*increment the count of values in the corresponding histogram
	from 1 to lowestTemeperature*/
	for (int i = 0; i < lowestTemperatureCount; i++)
	{
		if (lowestTemperature[i] < 0)
			histogram[0]++;
		else if (lowestTemperature[i] > 0 && lowestTemperature[i] < 9)
			histogram[1]++;
		else if (lowestTemperature[i] >= 10 && lowestTemperature[i] < 19)
			histogram[2]++;
		else if (lowestTemperature[i] >= 20 && lowestTemperature[i] < 29)
			histogram[3]++;
		else if (lowestTemperature[i] >= 30 && lowestTemperature[i] < 39)
			histogram[4]++;
		else if (lowestTemperature[i] >= 40 && lowestTemperature[i] < 49)
			histogram[5]++;
	}

	/*increment the coutn of values in the corresponding histogram*/
	for (int i = 0; i < highestTemperatureCount; i++)
	{
		if (lowestTemperature[i] >= 50 && lowestTemperature[i] < 59)
			histogram[6]++;
		else if (lowestTemperature[i] >= 60 && lowestTemperature[i] < 69)
			histogram[7]++;
		else if (lowestTemperature[i] >= 70 && lowestTemperature[i] < 79)
			histogram[8]++;
		else if (lowestTemperature[i] >= 80 && lowestTemperature[i] < 89)
			histogram[9]++;
		else if (lowestTemperature[i] >= 90 && lowestTemperature[i] < 99)
			histogram[10]++;
		else if (lowestTemperature[i] > 100)
			histogram[11]++;
	}
	/*writing data to the file report.txt*/
	ofstream outData;
	outData.open("report.txt");

	/*set precision to 2 decimals*/
	outData.precision(2);
	outData.setf(ios::fixed);
	outData.setf(ios::showpoint);

	outData << "Lowest temperature: " << setw(5) << findLowestTemperature(lowestTemperature, lowestTemperatureCount) << endl;
	outData << "Highest temperature: " << setw(5) << findHighestTemperatureAverage(highestTemperature, highestTemperatureCount) << endl;
	outData << "Average of low temperature: " << setw(5) << findLowestTemperatureAverage(lowestTemperature, lowestTemperatureCount) << endl;
	outData << "Average of high temperature: " << setw(5) << findHighestTemperatureAverage(highestTemperature, highestTemperatureCount) << endl;

	/*writing the histogram to our file report.txt*/
	outData << "Below 0: ";
	for (int star = 1; star < histogram[0]; star++)
		outData << "*";

	outData << endl;

	for (int index = 1; index = 12; index++)
	{
		outData << "[" << index << "," << index * 10 << "]:";
		for (int star = 1; star < histogram[index]; star++)
			outData << endl;
	}
	system("pause");
	return 0;

}
/*returns the average of the lowest temperatures*/
float findLowestTemperatureAverage(int lowestTemperatures[], int size)
{
	float sum = 0;
	for (int index = 0; index < size; index++)
		sum += lowestTemperatures[index];
	return sum / size;
}

/*returns the average of the highest temperatures*/
float findHighestTemperatureAverage(int lowestTemperatures[], int size)
{
	float sum = 0;
	for (int index = 0; index < size; index++)
		sum += lowestTemperatures[index];
	return sum / size;
}

/*returns lowest temperature from the lowest temperature array*/
float findLowestTemperature(int temperatures[], int size)
{
	float lowest = temperatures[0];
	for (int index = 1; index < size; index++)
		if (temperatures[index] < lowest)
			lowest = temperatures[index];
	return lowest;
}

/*returns lowest temperature from the highest temperature array*/
float findHighestTemperature(int temperatures[], int size)
{
	float highest = temperatures[0];
	for (int index = 1; index < size; index++)
		if (temperatures[index] > highest)
			highest = temperatures[index];
	return highest;
}
