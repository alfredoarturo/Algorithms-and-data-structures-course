#include <iostream>

using namespace std;

struct a {
	int dias;
	int multa;
	int id;
};

typedef a ord;

template <typename Item>
void bubbleSort( Item a[], int l, int r){
	Item temp;
	int  obj1, obj2;
	for ( int i = r; i >= l; --i){
		for ( int j = l+1; j <= i; ++j){
			obj1 = a[j].dias*a[j-1].multa;
			obj2 = a[j-1].dias*a[j].multa;
			if ( obj1 < obj2 ){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
			}
		}
	}
}

void resolver(ord *vec, int N){
	bubbleSort <ord> (vec, 0, N-1);
	for (int i = 0 ; i < N; ++i)
		cout << vec[i].id << " ";
	cout << endl;
}

int main(){
	int ncasos, N;
	cin >> ncasos;
	while (ncasos--){
		cin >> N;
		ord *vec = new ord[N];
		for (int i = 0; i < N; i++){
			cin >> vec[i].dias >> vec[i].multa;
			vec[i].id = i+1;
		}
		resolver(vec, N);
		cout << endl;
		if (ncasos)
			cout << endl;
		delete vec;
	}
	return 0;
}
