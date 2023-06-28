// Code written by James Neil NUID: 002250732

#include <iostream>
using namespace std;

void SwapP(int*, int*);
void SwapR(int&, int&); // initialize our SwapP and SwapR functions

int main() { // main function will test both of our functions SwapP and SwapR
	int x = 15, y = 4;
	int a = 23, b = 58;
	cout << "x = " << x << " before SwapP\n";
	cout << "y = " << y << " before SwapP\n"; //output our starting integer values for testing SwapP
	SwapP(&x, &y); 
	cout << "x = " << x << " after SwapP\n";
	cout << "y = " << y << " after SwapP\n"; // output the integers after running SwapP
	cout << "a = " << a << " before SwapR\n";
	cout << "b = " << b << " before SwapR\n"; // output the starting integer values for testing SwapR
	SwapR(a, b);
	cout << "a = " << a << " after SwapR\n"; 
	cout << "b = " << b << " after SwapR\n"; // output the integers after running SwapR
	return 0;
}

void SwapP(int *x, int *y) { // function that will swap the two input integers using pass-by-pointer
	int z = *x; //creates a temporary local integer to use as a base for the swap
	*x = *y; 
	*y = z; 
}

void SwapR(int& a, int& b) { // function that will swap the two input integers using pass-by-reference
	int c = a; //creates a temporary local integer to use as a base for the swap
	a = b;
	b = c;
}
