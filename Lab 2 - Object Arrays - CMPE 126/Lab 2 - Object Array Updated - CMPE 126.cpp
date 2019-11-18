#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Complex.h"
#include "ComplexDB.h"
using namespace std;


int main() {

	ifstream instream;
	instream.open("126import.txt");
	if (instream.fail()) {
		cout << "126import.txt file has failed to open" << endl;
		exit(1);
	}

	ofstream outstream;
	outstream.open("126export.txt");
	if (outstream.fail()) {
		cout << "126export.txt file has failed to open" << endl;
		exit(1);
	}


	int length;
	int count = 0;
	int symbol1;
	int symbol2;
	int symbol3;
	string line;
	string sub1;
	string sub2;
	Complex temp;
	ComplexDB stuff;

	while (getline(instream, line)) {

		length = line.length();
		symbol1 = line.find("+");
		symbol2 = line.find("-", 1);
		symbol3 = line.find("i");


		if (length < 4) { // Applicable to single digit complex numbers, i.e. 6 or 7i

			if (symbol3 > 0) {
				temp.set_imaginary(atof(line.c_str()));
				temp.set_real(0);
				stuff.set_data(0, atof(line.c_str()), count);
			}
			else {
				temp.set_real(atof(line.c_str()));
				temp.set_imaginary(0);
				stuff.set_data(atof(line.c_str()), 0, count);
			}
			
		}
		else if (symbol1 > 0) { // Applicable to complex numbers with + in between, i.e. 5 + 6i

			sub1 = line.substr(0, symbol1);
			sub2 = line.substr(symbol1 + 1, 5);

			temp.set_real(atof(sub1.c_str()));
			temp.set_imaginary(atof(sub2.c_str()));

			stuff.set_data(atof(sub1.c_str()), atof(sub2.c_str()), count);
		}
		else if (symbol2 > 0) { // Applicable to complete complex numbers with - inbetween, i.e. 4.4 - 4.5i


			sub1 = line.substr(0, symbol2);
			sub2 = line.substr(symbol2 + 1, 5);

			temp.set_real(atof(sub1.c_str()));
			temp.set_imaginary(atof(sub2.c_str()) * -1);

			stuff.set_data(atof(sub1.c_str()), atof(sub2.c_str()) * -1, count);

		}

		count++;
	}

	stuff.set_size(count);

	int choice = 0;

	while (true) {
		cout << "*********************************************************" << endl;
		cout << "Press 1 to add to the list" << endl;
		cout << "Press 2 to delete from the list" << endl;
		cout << "Press 3 to display current list" << endl;
		cout << "Press 4 to save list to file" << endl;
		cout << "Press 5 to exit" << endl;
		cout << "*********************************************************" << endl;

		cin >> choice;

		if (choice == 1) {
			stuff.add();
		}
		else if (choice == 2) {
			stuff.remove();
		}
		else if (choice == 3) {
			stuff.print_data();
		}
		else if (choice == 4) {
			outstream << stuff;
			cout << "Output saved to file." << endl;
		}
		else if (choice == 5) {
			exit(1);
		}
		else {
			cout << "Please enter a correct menu item" << endl;
		}
		
	}


	instream.close();
	outstream.close();











}

