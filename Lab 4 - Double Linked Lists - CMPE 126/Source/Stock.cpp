#include "Stock.h"

Stock::Stock() {
	name = "";
	shares = 0;
	cost = 0;
}

void Stock::set_all(string n, int s, double c) {
	name = n;
	shares = s;
	cost = c;
}

void Stock::set_name(string n) {
	name = n;
}

void Stock::set_shares(int s) {
	shares = s;
}

void Stock::set_cost(double c) {
	cost = c;
}

string Stock::return_name() {
	return name;
}

int Stock::return_shares() {
	return shares;
}

double Stock::return_cost() {
	return cost;
}