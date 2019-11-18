#ifndef STACKSTL_H
#define STACKSTL_H
#include <stack>
#include <iostream>
using namespace std;

class StackSTL {
private:
	int i;
	int j;
	stack<int>s2;
	char ch;
	char infix[100], postfix[100];
public:
	StackSTL();
	StackSTL(char sample[]);
	void conversion();
	int find_precedence(char ch);
	void printout();

};

#endif
