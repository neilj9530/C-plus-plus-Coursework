// Code written by James Neil NUID: 002250732

#include <iostream>
using namespace std;

void MaxFirst(int[], int);

int main() {
	int v[] = { 6, 1, 7, 8, 2, 5 }; //Declare array
	MaxFirst(v, 6); //Bring Max value to beginning
	for (int i = 0; i < 6; i++) //Print array
		cout << v[i] << ' ';
	return 0;
}

void MaxFirst(int n[], int nlength) {
	int max = 0;
	int replace = 0;
	for (int i = 0; i < nlength; i++) // loop through each integer in the array
		if (n[i] >= max) // if the array value is greater than the max value, create a new max value
			max = n[i], replace = i; //replace integer will be used to find the array location as a swap target
	n[replace] = n[0]; //replace the max value's original location with the first value in the array
	n[0] = max; //replace the first value in the array with the max value 
}