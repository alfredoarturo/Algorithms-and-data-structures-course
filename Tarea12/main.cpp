#include <iostream>
#include <cstdio>

using namespace std;

void gotoxy(int x, int y){
	printf("%c[%d;%df",0x1B,y,x);
}

void limpiar(){
    for (int i = 0; i < 50; ++i){
        for (int j = 0; j < 81; ++j){
            gotoxy(j, i);
            cout << " ";
        }
    }
}

typedef int Item;

class nodo{
	private:
		Item val;
		nodo *next;
	public:
		nodo(Item x, nodo *y){
			val = x;
			next = y;
		}
		Item get_val(){ return val; }
		nodo *get_next(){ return next; }
		void iguala_next(nodo *a) { next = a; }
};

typedef nodo *liga;

class pila{
	private:
		liga head;
		int y;
	public:
		pila(liga a, int q){ head = a; y = q; }
		pila(){ head = NULL; y = 1; }
		void push(int);
		void pop();
		int size();
		int get_y(){ return y; }
		liga& peek(){
            if (head == NULL){
                cout << "malo" << endl;
            }
            return head;
        }
		friend ostream& operator<<(ostream &out, const pila a){
			liga aux;
			Item val;
			aux = a.head;
			int i = 0;
			while (aux != NULL){
				val = aux->get_val();
				out << val << " ";
				aux = aux->get_next();
				++i;
			}
			return out;
		}
};

void pila::push(int a){
	head = new nodo(a, head);
}

void pila::pop(){
	if (head == NULL)
		return;
    liga aux = head->get_next();
    delete [] head;
    head = aux;
}

int pila::size(){
	if (head == NULL)
		return 0;
	int cont = 1;
	liga aux;
	aux = head;
	while (aux->get_next() != NULL){
		++cont;
		aux = aux->get_next();
	}
	return cont;
}

void delay(){
	for (long int i = 0; i < 199999999; ++i);
}

void imprime(pila a, pila b, pila c){
    limpiar();
    gotoxy(1, a.get_y());
    cout << "Pila a:";
    gotoxy(10, a.get_y());
	cout << a << endl;
	gotoxy(1, b.get_y());
    cout << "Pila b:";
	gotoxy(10, b.get_y());
	cout << b << endl;
	gotoxy(1, c.get_y());
    cout << "Pila c:";
	gotoxy(10, c.get_y());
	cout << c << endl;
	gotoxy(0, 0);
    delay();
}

void hanoi(int discos, pila *ini, pila *des, pila *aux){
	if (discos == 1){
		des->push(ini->peek()->get_val());
		ini->pop();
		imprime(*ini, *des, *aux);
	}
	else{
		hanoi(discos - 1, ini, aux, des);
		des->push(ini->peek()->get_val());
		ini->pop();
		imprime(*ini, *des, *aux);
		hanoi(discos - 1, aux, des, ini);
	}
}

int main(){
	pila *a = new pila(new nodo(1, new nodo(2, new nodo(3, new nodo(4, NULL)))), 5);
	pila *b = new pila(NULL, 10);
	pila *c = new pila(NULL, 15);
	hanoi(a->size(), a, b, c);
	return 0;
}

