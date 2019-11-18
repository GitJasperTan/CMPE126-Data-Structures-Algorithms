#include "List.h"
#include "Student.h"
#include <iostream>
using namespace std;

int main() {

	// file input
	cout << "*********** File Input ***********" << endl;
	List Portfolio;
	Portfolio.file_input("studentsLab2.txt");
	Portfolio.print_list(Portfolio.return_head());
	cout << endl << endl;


	// insert
	cout << "*********** Node Insert ***********" << endl;
	Node* temp = new Node;
	temp->student.set_all(999919999, "Jasper", "Tan", "408-999-9999", "jasper.tan@sjsu.edu");
	Portfolio.insert_node(temp, 5);
	Portfolio.print_list(Portfolio.return_head());
	cout << endl << endl;

	// delete
	cout << "*********** Node Delete ***********" << endl;
	cout << "Deleting: 999919999" << endl << endl;
	Portfolio.delete_node(999919999);
	Portfolio.print_list(Portfolio.return_head());
	cout << endl;
	cout << "Deleting: 112112111" << endl;
	Portfolio.delete_node(112112111);
	cout << endl << endl;

	// sort
	cout << "*********** List Sort ***********" << endl;
	Portfolio.sort();
	Portfolio.print_list(Portfolio.return_head());
	cout << endl << endl;

	// split
	
	cout << "*********** List Split ***********" << endl;
	Portfolio.split_list(5);
	cout << "Sub List 1: " << endl;
	Portfolio.print_list(Portfolio.return_head());
	cout << endl << "Sub List 2: " << endl;
	Portfolio.print_list(Portfolio.return_split());
	



}