#include "Stack.h"

Stack::Stack() {
	top = -1;
}

bool Stack::isFull() {
	return top == 100-1;
}

bool Stack::isEmpty() {
	return top == -1;
}

void Stack::push(char data) {
	if (!isFull()) {
		list[++top] = data;
	}
	else {
		cout << "Stack overflow" << endl;
		return;
	}
}

char Stack::pop() {
	if (!isEmpty()) {
		return list[top--];
	}
	else {
		cout << "Stack underflow" << endl;
	}
}

char Stack::peep() {

	if (!isEmpty()) {
		return list[top];
	}
	else {
		cout << "Stack underflow" << endl;
	}

}

void Stack::reset() {

	while (!isEmpty()) {
		pop();
	}
}
