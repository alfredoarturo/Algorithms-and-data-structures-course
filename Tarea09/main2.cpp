#include <iostream>

using namespace std;

struct node {
	int item;
	node* next;
	node(int x, node* t) { item = x; next = t; }
};
typedef node *liga;

node *buscar(int a, node *lista){
	node *aux;
	aux = lista;
	while(aux->next != NULL){
		if (aux->item == a)
			return aux;
		if (a < aux->item){
			aux = NULL;
			return aux;
		}
		aux = aux->next;
	}
}

int inserta_final(int a, liga lista){
	node *aux;
	aux = lista;
	while(aux->next != NULL){
		if (a % aux->item == 0)
			return 0;
		aux = aux->next;
	}
	node *n = new node(a, NULL);
	aux->next = n;
	return 1;
}

int main(int argc, char *argv[]){
	int i = 1, n = atoi(argv[1]), b = atoi(argv[2]), c = 3;

	liga inicio;
	liga t = new node (2, NULL);
	inicio = t;
	while (i < n){
		if (inserta_final(c, t) == 1)
			++i;
		++c;
	}
	while (t->next != NULL){
		cout << t->item << " ";
		t = t->next;
	}
	cout << endl;
	cout << "Buscando " << b << " Esta en: " << buscar(b, inicio) << endl;
	return 0;
}
