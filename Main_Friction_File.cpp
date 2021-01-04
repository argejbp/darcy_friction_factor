//Written by Argenis Bonilla, updated in 01/2021
//aj.bonilla.13@gmail.com

#include <iostream>
#include <cmath>
#include "Friction_Functions.h"
using namespace std;

int main(){
	
	double Re, f, D;
	int g, p;
	cout << "Welcome to the interactive program to \ncalculate the Darcy-Weisbach friction factor in pipe flow \n\n";
	cout << "First, the flow regime must be known \n\n";
	cout << "Enter 1 or 2 according the known variable: \n\n";
	cout << "Volumetric Flowrate [1]" << endl;
	cout << "Fluid velocity [2]" << endl;
	cout << "Your choice: ";
	cin >> g;
	
	cout <<"\nEnter the pipe inner diameter in [mm]: ";
	cin >> D;
	Re = Reynolds(g, D);
	f = friction_factor(Re, D);
	print_values(Re, f);

	cout << "\n\nGood Bye, see you next time" << endl;
	system("pause");
	return 0;
}

