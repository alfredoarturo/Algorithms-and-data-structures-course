#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int narg, char * args[]){

	double x,b;

	if (narg < 2){
		cout << "Erros, introduce el numero" << endl;
		return 1;
	}

	x = atof(args[1]);

	b = x;

	while( fabs(b - x/b) > 1e-5){
		b = 0.5*(x/b + b);
		cout << b << endl;
	}

	cout << "la raiz de " << x <<  " es " << b << endl;

	return 0;
}
