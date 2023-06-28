// Code written by James Neil NUID: 002250732

#include <iostream>
#include <chrono>
#include <fstream>
#include <stdexcept>
#include <string>
using namespace std;

int moves = 0;
int comps = 0;  // global integer variables for counting movements/computations

void copy(int[], int*);
void Insert(int*);
void Heap(int*);
int left(int);
int right(int);
void maxHeapify(int*, int, int);
void buildmaxHeap(int*);
void Quick(int*, int, int);
int partition(int*, int, int);
bool sortCheck(int*);

void toTextFile(string, string);

int main() {
	int BST[1000] = {};
	int AVG[1000] = {};
	int WST[1000] = {};
	int* tBST = new int[1000];
	int* tAVG = new int[1000];
	int* tWST = new int[1000];  // initialize all of our arrays

	srand(time(NULL)); // creates a random generator for our average array

	for (int i = 0; i < 1000; i++)  // create a pre-sorted array for BST in ascending order
		BST[i] = 10 * i + 10;
	for (int i = 0; i < 1000; i++)  // create a pre-sorted array for WST in descending order
		WST[i] = 10000 - 10 * i;
	for (int i = 0; i < 1000; i++)  // create an array of random integers 0-100000 for AVG
		AVG[i] = rand() % 100000;

	copy(BST, tBST);
	copy(AVG, tAVG);
	copy(WST, tWST);      // initialize our test arrays

	Insert(tBST);
	toTextFile("Insertion sort", "BST");
	Insert(tAVG);
	toTextFile("Insertion sort", "AVG");
	Insert(tWST);                         // run the insertion sort on each test array and edit text file each call
	toTextFile("Insertion sort", "WST");

	copy(BST, tBST);
	copy(AVG, tAVG);
	copy(WST, tWST);      // re-initialize our test arrays

	Heap(tBST);
	toTextFile("Heap sort", "BST");
	Heap(tAVG);
	toTextFile("Heap sort", "AVG");
	Heap(tWST);                          // run the heap sort on each test array and edit text file each call
	toTextFile("Heap sort", "WST");

	copy(BST, tBST);
	copy(AVG, tAVG);
	copy(WST, tWST);      // re-initialize our test arrays one last time

	Quick(tBST, 0, 999);
	if (sortCheck(tBST) == false)  // check if sorted properly
		cout << "Didn't sort properly" << "\n";
	cout << "Number of moves: " << moves << "\n";
	cout << "Number of comps: " << comps << "\n";
	toTextFile("Quick sort", "BST");
	Quick(tAVG, 0, 999);
	if (sortCheck(tAVG) == false)  // check if sorted properly
		cout << "Didn't sort properly" << "\n";
	cout << "Number of moves: " << moves << "\n";
	cout << "Number of comps: " << comps << "\n";
	toTextFile("Quick sort", "AVG");
	Quick(tWST, 0, 999);  // run the quick sort on each test array and edit text file each call
	if (sortCheck(tWST) == false)  // check if sorted properly
		cout << "Didn't sort properly" << "\n";
	cout << "Number of moves: " << moves << "\n";
	cout << "Number of comps: " << comps << "\n";
	toTextFile("Quick sort", "WST");

	delete[] tBST;
	delete[] tAVG;
	delete[] tWST;
}

void copy(int A[], int * B) {
	for (int i = 0; i < 1000; i++)
		B[i] = A[i];
}

void Insert(int* A) {       // insertion sort function
	moves = 0;
	comps = 0;
	for (int i = 1; i < 1000; i++) {
		int k = A[i];
		int j = i - 1;
		while (j >= 0 and A[j] > k) {
			A[j + 1] = A[j];
			j = j - 1;
			comps++;
			moves++;           // increments moves based on how many times the while loop runs
		}
		A[j + 1] = k;
		comps++;
	}
	cout << "Number of moves: " << moves << "\n";
	cout << "Number of comps: " << comps << "\n";
	if (sortCheck(A) == false)    // check if sorted properly
		cout << "Didn't sort properly" << "\n";
}

void Heap(int* A) {
	moves = 0;
	comps = 0;
	buildmaxHeap(A);   // create a Max Heap
	int heapsize = 999;
	for (int i = 999; i > 0; i--) {   // for each array value, switch last val with the root and then heapify without the root
		int k = A[i];
		A[i] = A[0];
		A[0] = k;
		moves++;
		heapsize = heapsize - 1;
		maxHeapify(A, 0, heapsize);
	}
	cout << "Number of moves: " << moves << "\n";
	cout << "Number of comps: " << comps << "\n";
	if (sortCheck(A) == false)  // check if sorted properly
		cout << "Didn't sort properly" << "\n";
}

int left(int i) {
	return (2 * (i + 1)); 
}
int right(int i) {
	return (2 * (i + 1) + 1);
}

void maxHeapify(int* A, int i, int heapsize) {
	int l = left(i) - 1;
	int r = right(i) - 1;
	int largest = 0;
	if (l <= heapsize and A[l] > A[i])
		largest = l;
	else largest = i;
	comps++;
	if (r <= heapsize and A[r] > A[largest])
		largest = r;
	comps++;
	if (largest != i) {
		int k = A[i];
		A[i] = A[largest];
		A[largest] = k;
		moves++;
		maxHeapify(A, largest, heapsize);
	}
	comps++;
}

void buildmaxHeap(int* A) {
	for (int i = 500; i > 0; i--)
		maxHeapify(A, i-1, 999);
}

void Quick(int* A, int p, int r) {
	if (p == 0 and r == 999) {       // initial call sets moves and comps to 0
		moves = 0;
		comps = 0;
	}
	if (p < r) {
		int q = partition(A, p, r);   // partition the array and find halfway point
		Quick(A, p, q - 1);           // recursive calls with partitions
		Quick(A, q + 1, r);
	}
	comps++;
}

int partition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++) {      
		if (A[j] <= x) {
			i = i + 1;
			int key = A[i];
			A[i] = A[j];
			A[j] = key;
			moves++;
		}
		comps++;
	}
	int key = A[i + 1];
	A[i + 1] = A[r];
	A[r] = key;
	moves++;
	return i + 1;
}

bool sortCheck(int* A) {
	for (int i = 0; i < 999; i++) {
		if (A[i] > A[i + 1]) {
			return false;
		}
	}
}

void toTextFile(string sort, string array) {  // takes the name of the sort method and which array it used
	ofstream outf;

	outf.open("sort.txt", ios::app); 
	if (outf.fail()) {
		cerr << "Error: Could not open output file\n";
		exit(1);
	}

	outf << sort << " on " << array << " gives us " << moves <<   // edits the sort text file to give moves/comps
		" moves and " << comps << " comparisons.\n";

	outf.close();
}