#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct pareja{
	int a, b;
} par; //para contener a los dos enteros ingresados

void euler(par *p){  //algoritmo de euclides implementado
	if (p->a < p->b)
		p->b = p->b % p->a;
	else if (p->a >= p->b)
		p->a = p->a % p->b;
}

void checar(par *p){  //checa si se terminó el proceso o se debe de continuar
	while(2<4){
		if (p->a == 0){
			cout <<"El MCD es: " << p->b << endl;
			return;
		}
		else if (p->b == 0){
			cout << "El MCD es: " << p->a << endl;
			return;
		}
		else{
			euler(p);
		}
	}
}

int main(int narg, char * args[]){
	par *p;
	if(narg < 3){
		cout << "Error, introduce comandos" << endl;
		return 1;
	}
	p = (par *)malloc(sizeof(par));
	p->a = atoi(args[1]);
	p->b = atoi(args[2]);
	cout << "checando" << endl;
	checar(p);
	return 0;
}
