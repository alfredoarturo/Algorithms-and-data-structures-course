#include <iostream>

using namespace std;

void withdraw(int X, int *monedas, int *usadas, int N){
	if (X == 0)
		return;
	int i = 0;
	while (X < monedas[i]){
		++i;
		if (i >= N){
			cout << "error" << endl;
			return;
		}
	}
	usadas[i] = 1;
	withdraw(X-monedas[i], monedas, usadas, N);
}

int main(){
	int Ncasos, N, *monedas, *usadas, suma, mon;

	cin >> Ncasos;
	for (int i = 0; i < Ncasos; ++i){
		suma = 0;
		mon = 0;
		cin >> N;
		monedas = new int[N];
		usadas = new int[N];
		for (int j = N-1; j >= 0; --j){
			cin >> monedas[j];
			usadas[j] = 0;
			suma += monedas[j];
		}
		withdraw(suma, monedas, usadas, N);
		for (int k = 0; k < N; ++k)
			mon +=usadas[k];
		cout << mon << endl;
		delete [] usadas;
		delete [] monedas;
	}


}