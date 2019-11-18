#include "List.h"

List::List() {
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void List::loadfile(string file) {

	ifstream instream;
	instream.open(file);
	if (instream.fail()) {
		cout << "Input file: " << file << " has failed to open" << endl;
	}

	int temp_shares;
	double temp_cost;
	string temp_name;

	while (instream) {
		
		instream >> temp_name;
		instream >> temp_shares;
		instream >> temp_cost;
		if (!instream) break;

		listinsert(temp_name, temp_shares, temp_cost);

	}
	instream.close();

}

void List::listinsert(string n, int s, double c) {

	Node* temporary = new Node;
	temporary->next = NULL;
	temporary->stock.set_all(n, s, c);

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = temporary;
	}
	else {
		head = temporary;
	}

}

void List::printout(Node *h1) {
	curr = h1;
	while (curr != NULL) {
		curr->stock.print_all();
		curr = curr->next;
	}
	cout << endl;
}

Node* List::return_head() {
	return head;
}

void List::reverse_print(Node* h1) {

	if (h1 != NULL) {
		reverse_print(h1->next);
		h1->stock.print_all();
	}

}