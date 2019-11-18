#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Portfolio.h"
#include "Stock.h"

int main() {

	Portfolio portfolio;
	portfolio.fileinput("stock.txt");

	portfolio.forward_printout(portfolio.get_head());
	portfolio.reverse_printout(portfolio.get_tail());

	//portfolio.insert_node(portfolio.get_head());
	//portfolio.insert_node(portfolio.get_tail());
	//portfolio.insert_node(portfolio.get_middle());

	//portfolio.forward_printout(portfolio.get_head());

	portfolio.delete_node(portfolio.get_middle());
	portfolio.forward_printout(portfolio.get_head());
	portfolio.output();

}