// Lab 1 - Complex Numbers - CMPE126.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Complex.h"
using namespace std;

int main()
{
	ifstream instream;
	instream.open("complex.txt");
	if (instream.fail()) {
		cout << "Input file failed to open" << endl;
		exit(1);
	}

	ofstream outstream;
	outstream.open("complexout.txt");
	if (outstream.fail()) {
		cout << "Output file failed to open" << endl;
		exit(1);
	}


	Complex temp;
	Complex total;

	int symbol1;
	int symbol2;

	string sub1;
	string sub2;
	string line;


	while (getline(instream, line)) {

		symbol1 = line.find("+");
		symbol2 = line.find("-");

		if (symbol1 == -1 && symbol2 == -1) {
			continue;
		}

		if (symbol1 > 0) {
			sub1 = line.substr(0, symbol1);
			sub2 = line.substr(symbol1+1, line.find("i") - symbol1-1);

			temp.set_real(atoi(sub1.c_str()));
			temp.set_imaginary(atoi(sub2.c_str()));
		}
		else if (symbol2 > 0) {
			sub1 = line.substr(0, symbol2);
			sub2 = line.substr(symbol2 + 1, line.find("i") - symbol2 - 1);

			temp.set_real(atoi(sub1.c_str()));
			temp.set_imaginary(atoi(sub2.c_str()) * -1);
		}

		total = total + temp;

	}

	cout << total;
	outstream << total;
	


}

//cout << temp.return_real() << endl << temp.return_imaginary() << endl << endl;



/*
string line;
string str = "123"
int x = atoi(str.c_str())*;
cout << x;

/*


*/