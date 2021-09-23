#include <iostream>
#include <cmath>
#include "Friction_Functions.h"
using namespace std;

/*Se crea una funcion para el calculo del factor de friccion de Darcy-Weisbach en tuberias
donde a es el numero de Reinolds, y b es el diametro de la tuberia*/

double get_roughtness (){
	
	double e;
	int k;
	cout <<"\n\nEnter the digit corresponding the pipe's material': \n\n";
	//Se introduce la rugosidad absoluta del material en mm segun la eleccion del usuario
	cout <<"Glass, plastic [1] \nConcrete [2] \nWood stave [3] \nRubber [4] \nCopper of brass tubing [5] \nCast iron [6] \nGalvanized iron [7] \nStainless iron [8] \nCommercial steel [9] \nWrought iron [0] \nYour choice: ";
	while (!(cin>>k)|| k!=1 && k!=2 && k!=3 && k!=4 && k!=5 && k!=6 && k!=7 && k!=8 && k!=9 && k!=0){
	
		cout<<"Wrong entry \nTry again \n\n";
		cin.clear();
		cin.ignore(100, '\n');
	}
		switch (k) {
			case 0:
				e=0.046;
				break;
			case 1:
				e=0;
				break;
			case 2:
				e=4.9;
				break;
			case 3:
				e=0.5;
				break;
			case 4:
				e=0.01;
				break;
			case 5:
				e=0.0015;
				break;
			case 6:
				e=0.26;
				break;
			case 7:
				e=0.15;
				break;
			case 8:
				e=0.002;
				break;
			case 9:
				e=0.045;
				break;
		}
		
	return e;
}

double darcy_weisbach(const double &Re, const double &D){
	double d, e, f = 0.0001, m, fh;
	
	/*Se calcula el factor de friccion segun la 
	ecuacion de Colebrook de manera iterativa*/

	e = get_roughtness();
		
	do {
		d= 1/sqrt(f);
		m= -2*log10((e/D)/3.7+2.51/(sqrt(f)*Re));
		f+=0.00001;
	} while(d>m);

	return f;
}

double Haaland(const double &Re, const double &D) {
	double e, fh;

	/* Se calcula del factor de friccion
	segun la ecuacion de Haaland*/

	e = get_roughtness();	
	fh = pow((1/(-1.8*log10(pow((e/D)/3.7, 1.11) + 6.9/Re))), 2.0);
	return fh;
}

void print_values(const double &Re, const double &f) {
	cout<<"\n\nReynolds Number is: "<< Re <<endl;
	cout<<"Friction Factor is: "<< f <<endl;
}


double f_laminar(const double &Re){
	double f;
	f=64 / Re;
	return f;
}

double friction_factor(const double &Re, const double &D){
	double f;
	if (Re<=2000){
			cout <<"\nLaminar Flow \n\n";
			f = f_laminar(Re);
	}
		
	else if (Re>2000 && Re<10000){
		cout<<"Transision Flow \n";
		f = darcy_weisbach(Re, D);
	}
		
	else if (Re>=10000){
		cout<<"Fully Turbulent Flow \n";
		f = darcy_weisbach(Re, D);
	}

	return f;
}

double Reynolds(int const &g, const double &D){
	double V, Q, m;
	double v, rho;
	double Re;
	
	switch (g){
		
		case 1:
			double Q;
			cout << "Enter the Volumetric Flowrate in [m^3/s]: ";
			cin >> Q;
			cout<< "Enter the Kinematic Viscocity of the fluid in [m^2/s]: ";
			cin >> v;
			Re = (4*Q/(4*atan(1)*(D/1000)))/v;			//Reynolds Number is calculated here 
		break;
		
		case 2:
			double V ;
			cout <<"Enter the Fluid Velocity in [m/s]: ";
			cin >> V;
			cout << "Enter the Kinematic Viscocity of the fluid in [m^2/s]: ";
			cin >> v;
			Re = (V*D/1000)/v;						//Reynolds Number is calculated here  
		break;
		
	}
	
	return Re;
}
