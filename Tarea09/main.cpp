#include <iostream>

using namespace std;

struct node {
	int item;					//este es el valor guardado en el nodo
	node* next;					//este será el apuntador al siguiente nodo
	node(int x, node* t) { item = x; next = t; }	//esto inicializa los elemntos del node
};
typedef node *liga;					//llama liga a un apuntador de node

int main( int argc, char *argv[]){
	int i, n = atoi(argv[1]), k = atoi(argv[2]);	//esto convierte un argumento ingresado desde la terminal a un entero, que es el tamaño de la lista que se va a crear y de cuanto en cuanto se va a avanzar

	liga t = new node (1, NULL);			//esto inicializa un nodo con valor 1 y apuntador a NULL
	t->next = t;					//esto hace que se haga un circulo de solo un nodo
	liga x = t;					//esto es un auxiliar que apunta al unico nodo del circulo
	for (i = 2; i <= n; ++i){
		x = (x->next = new node(i, t));		//esto crea nodos de 2 a n en circulo
	}
	cout << "mueren";
	while(x != x->next){				//Esto va a iterar hasta que solo quede un elemnto en el circulo de nodos
		for (i = 1; i < k; ++i){		//va a avanzar k lugares en el ciruclo
			x = x->next;			//esto avanza el apuntador k lugares
		}
		t = x->next;				//Después de las iteraciones llegamos al nodo k, igualamos a t para borrarlo después
		x->next = t->next;			//Unimos el nodo que va antes de t con el siguiente a t para sacar a t de la lista
		cout << t->item << " "; 		//Mostramos el nodo que sacamos de la lista
		delete t;				//Eliminamos a t de la lista
	}
	cout << "sobrevive: " << x->item << endl;	//Después de realizar las iteraciones necesarias para que sólo quede un nodo, lo mostramos
}
