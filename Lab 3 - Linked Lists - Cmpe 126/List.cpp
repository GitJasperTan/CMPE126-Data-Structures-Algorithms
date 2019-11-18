#include "List.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

List::List() {
	head = NULL;
	curr = NULL;
	mid1 = NULL;
	mid2 = NULL;
}

void List::fileinput(string f) {

	ifstream instream;
	instream.open(f);
	if (instream.fail()) {
		cout << "Input file: " << f << " has failed to open" << endl;
		exit(1);
	}

	int temp_shares;
	double temp_cost;
	string temp_name;

	while (instream) {

		instream >> temp_name;
		instream >> temp_shares;
		instream >> temp_cost;

		if (!instream) break;

		fileinsert(temp_shares, temp_cost, temp_name);
	}

}

void List::fileinsert(int s, double c, string n) {

	Node* j = new Node;
	j->next = NULL;
	j->stock.set_shares(s);
	j->stock.set_cost(c);
	j->stock.set_name(n);

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = j;
	}
	else {
		head = j;
	}

}

void List::printout(Node *h1) {

	curr = h1;
	while (curr != NULL) {
		cout << curr->stock.return_name() << " " << curr->stock.return_shares() << " $" << curr->stock.return_cost() << endl;
		curr = curr->next;
	}
	cout << endl << endl;

}

void List::splitinhalf(Node* h1) {

	Node* middle = findmiddle(h1);
	mid1 = h1;
	mid2 = middle;

	while (mid1->next != middle) {
		mid1 = mid1->next;
	}
	mid1->next = NULL;
	mid1 = h1;


	cout << "First half is: " << endl;
	printout(mid1);
	cout << "Second half is: " << endl;
	printout(mid2);

}



Node* List::findmiddle(Node* h1) {

	Node* fast_h = new Node;
	Node* slow_h = new Node;

	fast_h = h1;
	slow_h = h1;

	while (fast_h != NULL && fast_h->next != NULL) {
		slow_h = slow_h->next;
		fast_h = fast_h->next->next;
	}

	return slow_h;

}

Node* List::return_head() {
	return head;
}

Node* List::return_mid1() {
	return mid1;
}

Node* List::return_mid2() {
	return mid2;
}

void List::print_middle(Node* mid) {
	cout << "***Middle of the list is***" << endl;
	cout << mid->stock.return_name() << " " << mid->stock.return_shares() << " $" << mid->stock.return_cost() << endl;
	cout << "***************************" << endl << endl;
}