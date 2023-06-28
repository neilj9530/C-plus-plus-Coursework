// Code written by James Neil NUID: 002250732

#include <iostream>
#include <string>  // include the string library to work with strings in our code
using namespace std;

struct classInfo {  // this struct will be used for our student names and grades
	string name;
	int grade;
};

int getClassSize();
string getName();
int getGrade();
void orderData(classInfo*, int);
void avgMed(classInfo*, int);
void maxThree(classInfo*, int);
void minThree(classInfo*, int); // initialize all of our functions

int main() { 
	classInfo tempInfo = {" ", 0 };  // create a temporary point on the struct 
	int classSize = getClassSize(); 
	classInfo* data = new classInfo[classSize]; // create an array of structs with the class size as array size
	for (int i = 0; i < classSize; i++) {
		data[i] = { getName(), getGrade() }; //assign a name and grade to each point on the array
	}
	orderData(data, classSize); // run the function to order our data for the other functions
	avgMed(data, classSize);
	maxThree(data, classSize);
	minThree(data, classSize); // run our 3 functions that output avg, med, max 3 and min 3 grades
	delete[] data; // delete our memory allocation
}

int getClassSize() { // function used to get class size
	int classSize;
	cout << "What is the size of the class?";
	cin >> classSize; // asks for an input of the size of the class as an integer
	return classSize;
}

string getName() { // this function will help us obtain an input of each student's name
	string firstnameTemp, lastnameTemp, fullnameTemp;
	cout << "Please input student's first name: ";
	cin >> firstnameTemp; // input the first name of the student
	fullnameTemp.append(firstnameTemp);
	cout << "Please input " << firstnameTemp << "'s last name: ";
	cin >> lastnameTemp; // input the last name of the student
	fullnameTemp.append(" " + lastnameTemp); // append the first and last names of the student together
	return fullnameTemp;
}

int getGrade() { // function to input a grade for a student
	int gradeTemp;
	cout << "What is this student's grade? ";
	cin >> gradeTemp; // input the grade of the student
	return gradeTemp;
}

void orderData(classInfo* data, int size) { // function to order our data by grades
	string tempname = "";
	int tempgrade = 0;
	for (int i = 0; i < size - 1; i++)
		for(int j = i + 1; j < size; j++)  // a simple sorting loop for the data
			if (data[i].grade >= data[j].grade) {
				tempgrade = data[i].grade;
				tempname = data[i].name;
				data[i].grade = data[j].grade;
				data[j].grade = tempgrade;
				data[i].name = data[j].name;
				data[j].name = tempname;
			}
}

void avgMed(classInfo * data, int size) { // finds the avg and median of the grades
	double sum = 0;
	double avg = 0;
	double med = 0;
	for (int i = 0; i < size; i++) {      // add all of the grades
		sum += data[i].grade;
	}
	avg = sum / size; // calculate avg grade
	cout << "The average grade is: " << avg << "\n";
	if ((size % 2) == 0) {  // if class size is even
		int halfsize = size / 2;
		med = (data[halfsize - 1].grade + data[halfsize].grade) / 2.0; //median is avg of middle two grades
	}
	else { // if class size is odd
		int halfsize = (size / 2) + 1; // median is the middle grade
		med = data[halfsize - 1].grade;
	}
	cout << "The median grade is: " << med << "\n";
}

void maxThree(classInfo* data, int size) { // a function that simply outputs the top 3 students and their grades
	cout << "The top three students are: ";
	cout << data[size - 3].name << " with a grade of " << data[size - 3].grade << "\n";
	cout << data[size - 2].name << " with a grade of " << data[size - 2].grade << "\n";
	cout << data[size - 1].name << " with a grade of " << data[size - 1].grade << "\n";
}

void minThree(classInfo* data, int size) { // a function that simply outputs the bottom 3 students and their grades
	cout << "The bottom three students are: ";
	cout << data[2].name << " with a grade of " << data[2].grade << "\n";
	cout << data[1].name << " with a grade of " << data[1].grade << "\n";
	cout << data[0].name << " with a grade of " << data[0].grade << "\n";
}
