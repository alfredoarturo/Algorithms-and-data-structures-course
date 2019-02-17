#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct nodo{
	int item;
	nodo* next;

	nodo(int a, nodo *siguiente){
		item = a;
		next = siguiente;
	}
} nodo;

void insertar_inicio(int a, nodo **lista){			//Se usa un doble apuntador, porque se va a modificar el apuntador a lista, así que se debe de tener un apuntador al apuntador de lista, para poder modificarlo dentro de la función, de lo contrario no lo va a modificar.
	nodo *aux = new nodo(a, *lista);			//Se agrega un nodo con item a al inicio de la lista
	*lista = aux;
}

void inserta_final(int a, nodo *lista){				//inserta un nodo con item a al final de la lista
	nodo *aux;
	aux = lista;
	while(aux->next != NULL)				//encuentra el último elemento de la lista
		aux = aux->next;
	nodo *n = new nodo(a, NULL);
	aux->next = n;
}

void inserta_pos_n(int a, int n, nodo *lista){			//inserta un nodo en la posicion n, con item a
	nodo *aux = lista;
	for(int i = 0; i < n; ++i){
		if (aux->next == NULL){				//esto por si se da un valor fuera del rango de la lista
			cout << "Error al insertar" << endl;
			return;
		}
		aux = lista->next;
	}
	nodo *nd = new nodo(a, aux->next);
	aux->next = nd;
}

void borrar_inicio(nodo **lista){				//borra el primer nodo de la lista
	nodo *aux;
	aux = (*lista)->next;
	delete *lista;
	*lista = aux;
}

void borrar_final(nodo *lista){					//borra el último nodo de la lista
	nodo *aux, *aux2;
	aux2 = NULL;
	aux = lista;
	while(aux->next != NULL){
		aux2 = aux;
		aux = aux->next;
	}
	delete aux;
	aux2->next = NULL;
}

void imprime_lista(nodo *lista){				//imprime la lista del primer al último elemento
	nodo *aux = lista;
	while(aux != NULL){					//encuentra el final de la lista
		cout << "Elemento: " << aux->item << endl;
		aux = aux->next;
	}
	cout << endl;
}

int main(){
	nodo *lista;
	lista = new nodo(10, new nodo(20, new nodo(30, NULL)));
	imprime_lista(lista);
	insertar_inicio(12, &lista);
	imprime_lista(lista);
	inserta_final(13, lista);
	imprime_lista(lista);
	inserta_pos_n(14, 2, lista);
	imprime_lista(lista);
	borrar_inicio(&lista);
	borrar_final(lista);
	imprime_lista(lista);
}
