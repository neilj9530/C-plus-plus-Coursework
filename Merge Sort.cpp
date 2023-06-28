// Code written by James Neil NUID: 002250732

#include <iostream>
#include <random> // needed for assigning random integer values to the array
using namespace std;

int getSize();
void mergeSort(double*, int, int);
void merge(double*, int, int, int);

int main() {
	int n = getSize();
	random_device rd;  // create a random seed
	mt19937 rInt(rd());  // create an engine using the random seed
	uniform_int_distribution<> uniform(0, 100);  //create a uniform distribution 0-100 to draw random integers from
	double* A = new double[n];
	for (int i = 0; i < n; i++) { // assigns random integers from the uniform distribution to the array
		A[i] = uniform(rInt);
	}
	for (int i = 0; i < n; i++) { // print the contents of the array before merge sort
		cout << A[i] << "\n";
	}
	mergeSort(A, 0, n - 1); // sort the array
	cout << "Here is the sorted array: \n";
	for (int i = 0; i < n; i++) { // print the contents of the array after merge sort
		cout << A[i] << "\n";
	}
	mergeSort(A, 0, n - 1); // check to see if the function skips the merge process entirely
	delete[] A;
}

int getSize() { // similar to previous homeworks, a simple function to ask for an integer
	int n;
	cout << "What is the size of the array between 2 and 50?";
	cin >> n;
	if ((n >= 2) and (n <= 50))  // restricts the integer output to the bounds we have set
		return n;
	else
		return getSize(); // asks for the integer again if it doesn't fit the criteria
}

void mergeSort(double* A, int p, int r) { // function used to sort the array using a merge method
	if (p < r) {
		int q = ((p + r) / 2);   // find the center point of the array
		mergeSort(A, p, q);  // recursively sort the first half of the array
		mergeSort(A, q + 1, r); // recursively sort the second half of the array
		merge(A, p, q, r); // merge the sorted arrays
	}
}

void merge(double* A, int p, int q, int r) { // function that merges two arrays 
	int n1 = q - p + 1;  // array sizes we will use
	int n2 = r - q;
	bool check = true;
	double* L = new double[n1 + 1];       // create two arrays to be merged together
	double* R = new double[n2 + 1];
	for (int i = 0; i < n1; i++)  // assigns values to one array
		L[i] = A[p + i];
	for (int j = 0; j < n2; j++)  // assigns values to the other array
		R[j] = A[q + j + 1];
	L[n1] = 101;
	R[n2] = 101; // upper limit so comparisons between arrays are always correct
	for (int i = 0; i < n1; i++) { // test if the array is already sorted
		for (int j = 0; j < n2; j++) {
			if (L[i] > R[j])               // if any integers in L are > R, set check to false
				check = false;
			else if (j > 0 and R[j] < R[j - 1]) // if any integers in R are less than the previous, set check to false
				check = false;
		}
		if (i > 0 and L[i] < L[i - 1])    // if any integers in L are less than the previous, set check to false
			check = false;
	}
	if (check == true) {
		cout << "Already sorted, skipping merge of p =" << p << " and r =" << r <<  "\n"; // lets us know that it skipped the merge step
		return;
	}
	int i = 0;
	int j = 0;
	for (int k = p; k < r + 1; k++) { // sorts and then merges into the main array
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i = i + 1;
		}
		else {
			A[k] = R[j];
			j = j + 1;
		}
	}
	cout << "Merged p =" << p << " with r =" << r << "\n"; // lets us know which merges went through
	delete[] L;
	delete[] R;
}