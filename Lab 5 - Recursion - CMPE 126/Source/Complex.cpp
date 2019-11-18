#include "Complex.h"

Complex::Complex() {
	real = 0;
	imaginary = 0;
	magnitude = 0;
}

Complex::Complex(double r, double i) {
	real = r;
	imaginary = i;
}

Complex operator +(Complex& o1, Complex& o2) {
	Complex o3;
	o3.set_real(o1.return_real() + o2.return_real());
	o3.set_imaginary(o1.return_imaginary() + o2.return_imaginary());
	return o3;
}

bool operator >=(Complex& o1, Complex& o2) {


	if (o1.return_magnitude() >= o2.return_magnitude()) {
		return true;
	}
	else {
		return false;
	}

}

void Complex::set_real(double r) {
	real = r;
}

void Complex::set_imaginary(double i) {
	imaginary = i;
}

void Complex::set_magnitude() {

	magnitude = (sqrt((real * real) + (imaginary * imaginary)));
}

double Complex::return_real() {
	return real;
}

double Complex::return_imaginary() {
	return imaginary;
}

double Complex::return_magnitude() {
	return magnitude;
}

void Complex::printout() {
	cout << "Real: " << real << " Imaginary: " << imaginary << "j Magnitude: " << magnitude << endl;
}


//**********************************************************************************************************//
//***** ComplexDB part*****//
//**********************************************************************************************************//


ComplexDB::ComplexDB() {
	size = 0;
	max_size = 20;
	data = new Complex[max_size];
}

ComplexDB::ComplexDB(int max) {
	size = 0;
	max_size = max;
	data = new Complex[max];
}

void ComplexDB::loadfile(string file) {

	ifstream instream;
	instream.open(file);
	if (instream.fail()) {
		cout << "Input file: " << file << " has failed to open" << endl;
		exit(1);
	}

	string line;
	string sub1;
	string sub2;

	while (getline(instream, line)) {

		if (line.length() < 4) { // Applicable to single digit complex numbers, i.e. 6 or 7i

			if (line.find("i") > 0) {
				data[size].set_real(0);
				data[size].set_imaginary(atof(line.c_str()));
			}
			else {
				data[size].set_imaginary(0);
				data[size].set_real(atof(line.c_str()));
			}
		
		}
		else if (line.find("+") > 0) { // Applicable to complex numbers with + in between, i.e. 5 + 6i

			sub1 = line.substr(0, line.find("+"));
			sub2 = line.substr(line.find("+") + 1, 5);
			data[size].set_real(atof(sub1.c_str()));
			data[size].set_imaginary(atof(sub2.c_str()));

		}
		else if (line.find("-", 1) > 0) { // Applicable to complete complex numbers with - inbetween, i.e. 4.4 - 4.5i
			
			sub1 = line.substr(0, line.find("-", 1));
			sub2 = line.substr(line.find("-", 1) + 1, 5);
			data[size].set_real(atof(sub1.c_str()));
			data[size].set_imaginary(atof(sub2.c_str()) * -1);
		}
		data[size].set_magnitude();
		size++;
	}

	instream.close();
}

void ComplexDB::print() {
	for (int i = 0; i < size; i++) {
		data[i].printout();
	}
	cout << endl;
}


Complex ComplexDB::largest_mag(int smallest_index, int largest_index) {

	Complex max;

	if (smallest_index == largest_index) {
		return data[smallest_index];
	}
	else {
		max = largest_mag(smallest_index + 1, largest_index);
		if (data[smallest_index] >= max) {
			return data[smallest_index];
		}
		else {
			return max;
		}
	}


}


int ComplexDB::return_size() {
	return size;
}

Complex* ComplexDB::return_data() {
	return data;
}











//int ComplexDB::largest(int list[], int lowerIndex, int upperIndex) {
//
//	int max;
//
//	if (lowerIndex == upperIndex) {
//		return list[lowerIndex];
//	}
//	else {
//		max = largest(list, lowerIndex + 1, upperIndex);
//		if (list[lowerIndex] >= max) {
//			return list[lowerIndex]
//		}
//		else {
//			return max;
//		}
//	}
//
//}