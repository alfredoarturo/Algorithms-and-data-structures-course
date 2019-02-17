#include <iostream>
#include <stack>

using namespace std;

void optimo_k(int k, int *op1, int *op2, int *cam1, int *cam2, int *l1, int *l2, int *t12, int *t21){
	op1[0] = l1[0] + t12[0];
	op2[0] = l2[0] + t21[0];
	cam1[0] = 1;
	cam2[0] = 2;
	for (int i = 1; i < k; ++i){
		if (op1[i-1] <= op2[i-1] + t21[i]){
			op1[i] = op1[i-1] + l1[i];
			cam1[i] = 1;
		}
		else{
			op1[i] = op2[i-1] + t21[i] + l1[i];
			cam1[i] = 2;
		}
		if (op2[i-1] <= op1[i-1] + t12[i]){
			op2[i] = op2[i-1] + l2[i];
			cam2[i] = 2;
		}
		else{
			op2[i] = op1[i-1] + t12[i] + l2[i];
			cam2[i] = 1;
		}
	}
}

int optimo(int n, int *op1, int *op2, int *cam1, int *cam2, int *l1, int *l2, int *t12, int *t21){
	optimo_k(n, op1, op2, cam1, cam2, l1, l2, t12, t21);
	op1[n-1] += t12[n];
	op2[n-1] += t21[n];
	if (op1[n-1] <= op2[n-1])
		return op1[n-1];
	return op2[n-1];
}

void imprime_camino(int n, int *op1, int *op2, int *cam1, int *cam2){
	int aux = 0;
	if (op1[n-1] <= op2[n-1]){
		aux = 1;
	}
	else{
		aux = 2;
	}

	if (aux == 2){
		for (int i = 1; i < n; ++i){
			cout << cam1[i] << " ";
		}
	}

	else{
		for (int i = 1; i < n; ++i){
			cout << cam2[i] << " ";
		}
	}

	cout << aux;

	cout << endl;
}

int main(){
	int Ncasos, tam;
	int *l1, *l2, *t12, *t21, *op1, *op2, *cam1, *cam2;
	cin >> Ncasos;
	for (int i = 0; i < Ncasos; ++i){
		cin >> tam;

		op1 = new int[tam];
		op2 = new int[tam];
		cam1 = new int [tam];
		cam2 = new int [tam];

		for (int i = 0; i < tam; ++i){
			op1[i] = 0;
			op2[i] = 0;
			cam1[i] = 0;
			cam2[i] = 0;
		}
		
		l1 = new int[tam];
		
		for (int i = 0; i < tam; ++i)
			cin >> l1[i];

		l2 = new int[tam];
		
		for (int i = 0; i < tam; ++i)
			cin >> l2[i];

		t12 = new int[tam+1];

		for (int i = 0; i < tam + 1; ++i)
			cin >> t12[i];

		t21 = new int[tam+1];

		for (int i = 0; i < tam + 1; ++i)
			cin >> t21[i];
	
		cout << optimo(tam, op1, op2, cam1, cam2, l1, l2, t12, t21) << endl;
		imprime_camino(tam, op1, op2, cam1, cam2);

		delete [] l1;
		delete [] l2;
		delete [] t12;
		delete [] t21;
		delete [] op1;
		delete [] op2;
		delete [] cam1;
		delete [] cam2;
	}
}