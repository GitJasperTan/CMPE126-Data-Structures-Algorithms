#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Student.h"
using namespace std;

Student::Student() {
	std_id = 0;
	phone = 0;
	name = "";
	email = "";
	score = 0;
}

void Student::set_score(double s) {
	score = s;
}
double Student::return_score() {
	return score;
}
void Student::set_average(double a) {
	average = a;
}
double Student::return_average() {
	return average;
}
void Student::set_everything(string s) {
	everything = s;
}
string Student::return_everything() {
	return everything;
}

Student Student::top_student(Student o1[]) {

	Student max = o1[0];
	for (int i = 1; i < 9; i++) {
		if (max.score < o1[i].score) {
			max = o1[i];
		}
	}

	return max;
}


Student operator +(Student& o1, Student& o2) {
	Student test;
	test.score = o1.score + o2.score;
	return test;
}

ostream& operator<<(ostream& out, Student& o1) {
	out << "The student with the highest score is: " << endl << o1.return_everything();
	return out;
}