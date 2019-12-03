#include "Search.h"

Search::Search() {
	head = NULL;
	tail = NULL;
	temp = NULL;
	length = 0;

}

void Search::load(int num_elem) {
	
	length = num_elem;

	list = new int[num_elem];
	list2 = new int[num_elem];
	for (int i = 0; i < num_elem; i++) {
		list[i] = (1 + rand() % 100);
		linked_insert(list[i]);
		list2[i] = list[i];
	}

}

void Search::linked_insert(int elem) {

	Node* n = new Node;
	n->next = NULL;
	n->prev = NULL;
	n->data = elem;

	if (head != NULL) {
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
}

void Search::linked_print() {
	cout << endl << "List of Elements: " << endl;
	curr = head;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl << endl;
}

void Search::array_print() {

	cout << endl << "List of Elements: " << endl;
	for (int i = 0; i < length; i++) {
		cout << list[i] << endl;
	}
	cout << endl << endl;
}

int Search::sequential_nonrecursive(int x) {

	bool found = false;
	int index;

	for (index = 0; index < length; index++) {
		if (x == list[index]) {
			found = true;
			break;
		}
	}

	if (found == true) {
		return index;
	}
	else if (found == false) {
		return -1;
	}

	}

int Search::sequential_recursive(int l, int x) {

	if (l == -1) {
		return -1;
	}
	if (list[l] == x) {
		return l;
	}
	return sequential_recursive(l - 1, x);
}

int Search::binary_nonrecursive(int x, int first, int last) {
	
	while (first <= last) {
		int middle = (first + last) / 2;
		if (list2[middle] == x) {
			return middle;
		}
		else if (list2[middle] > x) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}
	return -1;
}

void Search::sort() {
	cout << endl << "Sorted List: " << endl;

	int temp;
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (list2[i] > list2[j]) {
				temp = list2[i];
				list2[i] = list2[j];
				list2[j] = temp;
			}

		}
		cout << list2[i] << endl;
	}
	cout << list2[length - 1] << endl << endl;
}

int Search::binary_recursive(int x, int first, int last) {

	int middle = (first + last) / 2;
	if (first > last) {
		return -1;
	}
	if (list2[middle] == x) {
		return middle;
	}
	else if (list2[middle] > x) {
		return binary_recursive(x, first, middle - 1);
	}
	else {
		return binary_recursive(x, middle + 1, last);
	}

}

int Search::linked_nonrecursive(int x) {

	curr = head;

	for (int i = 0; i < length; i++) {
		if (curr->data == x) {
			return i;
		}
		curr = curr->next;
	}
	return -1;

}

int Search::linked_recursive(int x, Node* h) {

	if (h == NULL) {
		return -1;
	}
	if (h->data == x) {
		curr = head;
		int count = 1;
		while (curr != h) {
			curr = curr->next;
			count++;
		}
		return count;
	}
	return linked_recursive(x, h->next);

}

Node* Search::return_head() {
	return head;
}
