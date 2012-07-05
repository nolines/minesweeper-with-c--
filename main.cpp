/*
 ============================================================================
 Name        : Minesweeper
 Author      : Ahmet Cemre Cevik,Mahmut Yilmaz
 Description : Minesweeper project with C++.
 Made by Visual Studio 
 ============================================================================
 */
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	Date *dt = new Date(14, 05, 2012); //date class called from main and creating object dt.
	cout << "   -----" << *dt << "-----    ";
	
	dt->locatemines();
	dt->checkmines();
	dt->playgame();


	cout << "\nProgram is over: ";
	system("pause");
	return 0;

}
