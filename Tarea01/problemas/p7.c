#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pol(int n, double *coeficientes, int M, double *xs){
	int i, j;
	double res = 0;
	for (i = 0; i < M; ++i){
		for (j = 0; j < n+1; ++j)
			res = coeficientes[j]*pow(xs[i], j);
		printf("p(%lf) = %lf\n", xs[i],res);
	}
}

int main(){
	int n = 3, M = 3;
	double *coef, *xs;
	coef = (double *)malloc(sizeof(double)*(n+1));
	xs = (double *)malloc(sizeof(double)*M);
	coef[0] = 0.92;
	coef[1] = 10.2;
	coef[2] = 430.12;
	coef[3] = 1.123123;
	xs[0] = 1;
	xs[1] = 2;
	xs[2] = 3;
	pol(n, coef, M, xs);
	return 0;
}
