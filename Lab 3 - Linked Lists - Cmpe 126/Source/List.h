#ifndef LIST_H
#define LIST_H
#include "Stock.h"
//#include <fstream>


struct Node {
	Stock stock;
	Node* next;
};

class List {
private:
	Node* head;
	Node* curr;
	Node* mid1;
	Node* mid2;

public:
	List();
	void fileinput(string f);
	void fileinsert(int s, double c, string n);
	void printout(Node *h1);
	void splitinhalf(Node *h1);
	Node* findmiddle(Node* h1);
	Node* return_head();
	Node* return_mid1();
	Node* return_mid2();
	void print_middle(Node* mid);

};







#endif



