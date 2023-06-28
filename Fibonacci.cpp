// Code written by James Neil NUID: 002250732

#include <iostream>
#include <time.h> // for clock function
using namespace std;

int FibonacciD(int);
int FibonacciR(int);

int A[50];

int main() {
	int n; //input for Fibonacci sequence
	cout << "n = ";
	cin >> n;

	for (int i = 0; i <= n; i++) // initialize all elements to an invalid Fibonacci value
		A[i] = -1;

	clock_t d; //clock for measuring runtime of FibonacciD
	d = clock();
	//Find sequence n using Dynamic programming function
	cout << "FibonacciD(n) = " << FibonacciD(n);
	d = clock() - d;
	cout << "\nFibonacciD(n) took " << ((float)d / CLOCKS_PER_SEC) << " seconds";

	//Find sequence n using recursive only function
	cout << "\nFibonacciR(n) = " << FibonacciR(n);
	
	clock_t r;
	r = clock();
	cout << "\nFibonacciD(n) took " << ((float)r / CLOCKS_PER_SEC) << " seconds";
	r = clock() - r;

	return 0;
}

int FibonacciD(int n) {
	A[0] = 0;
	A[1] = 1;  //initialize array positions 0 and 1

	if (A[n] == -1)
		A[n] = (FibonacciD(n - 1) + FibonacciD(n - 2)); //recursively adds numbers in the array and assigns them values for future iterations
	
	return A[n];
}

int FibonacciR(int n) {
	if (n <= 1) // returns 0 for n = 0 and 1 for n = 1
		return n;
	return (FibonacciR(n - 1) + FibonacciR(n - 2)); //recursively adds the two numbers before it
}