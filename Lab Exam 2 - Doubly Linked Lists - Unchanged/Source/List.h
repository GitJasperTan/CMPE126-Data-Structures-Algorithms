#ifndef LIST_H
#define LIST_H
#include "Student.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

struct Node {
	Student student;
	Node* next;
	Node* prev;
};

class List {
private:
	Node* head;
	Node* tail;
	Node* curr;
	Node* del;
	int size;
	Node* split;
public:
	List();
	void file_input(string f);
	void insert_node(int i, string f, string l, string p, string e);
	void print_list(Node* h1);
	Node* return_head();
	void insert_node(Node* h1, int index);
	void delete_node(int std_id);
	bool find_node(int std_id);
	void split_list(int index);
	int return_size();
	void sort();
	Node* return_split();


};


#endif


