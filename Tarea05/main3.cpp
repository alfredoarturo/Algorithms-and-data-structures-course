#include <iostream>
#include <cstdlib>

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

int mult_aux(int **mat1, int **mat2, int r, int c, int n){
        int mult = 0;							//+1 por igualar
        for (int i = 0; i < n; ++i)					//+1 por igualar, +(n+1) por i < n y +n por ++i
                mult += mat1[r][i]*mat2[i][c];				//+n por igualr, +n por sumar, +2n por mat1[r][i], +2n por mat[i][c] y +n por multiplicar
        return mult;							//+1 por regresar el valor
}									//Esto genera f(n)=4 + 9n

int **mult_mat(int **mat1, int **mat2, int n){
        int **mat_res = init_mat(n);					//Esto no se considera por las instrucciones
        for (int i = 0; i < n; ++i){					//+1 por igualar, +(n+1) por i < n, +n por ++i
		for (int j = 0; j < n; ++j)				//+n por igualar, +n*(n+1) por j < n, +n² por ++j
                	mat_res[i][j] = mult_aux(mat1, mat2, i, j, n);	//+2n² por mat_res[i][j], +n² por igualar, +n²*f(n) por llamr mult_aux
	}
        return mat_res;							//+1 por regresar valor
}									//T(n) = 3 + 4n + 10n² + 9n³


int main(int narg, char *args[]){
	srand(time(NULL));
	int n = 100;
	int **mat1 = init_mat(n);
	int **mat2 = init_mat(n);
	int **mat_final = init_mat(n);
	llenar_mat(mat1, n);
	llenar_mat(mat2, n);
	mat_final = mult_mat(mat1, mat2, n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			cout << mat_final[i][j] << "	";
		cout << endl;
	}
	liberar_mat(mat1);
	liberar_mat(mat2);
	liberar_mat(mat_final);
	return 0;
}
//por lo tanto T(n) = 3 + 4n + 10n² + 9n³, donde la computadora va a tardar c*T(n), donde la computadora tarde c segundos en hacer una operacion.
