#ifndef COMPLEX_H
#define COMPLEX_H
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Complex {
	friend Complex operator +(Complex& o1, Complex& o2);
	friend bool operator >=(Complex& o1, Complex& o2);
private:
	double real;
	double imaginary;
	double magnitude;
public:
	Complex();
	Complex(double r, double i);
	void set_real(double r);
	void set_imaginary(double i);
	void set_magnitude();
	double return_real();
	double return_imaginary();
	double return_magnitude();
	void printout();
};

//**********************************************************************************************************//
//***** ComplexDB part*****//
//**********************************************************************************************************//

class ComplexDB {
private:
	int size;
	int max_size;
	Complex* data;
public:
	ComplexDB();
	ComplexDB(int max);
	void loadfile(string file);
	void print();
	Complex largest_mag(int smallest_index, int largest_index);
	int return_size();
	Complex* return_data();
};










#endif	

