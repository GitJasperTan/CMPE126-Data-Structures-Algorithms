#ifndef STACK_H
#define STACK_H
#include <iostream>
#define size 50
using namespace std;

class Stack {
private:
	int arr[size];
	int top;
public:
	Stack();
	void push(int);
	int pop();
	int peep();
	bool isfull();
	bool isempty();

};


#endif
