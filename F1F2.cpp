// Code written by James Neil NUID: 002250732

#include <iostream>
using namespace std;

int F1(int);
int F2(int);

int main() {
	int n = 5;
	cout << "F1 test results: " << F1(n) << "\n";
	cout << "F2 test results: " << F2(n) << "\n";
}

int F1(int n) {
	if (n == 0)
		return 1;
	return F1(n - 1) + F1(n - 1);
}

int F2(int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 0) {
		int result = F2(n / 2);
		return result * result;
	}
	else
		return 2 * F2(n - 1);
}