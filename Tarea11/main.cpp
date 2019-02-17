#include <iostream>

using namespace std;

class nodo{
	public:
		int item;
		nodo *next;

		nodo (int x, nodo *sig){
			item = x;
			next = sig;
		}

		nodo (int x){
			item = x;
			next = NULL;
		}

		int longitud(){
			if (next ==  NULL)
				return 0;
			nodo *aux;
			int cuenta = 1;
			aux = next;
			while (aux->next != NULL){
				aux = aux->next;
				++cuenta;
			}
			return cuenta;
		}
		nodo *regresaNth(int n){
			nodo *aux;
			aux = next;
			for (int i = 1; i < n; ++i){
				if (aux == NULL)
					return NULL;
				aux = aux->next;
			}
			return aux;
		}
};

nodo *inter(nodo *a, nodo *b){
	int la, lb;
	nodo *aux, *aux2;
	la = a->longitud();
	lb = b->longitud();
	if (lb > la)
		aux = b->regresaNth(lb-la);
	else
		aux = a->regresaNth(la-lb);
	while(aux != aux2){
		aux = aux->next;
		aux2 = aux2->next;
	}
	return aux;
}

int main(){
	nodo *c = new nodo(1, new nodo(2, new nodo(3, NULL)));
	nodo *a = new nodo(4, new nodo(7, new nodo(9, c)));
	nodo *b = new nodo(5, c);
	nodo *aux;
	aux = inter(a, b);
	cout << "se intersectan en: " << aux << endl;
	cout << aux->item << endl;
}
