#include "Queue.h"

Queue::Queue() {
	front = -1;
	rear = -1;
}

bool Queue::isEmpty() {

	if (front == -1 && rear == -1) {
		return true;
	}
	else {
		return false;
	}
}

bool Queue::isFull() {
	return rear == 100-1;
}

void Queue::enqueue(char c) {

	if (isEmpty()) {
		front = 0;
		rear = 0;
	}
	else if (isFull()) {
		cout << "Queue is full" << endl;
		return;
	}
	else {
		rear++;
	}
	list[rear] = c;
}

char Queue::dequeue() {

	char x;

	if (isEmpty()) {
		cout << "Queue is empty" << endl;
	}
	else if (front == rear) {
		x = list[front];
		//list[front] = '\n';
		rear = -1;
		front = -1;
		return x;
	}
	else {
		x = list[front];
		//list[front] = '\n'
		front++;
		return x;
	}
}

int Queue::count() {
	return(rear - front + 1);
}

void Queue::reset() {

	while (!isEmpty()) {
		dequeue();
		//top = -1;
		//rear = -1;
	}
}