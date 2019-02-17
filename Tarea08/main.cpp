#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	signed short int a = 109, b = -109;
	int mask=1, *aux, r;
	float f = 4256.78;
	double d = 4256.78;

	cout << sizeof(double) << endl;

	aux = (int*)&a;
	for (int i = 0; i < 16;  ++i){
		r = a&mask;
		if (r)
			cout << 1;
		else
			cout << 0;
		mask = mask << 1;
	}
	cout << endl;

	aux = (int*)&b;
	mask = 1;
	for (int i = 0; i < 16;  ++i){
		r = mask&*aux;
		if (r)
			cout << 1;
		else
			cout << 0;
		mask = mask << 1;
	}
	cout << endl;

	aux = (int*)&f;
	mask = 1;
	for (int i = 0; i <32;  ++i){
		r = *aux&mask;
		if (r)
			cout << 1;
		else
			cout << 0;
		mask = mask << 1;
	}
	cout << endl;

	aux = (int*)&d;
	mask = 1;
	for (int i = 0; i < 64;  ++i){
		r = *aux&mask;
		if (r)
			cout << 1;
		else
			cout << 0;
		mask = mask << 1;
	}
	cout << endl;

}
