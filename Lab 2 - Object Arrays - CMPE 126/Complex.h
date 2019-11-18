#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
using namespace std;

class Complex {

	friend Complex operator +(const Complex& o1, const Complex& o2);
	friend ostream& operator<<(ostream& outstream, Complex& out);

private:

	double real;
	double imaginary;
	double value;

public:

	Complex();
	Complex(double r, double i, double v);

	void set_real(double r);
	void set_imaginary(double i);
	void set_value(double v);
	double return_real();
	double return_imaginary();
	double return_value();

	void operator =(Complex c);

};

#endif