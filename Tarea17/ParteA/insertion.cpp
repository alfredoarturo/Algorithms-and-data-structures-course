#include <iostream>

using namespace std;

template <typename Item>
void insertionSort(Item a[], int l, int r){
	int temp, j;

	for (int i = l+1; i < r; ++i){
		j = i;
		while( (j>l) && (a[j-1] > a[j])){
			temp = a[j-1];
			a[j-1] = a[j];
			a[j] = temp;
			--j;
		}
	}
}

int *nums(int n){
	int *vec = new int[n];
	for (int i = 0; i < n; ++i)
		vec[i] = rand() % 10;
	return vec;
}

int main(){
	srand(time(NULL));
	int *a, N = 1000000;
	a = nums(N);
	cout << "Vector original" << endl;
	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;
	insertionSort <int> (a, 0, N);
	cout << endl << endl << "vector ordenado" << endl;
	for (int i = 0; i < N; ++i)
		cout << a[i] << " ";
	cout << endl;
}
