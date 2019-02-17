#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 1000000
#define D 100
#define C 100000

using namespace std;

long int  search ( long int a[], long int v, long int n ){
        for ( long int i=0; i< n; i++ )
                if( v == a[i]) return i;///AQUI QUITA EL RETURN
        return -1;///AQUI IGUAL
}

long int bin_search ( long int a[], long int v, long int l, long int r ){
        while (r >= l){
                long int m = (l+r)/2;
                if (v == a[m]) return m;///AQUI
                if (v < a[m]) r=m-1; else l=m+1;
        }
        return -1;///AQUI
}

long int *arg(long int n, long int d){
	long int *vec = (long int *)malloc(sizeof(long int)*n);
	long int aux, sumar, i;
	while(aux < n){
		i = rand() % 2;
		if (i == 0){
			vec[aux] = sumar + d;
			aux ++;
		}
		sumar ++;
	}
	return vec;
}

void liberar(long int *vec){
	free(vec);
}

void checar(long int *vec, long int *checar1, int n, int nchecar){
	for (long int i = 0; i < nchecar; ++i)
		search(vec, checar1[i], n);
}

void checar_bin(long int *vec, long int *checar1, int n, int nchecar){
	for (long int i = 0; i < nchecar; ++i)
		bin_search(vec, checar1[i], 0, n-1);
}

int main(){
	srand(time(NULL));
	int long *vec = arg(N, 0);
	int long *checar1 = arg(C, D);
	cout << "checando" << endl;
	long double time;
	clock_t start, finish;
	start = clock();
	checar(vec, checar1, N, C);
	finish = clock();
	time = (long double)(finish-start)/CLOCKS_PER_SEC;

	cout << "Busqueda secuencial tardo: " << time << endl;


	start = clock();
	checar_bin(vec, checar1, N, C);
	finish = clock();
	time = (long double)(finish-start)/CLOCKS_PER_SEC;

	cout << "Busqueda binaria tardo: " << time << endl;

	liberar (vec);
	liberar (checar1);
}
