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

int *init_vec(int n){
	int *vec = (int *)malloc(sizeof(int)*n);
	return vec;
}

void liberar_vec(int *vec){
	free(vec);
}

void llenar_vec(int *vec, int n){
	for (int i = 0; i < n; ++i)
		vec[i] = rand();
}

void llenar_mat(int **mat, int n){
        for (int i = 0; i < n*n; ++i)
                mat[0][i] = rand();
}

int mult_aux(int **mat, int *vec, int k, int n){
	int mult = 0;					//+1 por igualar
	for (int i = 0; i < n; ++i)			//+1 por igualar, +(n+1) por checar i < n, +n por ++i
		mult += mat[k][i]*vec[i];		//+n por igular, +n por sumar, +n por multiplicar, +n por vec[i], +2n por mat[k][i]
	return mult;					//+1 por regresar
}							//Esto genera a f(n) = 4 + 8n

int *mult_por_vec(int **mat, int *vec, int n){
	int *vec_res = init_vec(n);			//se ignora, por lo que se dijo de la tarea
	for (int i = 0; i < n; ++i)			//+1 por i = 0, +(n+1) por checar i < n, +n por ++i
		vec_res[i]=mult_aux(mat, vec, i, n);	//+n por vec_res[i], +n por igualar, +n*f(n) por llamar a mault_aux
	return vec_res;					//+1 por regresar
}							//Esto enera a T(n) = 3 + 8*n + 8*n²

int main(int narg, char *args[]){
	srand(time(NULL));
	int n = 1000;
	int **mat = init_mat(n);
	int *vec = init_vec(n);
	int *vec_mult;
	llenar_vec(vec, n);
	llenar_mat(mat, n);
	vec_mult = mult_por_vec(mat, vec, n);
	for (int i = 0; i < n; ++i)
		cout << vec_mult[i] << " ";
	cout << endl;
	liberar_mat(mat);
	liberar_vec(vec);
	liberar_vec(vec_mult);
	return 0;
}
// Tenemos que T(n) = 3 + 8n + 8n², así que dado se va a tardar c*T(n) segundos, si c es el tiempo que tarda la computadora en hacer una operación.
