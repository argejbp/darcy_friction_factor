#include <iostream>
#include <cmath>
#include "Friction_Functions.h"
using namespace std;

int main(){
	
	double Re, f, D;
	int g, p, a = 1;
	cout << "Welcome to the interactive program to \ncalculate the Darcy-Weisbach friction factor in pipe flow \n\n";
	cout << "First, the flow regime must be known \n\n";
	
	do
	{
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
		
		cout << "\n\nWould you like to keep doing calculations?";
		cout << "\n[0] No ";
		cout << "\n[1] Yes ";
		cout << "\nYour choice: ";
		cin >> a;
		cout << "\n";
	
			
	} while(a!=0);
	
	cout << "\nGood Bye, see you next time" << endl;
	system("pause");
	return 0;
}

