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

int longitud(nodo *lista){
	if (lista == NULL)					//En caso de que la lista se vacia
		return 0;
	nodo *aux;
	int cuenta = 1;
	aux = lista;
	while (aux->next != NULL){			//Busca llegar hasta el nodo final
		aux = aux->next;			//avanza al siguiente nodo
		++cuenta;				//contador
	}
	return cuenta;
}

void insertaAlInicio(int a, nodo **lista){			//Se usa un doble apuntador, porque se va a modificar el apuntador a lista, así que se debe de tener un apuntador al apuntador de lista, para poder modificarlo dentro de la función, de lo contrario no lo va a modificar.
	nodo *aux = new nodo(a, *lista);			//Se agrega un nodo con item a al inicio de la lista
	*lista = aux;
}

void insertaAlFinal(int a, nodo *lista){				//inserta un nodo con item a al final de la lista
	nodo *aux;
	if (aux != NULL){
		aux = lista;
		while(aux->next != NULL)			//encuentra el último elemento de la lista
			aux = aux->next;
		nodo *n = new nodo(a, NULL);			//se genera el nuevo nodo
		aux->next = n;
	}
	else
		aux = new nodo(a, NULL);			//nuevo nodo en caso de que sea vacia la lista
}

nodo *regresaNth(int n, nodo *lista){
	nodo *aux;
	aux = lista;
	for (int i = 1; i < n; ++i){				//este for avanza hast llegar a la posicion n
		if (aux->next == NULL)				//caso en el que la lista no llega a tener n elementos
			return NULL;
		aux = aux->next;				//Se guarda la posicion actual en aux
	}
	return aux;						//Se regresa aux, que es la posicion n
}

void limpiar(nodo **lista){
	nodo *aux;
	if ((*lista) == NULL)
		return;
	while((*lista)->next != NULL){
		aux = (*lista)->next;
		delete  (*lista);
		(*lista) = aux;
	}
	(*lista) = NULL;
}

nodo *ultimo(nodo *lista){
	nodo *aux;
	if (aux != NULL){
		aux = lista;
		while (aux->next != NULL)
			aux = aux->next;
		return aux;
	}
	return NULL;
}

void quitaPrimero(nodo **lista){				//borra el primer nodo de la lista
	nodo *aux;
	if (*lista != NULL){
		aux = (*lista)->next;
		delete *lista;
		*lista = aux;
	}
}

void quitaUltimo(nodo *lista){					//borra el último nodo de la lista
	nodo *aux, *aux2;
	if (lista == NULL)
		return;
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
	nodo *a = new nodo(1, new nodo(2, new nodo(3, NULL)));
	cout << "Lista original" << endl;
	imprime_lista(a);
	cout << "Longitud: " << longitud(a) << endl;
	insertaAlFinal(4, a);
	cout << "Se inserto al final" << endl;
	imprime_lista(a);
	insertaAlInicio(0, &a);
	cout << "Se inserto al inicio" << endl;
	imprime_lista(a);
	cout << "El apuntador del ultimo elemento: " << ultimo(a) << endl;
	quitaPrimero(&a);
	cout << "Se quito el primer elemento" << endl;
	imprime_lista(a);
	quitaUltimo(a);
	cout << "Se quito el ultimo elemento" << endl;
	imprime_lista(a);
}
