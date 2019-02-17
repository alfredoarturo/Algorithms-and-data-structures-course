#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template<class t>
class l_nodo{
private:
	int grado;
	l_nodo<t> *next;
	t coef;
public:
	l_nodo<t> (int n){
		if (n <= 0){
			this->next = NULL;
			this->coef = 0;
			return;
		}
		this->grado = n;
		this->coef = 0;
		this->next = new l_nodo<t>(n-1);
	}

	l_nodo<t> *get_next(){ return next; }

	int get_grado(){ return grado; }

	t get_coef(){ return coef; }

	void set_next(l_nodo<t> *a){ next = a; }

	void set_grado(int a){ grado = a; }

	void set_coef(t a){ coef = a; }

	void leer_pantalla(){
		int N;
		cin >> N;
		this->grado = N;
		if (N== 0){
			this->next = NULL;
			cin >> this->coef;
			return;
		}
		this->next = new l_nodo<t>(N-1);
		l_nodo *aux = this;
		while (aux != NULL){
			cin >> aux->coef;
			aux = aux->next;
		}
	}

	void leer_documento(const char *nombre){
		int a;
		ifstream myfile (nombre, ifstream::in);
		if (!myfile.is_open()){
			cout << "Error al abrir el documento " << nombre << endl;
			return;
		}
		myfile >> this->grado;
		if (this->grado == 0){
			this->next = NULL;
			myfile >> this->coef;
			return;
		}
		this->next = new l_nodo<t>(grado-1);
		l_nodo *aux = this;
		while (aux != NULL){
			myfile >> aux->coef;
			aux = aux->next;
		}
	}

	void imprimir_pantalla(){
		cout << "imprimiendo" << endl;
		l_nodo *aux = this;
		while(aux != NULL){
			if (aux->coef == 0){
				aux = aux->next;
				continue;
			}
			cout << aux->coef << "(x^" <<  aux->grado << ")";
			if (aux->next != NULL)
				cout << " + ";
			else
				cout << endl;
			aux = aux->next;
		}
	}

	void imprimir_documento(const char *nombre){
		ofstream myfile;
		myfile.open (nombre);
		l_nodo *aux = this;
		myfile << grado << '\n';
		while (aux != NULL){
			myfile << aux->coef << ' ';
			aux = aux->next;
		}
		myfile.close();
	}

	double evaluar(double a){
		double res = 0, pot = 0;
		l_nodo *aux = this;
		while(aux != NULL){
			pot = pow(a, (aux->grado));
			res += (aux->coef) * pot;
			aux = aux->next;
		}
		return res;
	}
};

template <class t>
class pol{
private:
	l_nodo<t> *head;
public:
	pol(int n){
		head = new l_nodo<t>(n);
	}

	pol(){
		head = new l_nodo<t>(0);
	}

	l_nodo<t> *get_head(){ return head; }

	void leer_pantalla(){
		head->leer_pantalla();
	}
	void leer_documento(const char *nombre){
		head->leer_documento(nombre);
	}
	void imprimir_pantalla(){
		head->imprimir_pantalla();
	}
	void imprimir_documento(const char *nombre){
		head->imprimir_documento(nombre);
	}
	double evaluar(double a){
		head->evaluar(a);
	}

	void operator=( pol<t> a){
		a.imprimir_documento("aux.dat");
		this->leer_documento("aux.dat");
	}

	~pol(){
		l_nodo<t> *aux1, *aux2;
		aux1 = head;
		aux2 = NULL;
		while(aux1 != NULL){
			aux2 = aux1->get_next();
			delete aux1;
			aux1 = aux2;
		}
	}
};

template<typename t>
pol<t> operator+( pol<t> l, pol<t> r){
	int uno = (l.get_head())->get_grado();
	int dos = (r.get_head())->get_grado();
	l_nodo<t> *auxl = l.get_head();
	l_nodo<t> *auxr = r.get_head();
	if (uno <= dos){
		pol<t> *res = new pol<t> (dos);
		int dif = dos-uno;
		l_nodo<t> *aux = res->get_head();
		while (dif > 0){
			aux->set_coef(auxr->get_coef());
			aux = aux->get_next();
			auxr = auxr->get_next();
			--dif;
		}
		while(aux != NULL){
			aux->set_coef(auxl->get_coef()+auxr->get_coef());
			aux = aux->get_next();
			auxl = auxl->get_next();
			auxr = auxr->get_next();
		}
		return *res;
	}
	else{
		return r + l;
	}
}

template<typename t>
pol<t> operator-( pol<t> l, pol<t> r){
	int uno = (l.get_head())->get_grado();
	int dos = (r.get_head())->get_grado();
	l_nodo<t> *auxl = l.get_head();
	l_nodo<t> *auxr = r.get_head();
	if (uno <= dos){
		pol<t> *res = new pol<t> (dos);
		int dif = dos-uno;
		l_nodo<t> *aux = res->get_head();
		while (dif > 0){
			aux->set_coef(-auxr->get_coef());
			aux = aux->get_next();
			auxr = auxr->get_next();
			--dif;
		}
		while(aux != NULL){
			aux->set_coef(auxl->get_coef() - auxr->get_coef());
			aux = aux->get_next();
			auxl = auxl->get_next();
			auxr = auxr->get_next();
		}
		return *res;
	}
	else{
		pol<t> *res = new pol<t> (uno);
		int dif = uno-dos;
		l_nodo<t> *aux = res->get_head();
		while (dif > 0){
			aux->set_coef(auxl->get_coef());
			aux = aux->get_next();
			auxl = auxl->get_next();
			--dif;
		}
		while(aux != NULL){
			aux->set_coef(auxl->get_coef() - auxr->get_coef());
			aux = aux->get_next();
			auxl = auxl->get_next();
			auxr = auxr->get_next();
		}
		return *res;
	}
}

template <typename t>
pol<t> operator*(pol<t> l, pol<t> r){
	pol<t> *res = new pol<t>(l.get_head()->get_grado() + r.get_head()->get_grado());
	l_nodo <t> *aux = res->get_head();
	l_nodo <t> *auxl = l.get_head();
	l_nodo <t> *auxr = r.get_head();
	l_nodo <t> *temp;
	while(auxl != NULL){
		temp = aux;
		while(auxr != NULL){
			aux->set_coef(aux->get_coef()+ (auxl->get_coef()*auxr->get_coef()));
			aux = aux->get_next();
			auxr = auxr->get_next();
		}
		aux = temp->get_next();
		auxl = auxl->get_next();
		auxr = r.get_head();
	}
	return *res;
}

int main(){
	pol<int> *a, *b;
	a = new pol<int>();
	b = new pol<int>();
	a->leer_pantalla();
	a->imprimir_pantalla();
	b->leer_pantalla();
	b->imprimir_pantalla();
	cout << b->evaluar(1) << endl;
	cout << a->evaluar(1) << endl;	
	pol<int> *c = new pol<int>();
	*c = *a * *b;
	c->imprimir_pantalla();
	delete a;
	delete b;
	delete c;
}