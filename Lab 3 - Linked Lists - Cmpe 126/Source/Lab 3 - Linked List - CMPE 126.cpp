#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "List.h"
#include "Stock.h"
using namespace std;




int main() {

	List Portfolio;

	Portfolio.fileinput("Stock.txt");
	Portfolio.printout(Portfolio.return_head());

	Node* mid = new Node;
	mid = Portfolio.findmiddle(Portfolio.return_head());
	Portfolio.print_middle(mid);

	Portfolio.splitinhalf(Portfolio.return_head());

}







