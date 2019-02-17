#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int **init_mat(int n){
	int **mat = (int **)malloc(sizeof(int *)*n);
	mat[0] = (int *)malloc(sizeof(int)*n*n);
	for (int i = 1; i < n; ++i)
		mat[i] = mat[i-1] + n;
	return mat;
}
void liberar_mat(int **mat){
	free(mat[0]);
	free(mat);
}

void llenar_mat(int **mat, int n){
	for (int i = 0; i < n*n; ++i)
		mat[0][i] = rand();
}

double norma_frobenius(int **mat, int n){
	double norma = 0;				//+1 operación, por norma = 0
	for (int i = 0; i < n*n; ++i)			//+1 por i = 0, +(n*n+1) por checar i < n*n, +n*n por ++i
		norma = norma + pow(mat[0][i], 2);	//+n*n por igualar, +n*n por sumar, +n*n por pow, +2n*n por mat[0][1]
	return sqrt(norma);				//+n*n por igualar, +n*n por sqrt
}

int main(int narg, char *args[]){
	srand(time(NULL));
	int n = 10;
	int **mat = init_mat(n);
	llenar_mat(mat, n);
	cout << "La norma es: " << norma_frobenius(mat, n) << endl;	//T(n) = 3 + 9*n²
	liberar_mat(mat);
	return 0;
}

//La funcion norma_frobenius es la que hace los cáluclos pedidos y esta tarde c*3 + 9*n² segundos, donde c es el tiempo que tarda la maquina en hacer una opercacion

