#ifndef LIST_H
#define LIST_H
#include "Stock.h"


struct Node {
	Stock stock;
	Node* next;
};


class List {
private:
	Node* head;
	Node* curr;
	Node* temp;
public:
	List();
	void loadfile(string file);
	void listinsert(string n, int s, double c);
	Node* return_head();
	void printout(Node* h1);
	void reverse_print(Node* h1);

};











#endif	
