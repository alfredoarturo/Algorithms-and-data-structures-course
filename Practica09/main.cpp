#include <iostream>
#include <cstdlib>

using namespace std;

void limpiar(int *vec, int N){
	for (int i = 0; i < N; ++i)
		vec[i] = 0;
}

int no_acomodados(int *estatus, int N){
	int cont;
	for (int i = 0; i < N; ++i){
		if (estatus[i] == 1)
			cont ++;
	}
	return cont;
}

int min(int *aux, int N){
	int imin, m;

void resolver(int *dias, int *multa, int N){
	int *estatus = new int[N];
	int *aux = new int[N];
	int suma_multas;
	int indice;
	limpiar(estatus, N);
	while (N > 0){
		suma_multas = 0;
		for (int i = 0; i < N; ++i){
			if (estatus[i] == 1)
				suma_multas += multa[i];
		}
		for (int i = 0; i < N; ++i)
			aux[i] = dias[i]*(suma_multas-multa[i]);
		indice = min(aux);
		estatus[indice] = -1;
		cout << indice << " ";
		--N;
	}
}

int main(){
	int casos, N, *dias, *multa, i;
	cin >> casos;
	while (casos > 0){
		cin >> N;
		dias = new int[N];
		multa = new int[N];
		for (i = 0; i < N; ++i){
			cin >> dias[i];
			cin >> multa[i];
		}

		

		delete [] dias;
		delete [] multa;
		--casos;
	}

}
