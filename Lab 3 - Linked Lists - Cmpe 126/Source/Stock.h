#ifndef STOCK_H
#define STOCK_H
#include <iostream>
using namespace std;

class Stock {
private:
	double cost;
	int shares;
	string name;

public:

	Stock();

	void set_cost(double c);
	void set_shares(int s);
	void set_name(string s);
	double return_cost();
	int return_shares();
	string return_name();
};


#endif

