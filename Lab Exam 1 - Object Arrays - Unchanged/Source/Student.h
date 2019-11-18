#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;


class Student {
private:
	int std_id;
	int phone;
	string name;
	string email;
	string everything;
	double score;
	double average;
public:
	Student();
	Student top_student(Student o1[]);
	void set_score(double s);
	double return_score();
	void set_average(double a);
	double return_average();
	void set_everything(string s);
	string return_everything();
	friend Student operator +(Student& o1, Student& o2);
	friend ostream& operator<<(ostream& out, Student& o1);
};



#endif
