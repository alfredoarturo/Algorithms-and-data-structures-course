#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
static const int N = 150;
static const int Pot = 3;


double TQuickUnionR(long int *id, long int *sz, long int p, long int q){
	clock_t start, finish;
	double t;
	long int i, j;

	start = clock();

	for(i = p; i != id[i]; i = id[i]);  //find
	for(j = q; j != id[j]; j = id[j]);
	if ( i == j ) {
		finish = clock();
		t = ((finish-start)/(double)CLOCKS_PER_SEC);
		return t;
	}

	if(sz[i] < sz[j]){
		id[i] = j; sz[j]+= sz[i];  // quick union + peso
	}
	else{
		id[j] = i; sz[i]+= sz[j];  // quick union + peso
	}

	finish = clock();
	t = (finish-start)/ (double)CLOCKS_PER_SEC;
	return t;
}

double TQuickUnion(long int *id, long int p, long int q){
	clock_t start, finish;
	double t;
	long int i, j;

	start = clock();

	for ( i = p; i != id[i]; i = id[i]);  //find
	for ( j = q; j != id[j]; j = id[j]);
	if ( i == j){
		finish = clock();
		t = ((finish-start)/(double)CLOCKS_PER_SEC);
		return t;
	}
	id[i] = j;  // quick union

	finish = clock();
	t = ((finish-start)/(double)CLOCKS_PER_SEC);
	return t;
}

double TQuickFind(long int *id, long int p, long int q){
	clock_t start, finish;
	double T;
	long int i, j;

	start = clock();

	int t = id[p];
	if (t == id[q]){  //quick find
		finish = clock();
		T = ((finish-start)/(double)CLOCKS_PER_SEC);
		return T;
	}
	for ( i = 0; i < N; ++i)  //union
		if (id[i] == t) id[i] = id[q];

	finish = clock();
	T = ((finish-start)/(double)CLOCKS_PER_SEC);
	return T;
}

long int giveMeRandomNPot10(int pot10){
	long int n=0,fact=1; //n es resultado y factor potencia de 10
	for(int i=0;i<pot10;i++){
	n += (rand() % 10) * fact;
	fact *=10;
	}
	return n;
}

int main(){
	srand(time(NULL));
	clock_t start, finish;
	double T;
	long int i, j;

	start = clock();

	long int p, q;
	long int *idQUR = (long int *)malloc(sizeof(long int) * N);
	long int *idQU = (long int *)malloc(sizeof(long int) * N);
	long int *idQF = (long int *)malloc(sizeof(long int) * N);
	long int *sz = (long int *)malloc(sizeof(long int) * N);
	double TQUR = 0, TQU = 0, TQF = 0;
	for (int i = 0; i < N; ++i){
		idQUR[i] = i; sz[i] = 1;
		idQU[i] = i;
		idQF[i] = i;
	}
	cout << "Inicio" <<endl;
	for (int j = 0; j < N; ++j){
		p = giveMeRandomNPot10(Pot);
		q = giveMeRandomNPot10(Pot);
		TQUR += TQuickUnionR(idQUR, sz, p, q);
		TQU += TQuickUnion(idQU, p, q);
		TQF += TQuickFind(idQF, p, q);
	}
	cout.precision(10);
	cout << "Quick Union Robusto tardo: " << fixed << TQUR << endl;
	cout << "Quick Union tardo: " << fixed << TQU << endl;
	cout << "Quick Find tardo: " << fixed << TQF << endl;
	free(idQUR);
	free(idQU);
	free(idQF);
	free(sz);

	finish = clock();
	T = ((finish-start)/(double)CLOCKS_PER_SEC);
	cout << fixed << T << endl;
	return 0;
}