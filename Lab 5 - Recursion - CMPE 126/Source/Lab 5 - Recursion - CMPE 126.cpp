#include <iostream>
#include "Complex.h"
#include "List.h"
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main() {

	//Beginning of part 1//
	cout << "***Part 1 of recursion lab***" << endl << endl;
	ComplexDB list;
	list.loadfile("126import.txt");
	cout << "List of all stored complex numbers: " << endl;
	list.print();

	Complex max;
	max = list.largest_mag(0, list.return_size());
	cout << endl << "The largest magnitude found by recursion is: " << endl;
	max.printout();

	//Beginning of part 2//
	cout << endl << endl << "***Part 2 of recursion lab***" << endl << endl;
	List Portfolio;
	Portfolio.loadfile("stock.txt");
	cout << "Forward print of linked list" << endl;
	Portfolio.printout(Portfolio.return_head());
	cout << endl << "Reverse print of linked list using recursion is: " << endl;
	Portfolio.reverse_print(Portfolio.return_head());
}

