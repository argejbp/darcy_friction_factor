#include <iostream>
using namespace std;

double get_roughtness ();
double darcy_weisbach(const double &Re, const double &D);
double Haaland(const double &Re, const double &D);
double f_laminar(const double &Re);
double friction_factor(const double &Re, const double &D);
double Reynolds(int const &g, const double &D);
void print_values(const double &Re, const double &f);
