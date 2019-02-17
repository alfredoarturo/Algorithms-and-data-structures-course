#include <iostream>

using namespace std;

int main(int narg, char *args[]){
	unsigned int ui, mask, r, *aux;
	float f;
	ui = 342198456;
	f = 3.1415926535;
	mask = 1;
	for (int i = 0; i < 16; ++i){
		r = mask&ui;
		if (r)
			cout << 1;
		else
			cout << 0;
		mask = mask << 1;
	}
	cout << endl;

	aux = (unsigned int *) &f;
	mask = 1;

	for (int i = 0; i < 32; ++i){
		r = mask&*aux;
		if (r)
			cout << 1;
		else
			cout << 0;
		mask = mask << 1;
	}
	cout << endl;

	return 0;
}
