#include <iostream>

using namespace std;

long int Sumavector(int *vec, int tam){			//suma recirsiva de elementos de un vector
	if (tam == 1)								//condicion de paro
		return vec[0];
	return vec[0] + Sumavector(vec+1, tam-1);	//regresa el primer elemento y manda llamar a la función con problema menor
}

int *vecAleatorio(int tam){						//crea un vector aleatorio
	int *vec = new int[tam];
	for (int i = 0; i < tam; ++i)
		vec[i] = rand() % 100;
	return vec;
}

void destruyeVec(int *vec){
	delete []vec;
}

int main(){
	srand(time(NULL));
	int *v = vecAleatorio(1000);
	cout << Sumavector(v, 1000) << endl;
	destruyeVec(v);
}