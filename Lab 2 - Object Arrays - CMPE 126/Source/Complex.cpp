#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;


Complex::Complex() {
	real = 0;
	imaginary = 0;
	value = 0;
}

Complex::Complex(double r, double i, double v) {
	real = r;
	imaginary = i;
	value = v;
}

Complex operator +(const Complex& o1, const Complex& o2) {

	Complex result;
	result.real = o1.real + o2.real;
	result.imaginary = o1.imaginary + o2.imaginary;

	return result;
}

ostream& operator<<(ostream& outstream, Complex& obj) {

	outstream << "Summation of imaginary numbers is shown below: " << endl;

	if (obj.return_imaginary() > 0) {
		outstream << obj.return_real() << " + " << obj.return_imaginary() << "j" << endl;
	}
	else {
		outstream << obj.return_real() << obj.return_imaginary() << "j" << endl;
	}

	return outstream;
}

void Complex::set_real(double r) {
	real = r;
}

void Complex::set_imaginary(double i) {
	imaginary = i;
}

double Complex::return_real() {
	return real;
}

double Complex::return_imaginary() {
	return imaginary;
}

void Complex::set_value(double v) {
	value = v;
}
double Complex::return_value() {
	return value;
}

void Complex::operator=(Complex c) {
	real = c.return_real();
	imaginary = c.return_imaginary();
}
