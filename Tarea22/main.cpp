#include <iostream>
#include <stack>
#include <set>
#define M 100000

using namespace std;

int *vec_aleatorio(int N){
	int *vec = new int[N];
	for (int i = 0; i < N; ++i)
		vec[i] = rand() % N;
	return vec;
}

int *copiar_vec(int *vec, int N){
	int *v = new int[N];
	for (int i = 0; i < N; ++i){
		v[i] = vec[i];
	}
	return v;
}

template <typename Item>
void exch( Item &A, Item &B){
	Item t = A;
	A = B;
	B = t;
}

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

void quickSortSet(int arr[], int l, int r){
	multiset<int> Set;
	multiset<int>::iterator it;
	int j;
	for (int i = l; i < r; ++i)
		Set.insert(arr[i]);
	for (it = Set.begin(), j = 0; it != Set.end(); ++it){
		arr[j] = *it;
		++j;
	}

}

int main(int argc, char const *argv[])
{
	int *vec, *vec2;
	clock_t start, end;
	double tiempo;
	vec = vec_aleatorio(M);
	vec2 = copiar_vec(vec, M);
	
	start = clock();
	quickSortIterative<int>(vec, 0, M);
	end = clock();
	tiempo = (double)(end-start)/CLOCKS_PER_SEC;
	cout << "stack: " << tiempo << endl;

	start = clock();
	quickSortSet(vec2, 0, M);
	end = clock();
	tiempo = (double)(end-start)/CLOCKS_PER_SEC;
	cout << "set: " << tiempo << endl;
	return 0;
}