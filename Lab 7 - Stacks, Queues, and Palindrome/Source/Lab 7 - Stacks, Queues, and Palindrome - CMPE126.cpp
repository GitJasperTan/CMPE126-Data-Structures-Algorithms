#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

	cout << "*****Initiating Palindrome Test*****" << endl << endl;

	//File stream
	ifstream instream;
	instream.open("palindrome.txt");
	if (instream.fail()) {
		cout << "File: palindrome.txt error" << endl;
		exit(1);
	}

	string line;
	int count = 1;
	Queue q1;
	Stack s1;

	//This while loop individually tests each line from the file input
	while (!instream.eof()) {
		getline(instream, line);
		q1.reset();
		s1.reset();
		
		for (int i = 0; i < line.length(); i++) { //Disregards non alphabets, converts them to lower case, and pushes/enqueues them
			if (isalpha(line[i])) {
				q1.enqueue(tolower(line[i]));
				s1.push(tolower(line[i]));
			}
		}

		while (!s1.isEmpty()) {
			if (q1.dequeue() == s1.pop()) {
				//Checks if rear is equal to front i.e. a palindrome
			}
			else {
				break;
			}
		}

		cout << "Line " << count << ": " << line << endl;
		if (s1.isEmpty()) {
			cout << "***PASS***" << endl << endl;
		}
		else {
			cout << "***FAIL***" << endl << endl;
		}
		count++;
	}

	instream.close();
	cout << "File: palindrome.txt closed" << endl;
}