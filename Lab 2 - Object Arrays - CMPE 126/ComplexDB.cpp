#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Complex.h"
#include "ComplexDB.h"
using namespace std;


ComplexDB::ComplexDB() {
	size = 0;
	max_size = 20;
	data = new Complex[max_size];
}

ComplexDB::ComplexDB(int max) {
	size = 0;
	max_size = max;
	data = new Complex[max_size];
}

void ComplexDB::set_size(int s) {
	size = s;
}
void ComplexDB::set_max_size(int s) {
	max_size = s;
}


void ComplexDB::set_data(double real, double imaginary, int count) {

	data[count].set_real(real);
	data[count].set_imaginary(imaginary);

}

void ComplexDB::print_data() {
	sort();
	
	for (int i = 0; i < size; i++) {
		cout << i + 1<< ". " << "Real: " << data[i].return_real() << " " << "Imag: " << data[i].return_imaginary() << "j  " << "Value: " << data[i].return_value() << endl;
	}
}


void ComplexDB::add() {
	double real;
	double imaginary;

	if (size >= max_size) {
		cout << "Max size reached" << endl;
	}
	else {
		cout << "Enter real number: ";
		cin >> real;

		cout << "Enter imaginary number: ";
		cin >> imaginary;

		data[size].set_real(real);
		data[size].set_imaginary(imaginary);
		size++;
	}
	sort();
}

void ComplexDB::sort() {

	Complex temp;

	for (int i = 0; i < size; i++) {
		data[i].set_value((data[i].return_real() * data[i].return_real()) + (data[i].return_imaginary() * data[i].return_imaginary()));
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (data[i].return_value() > data[j].return_value()) {
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
	}

}

void ComplexDB::remove() {
	int choice;
	cout << "Which list option would you like to remove?" << endl;
	cin >> choice;
	choice -= 1;

	for (int i = choice; i < size; i++) {
		data[i] = data[i + 1];
	}
	size--;
	sort();
}

ostream& operator <<(ostream& out, ComplexDB& o1) {
	out << "Saved results: " << endl;
	for (int i = 0; i < o1.size; i++) {
		out << i + 1 << ". " << "Real: " << o1.data[i].return_real() << " " << "Imag: " << o1.data[i].return_imaginary() << "j  " << "Value: " << o1.data[i].return_value() << endl;
	}
	return out;
}

ComplexDB::~ComplexDB() {
	delete[]data;
}
