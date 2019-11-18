#ifndef COMPLEXDB_H
#define COMPLEXDB_H

class ComplexDB {
private:
	int size;
	int max_size;
	Complex* data;


public: 
	ComplexDB();
	ComplexDB(int max);
	~ComplexDB();


	void set_size(int s);
	void set_max_size(int s);
	void set_data(double real, double imaginary, int count);
	void print_data();
	void add();
	void sort();
	void remove();
	friend ostream& operator <<(ostream& out, ComplexDB& o1);

};



#endif