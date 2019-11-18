#include "Stack.h"

Stack::Stack() {
	top = -1;
}

void Stack::push(int data) {
	if (!isfull()) {
		arr[++top] = data;
	}
	else {
		cout << "Overflow!" << endl;
	}
}

int Stack::pop() {
	if (!isempty()) {
		return arr[top--];
	}
	else {
		cout << "Underflow!" << endl;
	}
}

int Stack::peep() {
	if (!isempty()) {
		return arr[top];
	}
	else {
		cout << "Underflow" << endl;
	}
}

bool Stack::isfull() {
	return top == size - 1;
}

bool Stack::isempty() {
	return top == -1;
}