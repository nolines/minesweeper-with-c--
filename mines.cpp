#include <iostream>
#include <iomanip>

using namespace std;

#include <time.h>
#include "mines.h"

mines::mines() {
}

void mines::display() {
	int i, j;
	cout << "\n";
	for (i = 1; i < 11; i++) {
		for (j = 1; j < 11; j++) {
			if (mineboard[i][j] == 0)
				mineboard[i][j] == ' ';
			cout << setw(2)<<mineboard[i][j];
		}
		cout << "\n";
	}
}
void mines::display2() {
	for (x = 1; x < 11; x++) {
		for (y = 1; y < 11; y++)
			if (minefield[x][y] == 'm')
				cout << "m";
			else {
				cout << minefield[x][y];
			}
		cout << "\n";
	}
}
void mines::locatemines() {

	for (x = 0; x < 11; x++)
		for (y = 0; y < 11; y++)
			mineboard[x][y] = 0;
	srand((unsigned) time(NULL));

	do {
		cout << "\n WELCOME TO THE MINESWEEPER \n" << endl;
		cout << "Made by A.Cemre Cevik and Mahmut Yilmaz\n" << endl;

		do {
			mine = -1;
			cout << "How many mines on the board? <max:100, min:0>: " << endl;
			cin >> mine;
			if (mine < 0 || mine > 100)
				cout << "Wrong number!" << endl;
		} while (mine < 0 || mine > 100); //initialize

		for (x = 0; x < 11; x++)
			for (y = 0; y < 11; y++)
				minefield[x][y] = 0;

		for (number = 0; number < mine; number++) {
			do {
				x = rand() % 10 + 1;
				y = rand() % 10 + 1;
			} while (minefield[x][y] == 'm'); //set mines on array
			minefield[x][y] = 'm';
		}
	} while (0);
}

void mines::checkmines() {
	for (x = 0; x < 11; x++) {
		for (y = 0; y < 11; y++)
			if (minefield[x][y] == 'm') {
				for (row = x - 1; row <= x + 1; row++)
					if (x != -1)
						if (x != 11) {
							for (column = y - 1; column <= y + 1; column++)
								if (y != -1)
									if (y != 11) {
										if (minefield[row][column] != 'm')
											++minefield[row][column];
									}
						}
			}
	}
	
	for (x = 1; x < 11; x++) {
		for (y = 1; y < 11; y++)
			if (minefield[x][y] == 'm')
				cout << setw(2)<<"|"<<"m"<<"|";
			else
				cout <<setw(2)<<"|"<<minefield[x][y]<<"|";
		cout << "\n";
	}
}

void mines::playgame() {
	int i, k, l;
	cout << "Lutfen x ve y koordinatlarini giriniz\n";
	while (1) {
		cout << "x : ";
		cin >> k;
		cout << "y : ";
		cin >> l;
		if (minefield[k][l] == 'm') {
			cout << "Program is over you hit the mine !\n" << endl;
			mines::display2();
			break;
		} else {
			i = minefield[k][l];
			mineboard[k][l] = i;
			mines::display();
			cout << "Please enter new coordinates.\n";
		}
	}
}

