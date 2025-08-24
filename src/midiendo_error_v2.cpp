#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x){
	return sin(x);
}
double fp(double x, double h){
	return (f(x+h)-f(x-h))/(2*h);
}
int main(){
	double x = 1.0, h1 = 0.1;
	cout << setprecision(12)
		<< "Valor real: " << cos(x) << endl
		<< "Diferencia Central: " << fp(x, h1) << endl
		<< "Error absoluto: " << fabs(cos(x)-fp(x, h1)) << endl
		<< "Error relativo porcentual: " << 100*fabs(cos(x)-fp(x, h1))/cos(x) << "%" << endl << endl;

	h1 = 0.01;
	cout << setprecision(12)
		<< "Valor real: " << cos(x) << endl
		<< "Diferencia Central: " << fp(x, h1) << endl
		<< "Error absoluto: " << fabs(cos(x)-fp(x, h1)) << endl
		<< "Error relativo porcentual: " << 100*fabs(cos(x)-fp(x, h1))/cos(x) << "%" << endl << endl;
	return 0;
}