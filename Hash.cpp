// Code written by James Neil NUID: 002250732

#include <iostream>
#include <random>
using namespace std;

int randomBirthday();
void sumStats(int[], int);

int main() {
	int n = 1000;  // size of the random birthday array
	int m1 = 97;
	int m2 = 98;
	int m3 = 100;
	int birthdays[1000] = {};
	for (int i = 0; i < n; i++) {
		birthdays[i] = randomBirthday();  // create an array of random integers
	}
	int h1[97] = {};
	for (int i = 0; i < m1; i++) {  // assign 0 to every value of the hash at first
		h1[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int j = birthdays[i] % m1;   // calls our hash function in order to get a key
		h1[j] = h1[j] + 1;      // adds a collision to the slot in the table
	}
	cout << "For h1, here are our summary statistics: \n";   // print out summary statistics
	sumStats(h1, m1);
	int h2[98] = {};
	for (int i = 0; i < m2; i++) {
		h2[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int k = birthdays[i] % m2;
		h2[k] = h2[k] + 1;
	}
	cout << "For h2, here are our summary statistics: \n";  // do the same for h2 and h3
	sumStats(h2, m2);
	int h3[100] = {};
	for (int i = 0; i < m3; i++) {
		h3[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int l = birthdays[i] % m3;               
		h3[l] = h3[l] + 1;
	}
	cout << "For h3, here are our summary statistics: \n";
	sumStats(h3, m3);
}

int randomBirthday() { // function for generating random birthdays in mm/dd/yy format
	random_device rd;   // create a random integer generator
	mt19937 rInt(rd());
	uniform_int_distribution<> month(1, 12); // split the random integers between month/day/year to make it easier to generate
	uniform_int_distribution<> day(1, 27);
	uniform_int_distribution<> year(0, 4);
	int x = month(rInt);
	x = x * 10000;          // multiply to make it easy to add the integers together
	int y = day(rInt);
	y = y * 100;
	int z = year(rInt);
	int birthday = x + y + z;  // add them together to give us the integer in mm/dd/yy format
	return birthday;
}

void sumStats(int h[], int m) {     // function to find and print out the min, max, mean, and var of each hash table
	int min = 1000;
	int max = 0;
	int sum = 0;
	for (int i = 0; i < m; i++) { 
		if (h[i] < min) {            // checks for a new min
			min = h[i];
		}
		if (h[i] > max) {            // checks for a new max
			max = h[i];
		}
		sum = sum + h[i];            // adds to the sum each iteration
	}
	int mean = sum / m;
	int error = 0;
	for (int i = 0; i < m; i++) {    // calculates the sum of sq error
		error = error + ((h[i] - mean) * (h[i] - mean));
	}
	int var = error / m;
	cout << "The minimum collision value is: " << min << "\n";      // prints out the summary statistics
	cout << "The maximum collision value is: " << max << "\n";
	cout << "The mean of the collision values is: " << mean << "\n";
	cout << "The variance of the collision values is: " << var << "\n";
}