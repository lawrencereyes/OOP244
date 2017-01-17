#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;

double findLow(const char* date, const Weather *data, int dataSize);

int main() {
	int i; //  loop counter
	int n; //the count of days worth of weather
		   // create the weather pointer here

	cout << "Weather Data\n";
	cout << "=====================" << endl;
	cout << "Days of Weather: ";
	cin >> n;
	cin.ignore();

	// allocate dynamic memory here
	Weather* weather = nullptr;
	weather = new Weather[n];

	for (i = 0; i < n; i++) {
		char date_description[7];
		double high;
		double low;

		// ... add code to accept user input for
		//weather
		cout << "Enter date: ";
		cin >> date_description;

		cout << "Enter high: ";
		cin >> high;

		cout << "Enter low : ";
		cin >> low;

		weather[i].set(date_description, high, low);
	}

	cout << endl
		<< "Weather report:" << endl
		<< "Date        high  low" << endl
		<< "======================" << endl;

	for (i = 0; i < n; i++) {
		weather[i].display();
	}

	char query[7];
	cout << endl << "Enter the date you are looking for: ";
	//accept user input for the date to find
	//(in this example stored in char query[7])
	// and display the found low temprature.
	cin.ignore();
	cin.getline(query, 7, '\n');

	double low = findLow(query, weather, n);
	cout << "Low temperature: " << low << endl;

	// deallocate dynamic memory here
	delete[] weather;
	weather = nullptr;

	system("pause");
	return 0;
}

double findLow(const char * date, const Weather * data, int dataSize) {
	for (int i = 0; i < dataSize; i++) {
		if (strcmp(data[i].date(), date) == 0) {
			return data[i].low();
		}
	}
	return 0.0;
}