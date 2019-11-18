#ifndef PORTFOLIO_H
#define PORTFOLIO_H
#include "Stock.h"
#include <iostream>
using namespace std;

struct Node {
	Stock stock;
	Node* next;
	Node* prev;
};


class Portfolio {
private:
	Node* head;
	Node* middle;
	Node* tail;
	Node* curr;

public:
	Portfolio();
	void fileinput(string file);
	void fileinsert(string n, int s, double c);
	void forward_printout(Node* h1);
	void reverse_printout(Node* h1);
	void delete_node(Node* h1);
	void insert_node(Node* h1);
	void output();

	Node* get_head();
	Node* get_middle();
	Node* get_tail();
};


#endif

