#include "Student.h"

Student::Student() {
	student_id = 0;
	fname = "";
	lname = "";
	phone = "";
	email = "";
}

void Student::set_all(int s, string f, string l, string p, string e) {
	student_id = s;
	fname = f;
	lname = l;
	phone = p;
	email = e;
}

void Student::print_all() {
	cout << student_id << " " << fname << " " << lname << " " << phone << " " << email << endl;
}

int Student::return_id() {
	return student_id;
}
string Student::return_fname() {
	return fname;
}
string Student::return_lname() {
	return lname;
}
string Student::return_phone() {
	return phone;
}
string Student::return_email() {
	return email;
}

void Student::set_id(int i) {
	student_id = i;
}