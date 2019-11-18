#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

class Stack {
private:
	char list[100];
	int top;
public:
	Stack();
	void push(char c);
	char pop();
	char peep();
	bool isFull();
	bool isEmpty();
	void reset();

};


#endif