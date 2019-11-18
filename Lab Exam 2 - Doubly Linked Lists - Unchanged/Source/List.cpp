#include "List.h"

List::List() {
	head = NULL;
	tail = NULL;
	curr = NULL;
	del = NULL;
	size = 0;
	split = NULL;
}

void List::file_input(string f) {

	ifstream instream;
	instream.open(f);
	if (instream.fail()) {
		cout << "File: " << f << " has failed to open" << endl;
	}

	int temp_id;
	string temp_fname;
	string temp_lname;
	string temp_phone;
	string temp_email;

	while (instream) {

		instream >> temp_id;
		instream >> temp_fname;
		instream >> temp_lname;
		instream >> temp_phone;
		instream >> temp_email;
		if (!instream) {
			break;
		}

		insert_node(temp_id, temp_fname, temp_lname, temp_phone, temp_email);
	}
}

void List::insert_node(int i, string f, string l, string p, string e) {

	Node* n = new Node;
	n->next = NULL;
	n->prev = NULL;
	n->student.set_all(i, f, l, p, e);

	if (head != NULL) { //if list is not empty
		curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
		n->prev = curr;
	}
	else {
		head = n;
	}
	tail = n;
	size++;
}

void List::print_list(Node* h1) {
	curr = h1;
	while (curr != NULL) {
		curr->student.print_all();
		curr = curr->next;
	}
}

Node* List::return_head() {
	return head;
}

void List::insert_node(Node* h1, int index) {

	curr = head;
	for (int i = 0; i < index; i++) {
		curr = curr->next;
	}

	h1->next = curr->next;
	curr->next->prev = h1;
	h1->prev = curr;
	curr->next = h1;
}

void List::delete_node(int std_id) {

	if (find_node(std_id)) {
		if (del->student.return_id() == head->student.return_id()) { // case for deleting head node
			head = del->next;
			del->next = NULL;
			head->prev = NULL;
		}
		else if (del->student.return_id() == tail->student.return_id()) { // case for deleting tail node
			tail = del->prev;
			del->prev->next = NULL;
			del->prev = NULL;
		}
		else {
			del->next->prev = del->prev;
			del->prev->next = del->next;
			del->prev = NULL;
			del->next = NULL;
		}
		delete del;
	}
	else {
		cout << "Student ID not in database" << endl;
	}
}

bool List::find_node(int std_id) {

	curr = head;
	while (curr != NULL) {
		if (curr->student.return_id() == std_id) {
			del = curr;
			return true;
			break;
		}
		else {
			curr = curr->next;
		}
	}
	return false;
}

void List::split_list(int index) {

	split = head;
	for (int i = 0; i < index; i++) {
		split = split->next;
	}

	curr = head;
	while (curr->next != split) {
		curr = curr->next;
	}
	curr->next = NULL;

}

int List::return_size() {
	return size;
}

void List::sort() {
	Node* index = new Node[size];
	curr = head;

	for (int i = 0; i < size; i++) {
		index[i] = *curr;
		curr = curr->next;
	}
	
	Node* temp = new Node;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (index[j].student.return_id() < index[i].student.return_id()) {
				*temp = index[i];
				index[i] = index[j];
				index[j] = *temp;
			}
		}
	}
	head = &index[0];
	curr = head;

	for (int i = 1; i < 28; i++) {
		curr->next = &index[i];
		curr = curr->next;
	}

	curr->next = NULL;
}

Node* List::return_split() {
	return split;
}