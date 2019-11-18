#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
using namespace std;

class Complex {

	friend Complex operator +(const Complex& o1, const Complex& o2);
	friend ostream& operator<<(ostream& outstream, Complex& out);

private:

	int real;
	int imaginary;

public:

	Complex();
	Complex(int r, int i);

	void set_real(int r);
	void set_imaginary(int i);
	int return_real();
	int return_imaginary();


};

#endif
