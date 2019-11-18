#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

class Student {
private:
	int student_id;
	string fname;
	string lname;
	string phone;
	string email;
public:
	Student();
	void set_all(int s, string f, string l, string p, string e);
	void print_all();
	int return_id();
	string return_fname();
	string return_lname();
	string return_phone();
	string return_email();
	void set_id(int i);
};

#endif
