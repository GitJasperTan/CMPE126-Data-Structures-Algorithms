#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Stock {
private:
	string name;
	int shares;
	double cost;


public:

	Stock();
	void set_name(string n);
	void set_shares(int s);
	void set_cost(double c);
	void set_all(string n, int s, double c);
	string return_name();
	int return_shares();
	double return_cost();


};



#endif

