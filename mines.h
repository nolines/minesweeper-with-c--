#ifndef MINES_H
#define MINES_H
#include<iostream>


class mines {
	 
public:
	mines();
	virtual void display()=0; //used virtual for inherit
    virtual void display2()=0;
	void locatemines();
	void checkmines();	
	void playgame();
	
protected:
	int minefield[12][12];
	int mineboard[12][12];
	int number;
	int mine; 
	int x,row,y,column;

};

#endif