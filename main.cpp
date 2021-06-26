// Lab 4: Dynamic Memory Part 2
// written by: Tom marazzo
// This file is used to demonstrate dynamic memory in
// C++ and to process an array of objects of compound
// type where the user specifies the number of
// elements in the array at run-time.
/////////////////////////////////////////////////////
// Name: KARAN BAGGA
// Student Number: 200449124
/////////////////////////////////////////////////////

#include <iostream>
#include "Weather.h"

using namespace std;

double findLow(const char*, const Weather*, int);

int main()
{
	int i; // loop counter
	int n; // number of objects in Weather array

	// declared a pointer named weatherArray of type Weather here
	Weather* weatherArray = nullptr;

	cout << "Weather Data" << endl
		<< "=====================" << endl
		<< "Days of Weather: ";
	cin >> n;
	cin.ignore();

	// allocated dynamic memory for weatherArray here
	weatherArray = new Weather[n];

	for (i = 0; i < n; i++)
	{
		char dateDescription[7];
		double high;
		double low;

		// added code to accept the user input for the weather array and set the data
		// for each object of weatherArray
	   //[Hint] get() and ignore()

		cout << "Enter the description of date: ";
		cin.get(dateDescription, 7, '\n');
		cin.ignore();   //it is used to clear or ignore characters from input stream

		cout << "Enter value that is high: ";
		cin >> high;
		cin.ignore();   //it is used to clear or ignore characters from input stream

		cout << "Enter value that is low: ";
		cin >> low;
		cin.ignore();   //it is used to clear or ignore characters from input stream

		weatherArray[i].setData(dateDescription, low, high);
	}

	cout << endl
		<< "Weather report:" << endl
		<< "Date high low" << endl
		<< "======================" << endl;

	for (i = 0; i < n; i++)
	{
		weatherArray[i].display();
	}

	char query[7];
	cout << endl << "Enter the date you are looking for: ";
	cin.getline(query, 7, '\n');
	double low = findLow(query, weatherArray, n);
	cout << "Low temperature: " << low << endl;

	// deallocated dynamic memory here using delete[] and assigning it null pointer value again

	delete[] weatherArray;
	weatherArray = nullptr;

	return 0;
	
}

// add findLow global function implementation here
double findLow(const char* date, const Weather* data, int dataSize)
{
	for (int n = 0; n < dataSize; n++)
	{
		Weather w1 = data[n];

		if (strncmp(w1.getDate(), date, strlen(date)) == 0)
		{
			return w1.getLow();
		}
		else
		{
			return 0.0;
		}
	}
}


