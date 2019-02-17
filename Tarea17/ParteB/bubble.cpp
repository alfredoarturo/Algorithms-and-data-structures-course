#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename Item>
void bubbleSort_mejorado( Item a[], int l, int r){
	Item temp;
	for ( int i = r; i >= l/2; --i){
		for ( int j =  l+1; j <= i; ++j){
			if ( a[j-1] > a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}

			if( (a[r-j] > a[r-j+1]) && (r-j > j)){
				temp = a[r-j+1];
				a[r-j+1] = a[r-j];
				a[r-j] = temp;
			}
		}
	}
}

template <typename Item>
void bubbleSort( Item a[], int l, int r){
	Item temp;
	for ( int i = r; i >= l; --i){
		for ( int j =  l+1; j <= i; ++j){
			if ( a[j-1] > a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

int *nums(int n){
	int *vec = new int[n];
	for ( int i = 0; i < n; ++i)
		vec[i] = rand() % 1000;
	return vec;
}

int *copia(int *original, int n){
	int *c = new int[n];
	for (int i = 0; i < n; ++i)
		c[i] = original[i];
	return original;
}

int main(){
	int *a, *b, N = 10000;
	double time;
	clock_t start, finish;
	a = nums(N);
	b = copia(a, N);
	cout << "vector original" << endl;
	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl << endl << endl;
	start = clock();
	bubbleSort_mejorado <int> (a, 0, N);
	finish = clock();
	time = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "vector ordenado" << endl;
	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;
	cout << "Ambos lados Tardo: " << time << endl;
	start = clock();
	bubbleSort <int> (a, 0, N);
	finish = clock();
	time = (double)(finish-start)/CLOCKS_PER_SEC;
	cout << "vector ordenado" << endl;
	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;
	cout << "Un lado Tardo: " << time << endl;

	delete [] a;
//	delete [] b;
}
