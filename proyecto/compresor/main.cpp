#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/*Esto es lo usado para que se lean los datos
	En el pair usado, se guardan los caracteres leidos primero y después el número de caracteres leidos
	La funcion leer llena una estructura par con los datos de archivo leido.	
*/


pair < char*, long int > *leer( const char *nombre ){
	ifstream is (nombre, ifstream::binary);
	if (is) {
    	is.seekg (0, is.end);
    	long int  length = is.tellg();
    	is.seekg (0, is.beg);

    	pair < char*, long int > *a = new pair <char*, long>;
    	a->second = length;

	    char * buffer = new char [length];

    	is.read (buffer,length);

    	if (!is)
    		cout << "error: solo se leyeron  " << is.gcount() << " caracteres";
  		is.close();

		a->first = buffer;

		return a;
	}
	cout << "Error";
  	return NULL;
}

/*
		Termina lo usado para leer de archivo
*/

/*Inicia lo relacionado con los nodos del arbolbinario que se va a necesitar*/

template <class t>
class nodo{
private:
	t item;
	nodo *l, *r;
public:
	nodo(t a, nodo* uno, nodo* dos){
		item = a;
		l = uno;
		r = dos;
	}
	
	t get_item(){
		return item;
	}

	nodo *get_left(){
		return l;
	}

	nodo *get_right(){
		return r;
	}

	void  set_left(nodo<t> *left){
		l = left;
	}

	void set_right(nodo<t> *right){
		r = right;
	}

	void inorden(int nivel, char **mem){
		static int vec[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
		int i;
		if (l != NULL){
			vec[nivel] = 0;
			l->inorden(nivel+1, mem);
		}
		if (item != '\0'){
			i = 0;
			for (int i = 0; i < nivel; ++i){
				mem[item][i] = '0' + vec[i];
			}
		}
		if (r != NULL){
			vec[nivel] = 1;
			r->inorden(nivel+1, mem);
		}
	}

	void preorden_guarda(ofstream& myfile){
		myfile << (int) item << ' ';
		if (l != NULL)
			l->preorden_guarda(myfile);
		else
			myfile << 300 << ' ';
		if (l != NULL)
			r->preorden_guarda(myfile);
		else
			myfile << 300 << ' ';
	}
};

template<typename Item>
void printnode (Item x, int h){
	for (int i = 0; i < h; ++i)
		cout << "   ";
	if (x == '\0')
		cout << 1 << endl;
	cout << x << endl;
}

template<typename tipo>
void show(nodo<tipo> *t, int h){
	if ( t == NULL){
		printnode<char>('*', h);
		return;
	}
	show(t->get_right(), h+1);
	printnode<tipo>(t->get_item(), h);
	show(t->get_left(), h+1);
}

/*
		Termina lo de arboles		
*/

/*
	Lo relacionado con las colas de prioridad que se van a usar para insertar los elementos dentro de la cola de prioridad.
*/

template <class t>
class nodo_p{
private:
	t item;
	long int prioridad;
	nodo_p<t> *next;

public:
	nodo_p(t a, long int p, nodo_p *b){
		item = a;
		prioridad = p;
		next = b;
	}

	void set_next(nodo_p *a){
		next = a;
	}

	t get_item(){
		return item;
	}

	long int get_prior(){
		return prioridad;
	}

	void set_prior(long int a){
		prioridad = a;
	}

	nodo_p<t> *get_next(){
		return next;
	}
};

template <class t>
class pila{
private:
	nodo_p<t> *head;
	int tam;

public:
	pila(){
		head = NULL;
		tam = 0;
	}

	void pop(){
		nodo_p<t> *aux = head->get_next();
		delete head;
		head = aux;
		--tam;
	}

	nodo_p<t> *top(){
		return head;
	}

	void push(t a){
		nodo_p<t> *aux = new nodo_p<t>(a, 0, head);
		head = aux;
		++tam;
	}

	int size(){
		return tam;
	}

	bool is_empty(){
		if (tam == 0)
			return true;
		return false;
	}
};

template <class t>
class pqueue{
private:
	nodo_p<t> *head;
	int tam;

public:
	pqueue(){
		tam = 0;
		head = NULL;
	}

	nodo_p<t> *get_head(){ return head; }

	void push(t a, int p){
		nodo_p<t> *aux1, *aux2;
		aux1 = head;
		aux2 = NULL;
		if (aux1 == NULL){
			head = new nodo_p<t>(a, p, NULL);
			tam+=1;
			return;
		}
		if (p < head->get_prior()){
			nodo_p<t> *nodo = new nodo_p<t>(a, p, head);
			head = nodo;
			tam += 1;
			return;
		}
		while(aux1 != NULL){
			if (aux1->get_prior() > p)
				break;
			if (aux1->get_next() == NULL){
				nodo_p<t> *node = new nodo_p<t>(a, p, NULL);
				aux1->set_next(node);
				tam+= 1;
				return;
			}
			aux2 = aux1;
			aux1 = aux1->get_next();
		}
		nodo_p<t> *node = new nodo_p<t>(a, p, aux1);
		if (aux2 != NULL)
			aux2->set_next(node);
		tam += 1;		
	}

	void pop(){
		nodo_p<t> *aux = head->get_next();
		delete head;
		head = aux;
		tam -= 1;
	}

	t top(){
		return head->get_item();
	}

	int get_tam(){ return tam; }

	bool empty(){
		if (tam <= 0)
			return true;
		return false;
	}
};

template <typename t>
void imprimir(pqueue <t> *cola){
	nodo_p<t> *aux = cola->get_head();
	while (aux != NULL){
		cout << aux->get_item()->get_item() << " " << aux->get_prior() << endl;
		aux = aux->get_next();
	}
}

/*
		Termina lo relacionado con las colas
*/

/*
	Aquí se lleva toda la informacion a un vector de repeticiones que van a tener los caracteres
*/
long int *apariciones(pair<char*, long int> *datos){
	long int *rep = new long int[255];
	for (int i = 0; i < 255 ; ++i)
		rep[i] = 0;
	for (int i = 0; i < datos->second; ++i)
		rep[datos->first[i]] += 1;
	return rep;
}
/*
		Termina lo que lleva a un vector pequeño la informacion
*/

/*
	Ahora se implementará lo necesario para insertar la informacion en la cola de prioridad
*/
void insertar(long int *apariciones, pqueue < nodo <char>* > *cola){
	for (int i = 0; i < 255; ++i){
		if (apariciones[i] <= 0){
			continue;
		}
		else{
			nodo<char> *a = new nodo<char>(i, NULL, NULL);
			cola->push(a, apariciones[i]);
		}
	}
}
/*
		Termina la insecion a la cola de prioridad
*/

/*
	Ahora inicia lo que es el algoritmo de Hufman
*/
void arbol(pqueue< nodo <char>* > *cola){
	while(cola->get_tam() >= 2){
		nodo <char> *izq, *der;
		int p1, p2;
		izq = cola->top();
		p1 = cola->get_head()->get_prior();
		cola->pop();
		der = cola->top();
		p2 = cola->get_head()->get_prior();
		cola->pop();
		nodo<char> *node = new nodo<char>('\0', izq, der);
		cola->push(node, p1+p2);
		//imprimir(cola);
		//cout << endl;
	}
}

void init_table(char ***codif){
	*codif = new char*[255];
	for (int i = 0; i < 255; ++i){
		(*codif)[i] = new char[10];
		for (int j = 0; j < 10; ++j)
			(*codif)[i][j] = '\0';
	}
}

pair<unsigned int, int> *comprimir(ofstream& archivo, char a, pair<unsigned int, int> *num){
	if (num->second == 8*sizeof(unsigned int)-1){
		if (a == '0')
			num->first = num->first << 1;
		else{
			num->first = num->first << 1;
			num->first += 1;
		}
		num->second = 0;
		archivo.write ((char *) &(num->first), sizeof(unsigned int));
		num->first = 0;
	}
	else{
		if (a == '0')
			num->first = num->first << 1;
		else{
			num->first = num->first << 1;
			num->first += 1;
		}
		num->second += 1;
	}
	return num;
}

void escribir(const char *archivo, char**codig, pair<char*, long int> *datos){
	ofstream myfile;
	myfile.open (archivo, ios::binary);
	int j;
	pair <unsigned int, int> *aux = new pair<unsigned int, int>;
	aux->first = 0;
	aux->second = 0;
	for (long int i = 0; i < datos->second; ++i){
		j = 0;
		while(codig[datos->first[i]][j] != '\0'){
			aux = comprimir(myfile, codig[datos->first[i]][j], aux);
			++j;
		}
	}
	int cont = 0;
	while (aux->second != 0){
		++cont;
		aux = comprimir(myfile, 0, aux);
	}
	ofstream auxfile;
	auxfile.open("aux.bin", ios::binary);
	auxfile.write((char *)&cont, sizeof(cont));
	auxfile.close();
	myfile.close();
}

template<typename t>
void guardar_arbol(pqueue<t> *datos){
	ofstream myfile;
	myfile.open ("uno.txt");
	datos->top()->preorden_guarda(myfile);
	myfile.close();
}

/*
----------------------------------------------------------------------------------------------------
		COMIENZA LA DECODIFICACION
----------------------------------------------------------------------------------------------------
*/

nodo<char> *leer_arbol(const char *nombre){
	ifstream myfile;
	myfile.open(nombre, ifstream::in);
	int a, b;
	pila < nodo < char>* > *stack = new pila < nodo < char >* >();
	nodo <char> *aux, *aux1;
	myfile >> a;
	aux1 = new nodo<char>(a, NULL, NULL);
	stack->push(aux1);
	while ( !stack->is_empty() && myfile){
		b = a;
		myfile >> a;
		if (a == 300 && b != 300){
			stack->top()->get_item()->set_left(NULL);
			stack->top()->set_prior(1);
			continue;
		}
		else if (a == 300 && b == 300){
			stack->top()->get_item()->set_right(NULL);
			stack->top()->set_prior(2);
			stack->pop();
			continue;
		}
		else{
			aux = new nodo<char>(a, NULL, NULL);
			if (stack->top()->get_prior() == 0){
				stack->top()->get_item()->set_left(aux);
				stack->top()->set_prior(1);
			}
			else{
				stack->top()->get_item()->set_right(aux);
				stack->top()->set_prior(2);
				stack->pop();
			}
			stack->push(aux);
		}
	}
	myfile.close();
	return aux1;
}

nodo<char> *descifrar(nodo<char> *actual, unsigned int mask, nodo<char>* arbol, unsigned int a, ofstream& decomp){
	unsigned int r;
	nodo <char> *aux = actual;
	for (int i = 0; i <= (8*sizeof(unsigned int)-1); ++i){
		if (aux->get_item() != '\0'){
			decomp << aux->get_item();
			aux = arbol;
			continue;
		}

		r = mask&a;
		if (r){
			aux = aux->get_right();
		}
		else{
			aux = aux->get_left();
		}
		if (aux == NULL){
			cout << "Error\n";
			aux = arbol;
		}
		if (aux->get_item() != '\0'){
			decomp << aux->get_item();
			aux = arbol;
		}
		mask = mask >> 1;
	}
	return aux;
}

void descomprimir(nodo<char>* arbol, const char *archivo, const char *decomp){
	ifstream file (archivo, ios::in | ios::binary);
	ofstream myfile;
	myfile.open(decomp);
	nodo <char> *aux = arbol;
	unsigned int a, mask = 1;
	for (int j = 0; j < (8*sizeof(unsigned int)-1); ++j){
		mask = mask << 1;
	}
	if (file.is_open()){
		while(file){
			file.read ((char*)&a, sizeof(a));
			aux = descifrar(aux, mask, arbol, a, myfile);
		}
	}
	int cont, cont2;
	ifstream auxfile;
	auxfile.open("aux.bin");
	auxfile.read((char*)&cont, sizeof(cont));
	cout << cont;
	auxfile.close();
	aux = arbol;
	while(aux->get_item() == '\0'){
		++cont2;
		aux = aux->get_left();
	}
	file.close();
	myfile.close();
}

int main () {

	/*Este bloque es el main para comprimir*/
	pair<char*, long int> *datos;

	datos = leer("prueba.txt");
	if (datos == NULL)
		return 1;

	long int *uno = apariciones(datos), cont = 0;
	pqueue < nodo <char>* > *cola = new pqueue< nodo <char>* >();
	char **codif;

	insertar(uno, cola);
	arbol(cola);
	
	init_table(&codif);
	cola->top()->inorden(0, codif);
	show(cola->top(), 0);
	escribir("uno.bin", codif, datos);
	guardar_arbol(cola);
	/*Aquí termina el main para comprimir*/

	/*Inicia el main para descomprimir*/
	nodo<char> *arbol = leer_arbol("uno.txt");
	show(arbol, 0);
	descomprimir(arbol, "uno.bin", "dos.txt");
	/*TErmina el main para descomprimir*/

	return 0;
}