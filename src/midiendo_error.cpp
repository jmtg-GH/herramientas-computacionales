#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x){
	return sin(x);
}
double fp(double x, double h){
	return (f(x+h)-f(x))/(h);
}
int main(){
	double x = 1.0, h = 0.01;
	cout << setprecision(12)
		<< "Valor real: " << cos(x) << endl
		<< "Diferencia Adelante: " << fp(x, h) << endl
		<< "Error absoluto: " << fabs(cos(x)-fp(x, h)) << endl
		<< "Error relativo porcentual: " << 100*fabs(cos(x)-fp(x, h))/cos(x) << "%" << endl;
	return 0;
}
