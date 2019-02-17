#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#define maxN 10000000


using namespace std;

template <typename Item>
void exch( Item &A, Item &B){
	Item t = A;
	A = B;
	B = t;
}

int *llenar_vec(int N){
	int *vec = new int[N];
	for (int i = 0; i < N; ++i)
		vec[i] = rand() % 1000;
	return vec;
}

int *vec_ordenado(int N){
	int *vec = new int[N];
	for (int i = 0; i < N; ++i)
		vec[i] = i;
	return vec;
}

int *vec_semiordenado(int N){
	int *vec = new int[N];
	for (int i = 0; i < N; ++i)
		vec[i] = i % 100;
	return vec;
}

int *vec_mayor(int N){
	int *vec = new int[N];
	for (int i = N; i > 0; --i)
		vec[N-i] = i;
	return vec;
}

int *copia_vec(int *vec, int N){
	int *cop = new int[N];
	for (int i = 0; i < N; ++i)
		cop[i] = vec[i];
	return cop;
}


//Esto es quickSort
//*************************************************************************

template <typename Item>
int partition( Item a[], int l, int r){
	int i = l-1;
	int j = r;
	Item v = a[r];
	for (;;){
		while( a[++i] < v);
		while( v < a[--j])
			if ( j == i)
				break;
		if ( i >=j)
			break;
		exch<Item>(a[i], a[j]);
	}
	exch<Item> ( a[i], a[r] );
	return i;
}

template <typename Item>
void quickSort (Item a[], int l, int r){
	if (r <= l) return;
	int i = partition<Item> (a, l, r);
	quickSort<Item> (a, l, i-1);
	quickSort<Item> (a, i+1, r);
}

template<class Item>
class par{
public:
	int left, right;
	par(Item l, Item r){ left = l; right = r;}
};

template<typename Item>
void quickSortIterative (Item arr[], int l, int r){
	stack< par<Item> > Stack;

	par<Item> unPar(l, r);
	Stack.push(unPar);

	while (!Stack.empty() ){
		unPar = Stack.top();
		Stack.pop();
		l = unPar.left; r = unPar.right;

		Item p = partition(arr, l, r);

		if (p-1 > l){
			unPar.left = l; unPar.right = p-1;
			Stack.push(unPar);
		}

		if ( p+1 < r){
			unPar.left = p+1; unPar.right = r;
			Stack.push(unPar);
		}
	}
}

//Termina quickSort
//************************************************************************

//ESto es mergeSort
//************************************************************************

template <typename Item>
void merge( Item a[], int l, int m, int r){
	int i, j;
	static Item aux[maxN];
	for ( i = m+1; i > l; --i)
		aux[i-1] = a[i-1];
	for ( j = m; j < r; ++j)
		aux[r+m-j] = a[j+1];
	for (int k = l; k <= r; ++k){
		if( aux[j] < aux[i] )
			a[k] = aux[j--];
		else
			a[k] = aux[i++];
	}
}

template <typename Item>
void mergeSort( Item a[], int l, int r){
	if ( r <= l) return;
	int m = (r+l)/2;
	mergeSort<Item> (a,l,m);
	mergeSort<Item> (a,m+1,r);
	merge<Item> (a,l,m,r);
}

template <typename Item>
void mergesort_inter( Item a[], int l, int r){
	for ( int m = 1; m<=r-l; m= m+m){
		for (int i = l; i < r-m; i+=m+m)
			merge(a, i, i+m-1, min(i+m+m-1, r));
	}
}

//Termina MergeSort
//************************************************************************

//Inicia heapsort
//***********************************************************************

template <typename Item>
void fixDown( Item a[], int k, int N){
	while ( 2*k <= N){
		int j = 2*k;
		if (j < N && a[j] < a[j+1])
			j++;
		if (!(a[k] < a[j]))
			break;
		exch(a[k], a[j]);
		k = j;
	}
}

template <typename Item>
void heapSort( Item a[], int l, int r){
	int k, N = r-l+1;
	Item *pq = a+l-1;
	for (int k=N/2; k >=1; --k)
		fixDown (pq, k, N);
	while ( N > 1){
		exch( pq[1], pq[N] );
		fixDown( pq, 1, --N);
	}
}

//Termina heapsort
//*******************************************************************


int main(){
	srand(time(NULL));
	int *vec, N = maxN;
	int *v1, *v2, *v3, *v4, *v5;
	double qs, qsi, ms, msi, hs;
	clock_t start, finish;
	vec = vec_mayor(N);
	v1 = copia_vec(vec, N);
	v2 = copia_vec(vec, N);
	v3 = copia_vec(vec, N);
	v4 = copia_vec(vec, N);
	v5 = copia_vec(vec, N);

	start = clock();
	quickSort(v1, 0, N);
	finish = clock();
	qs = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "QuickSort tardó: " << qs << endl;

	start = clock();
	quickSortIterative(v2, 0, N);
	finish = clock();
	qsi = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "QuickSort iterativo tardó: " << qsi << endl;

	start = clock();
	mergeSort(v3, 0, N);
	finish = clock();
	ms = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "MergeSort tardó: " << ms << endl;

	start = clock();
	mergesort_inter(v4, 0, N);
	finish = clock();
	msi = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "MergeSort iterativo tardó: " << msi << endl;

	start = clock();
	heapSort(v5, 0, N);
	finish = clock();
	hs = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "heapSort tardó: " << hs << endl;

	delete [] vec;
	delete [] v1;
	delete [] v2;
	delete [] v3;
	delete [] v4;
	delete [] v5;

	return 0;
}
