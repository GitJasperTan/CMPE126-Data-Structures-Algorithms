#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;


Complex::Complex() {
	real = 0;
	imaginary = 0;
}

Complex::Complex(int r, int i) {
	real = r;
	imaginary = i;
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

void Complex::set_real(int r) {
	real = r;
}

void Complex::set_imaginary(int i) {
	imaginary = i;
}

int Complex::return_real() {
	return real;
}

int Complex::return_imaginary() {
	return imaginary;
}

