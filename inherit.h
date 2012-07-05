#ifndef INHERIT_H
#define INHERIT_H
#include "mines.h"
#include <iostream>
using namespace std;

class Date: public mines // inheritance

{
	int mo, da, yr;
public:

	Date(int m, int d, int y) {
		mo = m;
		da = d;
		yr = y;
	}
	virtual void display() // polymorphism
	{
		int i, j;
		char c = ' ';
		cout << "\n";
		for (i = 1; i < 11; i++) {
			for (j = 1; j < 11; j++) {
				if (mineboard[i][j] == 0)
					mineboard[i][j] == c;
				cout <<mineboard[i][j];
			}
			cout << "\n";
		}
	}
	virtual void display2() { // polymorphism
		for (x = 1; x < 11; x++) {
			for (y = 1; y < 11; y++)
				if (minefield[x][y] == 'm')
					cout << "m";
				else {
					cout <<minefield[x][y];
				}
			cout << "\n";
		}
	}

	friend ostream& operator<<(ostream& os, const Date& dt); // used const and operator overload
};

ostream& operator<<(ostream& os, const Date& dt) {
	os << dt.mo << '/' << dt.da << '/' << dt.yr;
	return os;
}

#endif

