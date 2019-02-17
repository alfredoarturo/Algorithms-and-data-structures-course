#include <iostream>

using namespace std;

int main(int narg, char * args[]){
	if (narg < 2){
		cout << "Error, introduce las 4 palabras" << endl;
		return 1;
	}
	unsigned int a = 0;
	char *y;
	y = (char *)(&a);

	for (int i = 0; i < 4; ++i){
		*(y+i) = args[1][i];
	}


	cout << a << endl;

	return 0;
}
