#include <iostream>
#include <cmath>
#define M 1024
#define N 100
#define vacio -1
#define borrado -2
#define c1 0.5
#define c2 M

using namespace std;

int vec[M];

void limpiar_vec(){
	for (int i = 0; i < M; ++i){
		vec[i] = vacio;
	}
}

int hashaux(int k){
	return k % 2017;
}

void rhash(int k, int i){
	int q;
	q = (hashaux(k) + i*c1 + i*i*c2);
	q %= M;
	if (vec[q] == vacio || vec[q] == borrado){
		vec[q] = k;
	}
	else
		rhash(k, i+1);
}

void fhash(int k){
	rhash(k, 0);
}

int generador_unif(int n){
	int num = 0;
	int fact = 1;
	for (int i = 0; i < n; ++i){
		num += (rand() % 10) *fact;
		fact *= 10;
	}
	return num;
}

int generador_no_unif(int n){
	int num = rand();
	if (num % 2 == 1){
		num = num % 50;
		if (num < 20)
			num += 30;
	}
	else{
		num = num % 50;
		if (num > 20)
			num -= 20;
	}
	return num;
}

int *vec_aleatorio(int* v,int n){
	v = new int[n];
	for (int i = 0; i < n; ++i){
		v[i] = generador_unif(4);
	}
	return v;
}

void imprimir(int *v, int n){
	for(int i = 0; i < n; ++i)
		cout << v[i] << " ";
}

int main(){
//	srand(time (NULL));
	limpiar_vec();
	int *casos;
	casos = vec_aleatorio(casos, N);
	for (int i = 0; i < N; ++i){
		fhash(casos[i]);
	}
	cout << "vector guardado" << endl;
	imprimir(casos, N);
	cout << endl << "tabla" << endl;
	imprimir(vec, M);
	cout << endl;
}