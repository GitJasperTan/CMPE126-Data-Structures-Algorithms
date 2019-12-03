#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
using namespace std;

struct Node {
	Node* next;
	Node* prev;
	int data;
};

class Search {
private:
	Node* head;
	Node* tail;
	Node* temp;
	Node* curr;
	int* list;
	int* list2;
	int length;
public:
	Search();
	void load(int num_elem);
	void linked_insert(int elem);
	void linked_print();
	void array_print();
	int sequential_nonrecursive(int x);
	int sequential_recursive(int l, int x);
	int binary_nonrecursive(int x, int first, int last);
	int binary_recursive(int x, int first, int last);
	int linked_nonrecursive(int x);
	int linked_recursive(int x, Node* h);
	void sort();
	Node* return_head();
};




#endif



