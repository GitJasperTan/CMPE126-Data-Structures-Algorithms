#include "Stock.h"
#include <iostream>
using namespace std;

Stock::Stock() {
	cost = 0;
	shares = 0;
	name = "";
}
void Stock::set_cost(double c) {
	cost = c;
}
void Stock::set_shares(int s) {
	shares = s;
}
void Stock::set_name(string s) {
	name = s;
}
double Stock::return_cost() {
	return cost;
}
int Stock::return_shares() {
	return shares;
}
string Stock::return_name() {
	return name;
}