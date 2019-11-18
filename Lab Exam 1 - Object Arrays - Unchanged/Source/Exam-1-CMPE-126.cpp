#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Student.h"
using namespace std;


int main() {

	cout << "Program written by Jasper Tan, S. ID: 012154311" << endl;
	cout << "CMPE 126, Frank Lin" << endl;

	ifstream instream;
	instream.open("students.txt");
	if (instream.fail()) {
		cout << "Input file has failed to open" << endl;
		exit(1);
	}

	ofstream top1;
	top1.open("top_1.txt");
	if (top1.fail()) {
		cout << "Output file top 1 has failed to open" << endl;
		exit(1);
	}

	ofstream top3;
	top3.open("top_3.txt");
	if (top3.fail()) {
		cout << "Output file top 3 has failed to open" << endl;
		exit(1);
	}

	ofstream bonus;
	bonus.open("GiveMeBonus.txt");
	if (bonus.fail()) {
		cout << "Output file bonus has failed to open" << endl;
		exit(1);
	}

	int numberOfStudents = 9;
	int count = 0;
	int* scores = new int[numberOfStudents];

	string sub1;
	string line;
	string* all = new string[numberOfStudents];

	Student result;
	Student* students = new Student[numberOfStudents];

	cout << "All student information from file outputted to console: " << endl << endl;

	while (getline(instream, line)) {

		sub1 = line.substr(line.length() - 2, 2);
		students[count].set_everything(line);

		students[count].set_score(atoi(sub1.c_str()));
		result = result + students[count];

		cout << students[count].return_everything() << endl;

		count++;
	}

	result.set_average(result.return_score() / numberOfStudents);
	cout << endl << "The average scores of the students is: " << result.return_average() << endl;

	Student max = students[0];

	for (int i = 0; i < numberOfStudents; i++) {
		if (max.return_score() < students[i].return_score()) {
			max = students[i];
		}

	}

	// using operator overloaded '<<'
	cout << max;
	top1 << max;

	Student temp;

	for (int i = 0; i < numberOfStudents - 1; i++) {
		for (int j = i + 1; j < numberOfStudents; j++) {
			if (students[j].return_score() < students[i].return_score()) {
				temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}

	bonus << "The organized list is: " << endl;

	for (int i = 0; i < numberOfStudents; i++) {
		bonus << students[i].return_everything() << endl;
	}

	top3 << "The top 3 students are: " << endl;
	top3 << students[8].return_everything() << endl;
	top3 << students[7].return_everything() << endl;
	top3 << students[6].return_everything() << endl;

	cout << endl;
	cout << endl;
	cout << "***SEE EXTRA FILES***" << endl;
	cout << "***SEE EXTRA FILES***" << endl;
	cout << "***SEE EXTRA FILES***" << endl;
	cout << "***SEE EXTRA FILES***" << endl;
	cout << "***SEE EXTRA FILES***" << endl;
	cout << "***SEE EXTRA FILES***" << endl;
	cout << "***SEE EXTRA FILES***" << endl;

}



