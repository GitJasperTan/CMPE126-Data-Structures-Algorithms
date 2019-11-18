#include "Portfolio.h"

Portfolio::Portfolio() {
	head = NULL;
	tail = NULL;
	middle = NULL;
	curr = NULL;
}

void Portfolio::fileinput(string file) {

	ifstream instream;
	instream.open(file);
	if (instream.fail()) {
		cout << "File name: " << file << " has failed to open" << endl;
		exit(1);
	}

	string temp_name;
	int temp_shares;
	double temp_cost;

	while (instream) {
		instream >> temp_name;
		instream >> temp_shares;
		instream >> temp_cost;

		if (!instream) {
			break;
		}

		fileinsert(temp_name, temp_shares, temp_cost);

	}

}

void Portfolio::fileinsert(string n, int s, double c) {

	Node* j = new Node;
	j->next = NULL;
	j->prev = NULL;
	j->stock.set_all(n, s, c);

	if (head != NULL) {
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = j;
		j->prev = curr;
	}
	else {
		head = j;
	}

}

void Portfolio::forward_printout(Node* h1) {
	cout << "***Forward printout***" << endl;
	curr = h1;
	while (curr != NULL) {
		cout << curr->stock.return_name() << " " << curr->stock.return_shares() << " $" << curr->stock.return_cost() << endl;
		curr = curr->next;
	}
	cout << endl << endl;

}

void Portfolio::reverse_printout(Node* h1) {
	cout << "***Reverse printout***" << endl;
	curr = h1;
	while (curr != NULL) {
		cout << curr->stock.return_name() << " " << curr->stock.return_shares() << " $" << curr->stock.return_cost() << endl;
		curr = curr->prev;
	}
	cout << endl << endl;

}

void Portfolio::delete_node(Node* h1) {

	cout << "*****Delete Node*****" << endl;

	Node* del = new Node;
	del->next = NULL;
	del->prev = NULL;
	del = h1;

	if (h1->prev == NULL) {
		head = h1->next;
		head->prev = NULL;
	}
	else if (h1->next == NULL) {
		tail = h1->prev;
		tail->next = NULL;
	}
	else {
		h1->prev->next = h1->next;
		h1->next->prev = h1->prev;
	}

	delete del;
}

void Portfolio::insert_node(Node* h1) {

	cout << "*****Insert Node*****"<< endl;

	Node* temp = new Node;
	temp->next = NULL;
	temp->prev = NULL;

	string n;
	int s;
	double c;

	cout << "You have selected insert node" << endl;
	cout << "Please enter stock name: ";
	cin >> n;
	cout << "Please enter # of shares: ";
	cin >> s;
	cout << "Please enter price per share: ";
	cin >> c;

	temp->stock.set_all(n, s, c);
	
	if (h1->prev == NULL) {
		h1->prev = temp;
		temp->next = h1;
		head = temp;
		//delete h1;
	}
	else if (h1->next == NULL) {
		h1->next = temp;
		temp->prev = h1;
		tail = temp;
		//delete h1;
	}
	else {
		h1->next->prev == temp;
		temp->next = h1->next;
		h1->next = temp;
		temp->prev = h1;
		//delete h1;
	}

	cout << endl << endl;
	
}


Node* Portfolio::get_head() {
	return head;
}

Node* Portfolio::get_middle() {

	Node* fast = new Node;
	Node* slow = new Node;

	fast = head;
	slow = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;

}

Node* Portfolio::get_tail() {
	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	tail = curr;
	return tail;
}

void Portfolio::output() {

	ofstream outstream;
	outstream.open("StockOutput.txt");

	outstream << "************************" << endl;
	outstream << "File saved output: " << endl;

	outstream << "***Forward printout***" << endl;
	curr = head;
	while (curr != NULL) {
		outstream << curr->stock.return_name() << " " << curr->stock.return_shares() << " $" << curr->stock.return_cost() << endl;
		curr = curr->next;
	}
	outstream << endl << endl;


}
