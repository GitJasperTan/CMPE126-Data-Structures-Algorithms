#include <iostream>
#include "Search.h"
#include <cstdlib>
using namespace std;

//Bug Notice


int main() {

	int i = 0;
	int element;
	int num_elements;
	bool elements_initialize = false;
	Search search;

	do {
		cout << endl << "***************************************************" << endl;
		cout << "Please select a menu option" << endl;
		cout << "1. Arrays: Sequential Search without recursion" << endl;
		cout << "2. Arrays: Sequential Search with recursion" << endl;
		cout << "3. Ordered Arrays: Binary Search without recursion" << endl;
		cout << "4. Ordered Arrays: Binary Search with recursion" << endl;
		cout << "5. Linked List: Search without recursion" << endl;
		cout << "6. Linked List: Search with recursion" << endl;
		cout << "7. Exit" << endl;
		cout << "***************************************************" << endl << endl;
		
		cout << "Menu Selection: ";
		cin >> i;

		if (i == 7) {
			cout << "Ending Program" << endl;
			exit(1);
		}
		else if (i < 1 || i > 7) {
			cout << endl << "Please enter a valid menu option" << endl << endl;
			continue;
		}

		if (elements_initialize == false) {
			cout << "Specify the number of elements to be searched: ";
			cin >> num_elements;
			search.load(num_elements);
			
			elements_initialize = true;
		}
		search.linked_print();


		cout << "Specify the element to be searched for: ";
		cin >> element;

		if (i == 1) { //Sequential Search NO recursion
			if (search.sequential_nonrecursive(element) != -1) {
				cout << "Element found at index: " << search.sequential_nonrecursive(element) << endl;
			}
			else {
				cout << "Element not found" << endl;
			}
		}
		else if (i == 2) { //Sequential Search w/ recursion
			if (search.sequential_recursive(num_elements, element) != -1) {
				cout << "Element found at index: " << search.sequential_nonrecursive(element) << endl;
			}
			else {
				cout << "Element not found" << endl;
			}

		}
		else if (i == 3) {// Binary Search NO recursion
			search.sort();
			
			if (search.binary_nonrecursive(element, 0, num_elements) != -1) {
				cout << "Element found at index: " << search.binary_nonrecursive(element, 0, num_elements) << endl;
			}
			else {
				cout << "Element not found" << endl;
			}

		}
		else if (i == 4) {// Binary Search w/ recursion
			search.sort();

			if (search.binary_recursive(element, 0, num_elements) != -1) {
				cout << "Element found at index: " << search.binary_recursive(element, 0, num_elements) << endl;
			}
			else {
				cout << "Element not found" << endl;
			}
		}
		else if (i == 5) {

			if (search.linked_nonrecursive(element) != -1) {
				cout << "Element found at node: " << search.linked_nonrecursive(element) << endl;
			}
			else {
				cout << "Element not found" << endl;
			}

		}
		else if (i == 6) {

			if (search.linked_recursive(element, search.return_head()) != -1) {
				cout << "Element found at node: " << search.linked_recursive(element, search.return_head());
			}
			else {
				cout << "Element not found" << endl;
			}

		}




	} while (i != 7);

}

