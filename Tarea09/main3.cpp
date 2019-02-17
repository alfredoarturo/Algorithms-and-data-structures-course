#include <iostream>

using namespace std;

struct node{
	int item;
	node *next;
	node(int x, node*n){
		item = x;
		next = n;
	}
	node (){
		item = 0;
		next = NULL;
	}
};

typedef node *liga;

void limpia(liga lista){
	liga aux;
	aux = lista;
	while (aux->next != NULL){
		aux = aux->next;
		delete aux;
	}
}

void une_mantiene(liga uno, liga dos){
	liga aux;
	aux = uno;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = dos;
}

void une_limpia (liga uno, liga dos){
	une_mantiene(uno, dos);
	limpia(dos);
}

int main(){
	liga a = new node(1, new node(2, new node(3, NULL)));
	liga b = new node(5, new node(6, new node(8, NULL)));
	node p;
	p.item = 1;
	p.next = new node(2, new node(3, NULL));
	return 1;
}

