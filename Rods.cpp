// Code written by James Neil NUID: 002250732

#include <iostream>
#include <time.h> // for clock function
#include <math.h> // for floor function
using namespace std;

int RodCutR(int*, int);
int RodCutD(int*, int);
int RodCutDAux(int*, int, int*);

int main() {
	int n;
	cout << "n = ";
	cin >> n;

	int* price = new int[n]; // create a price array based on rod size
	price[0] = 2;
	for (int i = 1; i < n; i++) {
		if (i == (n - 1)) {
			price[i] = (i * 2.5) - 1; //if rod size is reached, this is the price
		}
		else {
			price[i] = floor(i * 2.5); //price if not rod size or length 1 (represented by array value 0)
		}
	}

	clock_t d; // set up a clock for testing the time of dynamic function
	d = clock();

	cout << "RodCutD(n) = " << RodCutD(price, n) << "$";

	d = clock() - d;
	cout << "\nRodCutD(n) took " << ((float)d / CLOCKS_PER_SEC) << " seconds";

	clock_t r; // set up a clock for testing the time of recursion function
	r = clock();

	cout << "\nRodCutR(n) = " << RodCutR(price, n) << "$";

	r = clock() - r;
	cout << "\nRodCutR(n) took " << ((float)r / CLOCKS_PER_SEC) << " seconds";
	
	delete[] price;
	return 0;
}

int RodCutR(int* p, int n) {
	if (n == 0)
		return 0; // stops the recursion if n = 0
	int q = -1;
	int max = 0;
	for (int i = 0; i < n; i++) {
		q = p[i] + RodCutR(p, n - i - 1); // check price for each way the rod is cut
		if (q > max)
			max = q;
	}
	return q; 
}

int RodCutD(int* p, int n) {
	int* r = new int[n];
	for (int i = 0; i < n; i++) { // create a new array to store revenues for each split
		r[i] = -1;
	}
	return RodCutDAux(p, n, r); // call recursion function
}

int RodCutDAux(int* p, int n, int* r) {
	if (n == 0)
		return 0; // stop the recursion if n = 0
	if (r[n] >= 0)
		return r[n]; // stop the recursion early if r[n] was defined in a previous iteration
	int q = -1;
	for (int i = 0; i < n; i++) {
		q = p[i] + RodCutDAux(p, n - i - 1, r); // same price check as the recursion function uses, but now with r array passed on
	}
	r[n - 1] = q; // assign q for this split to n - 1 array value
	return q;
}