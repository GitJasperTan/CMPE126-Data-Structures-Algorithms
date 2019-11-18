#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue {
private:
	char list[100];
	int front;
	int rear;
public:
	Queue();
	bool isEmpty();
	bool isFull();
	void enqueue(char c);
	char dequeue();
	int count();
	void reset();
};

#endif