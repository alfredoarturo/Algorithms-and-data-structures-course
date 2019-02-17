#include <iostream>
#include <list>

using namespace std;

class Diccionario{
private:
	list<string> *lista;																// se tiene un vector de listas que se va  estar modificando
	int letras;

public:
	Diccionario(){
		letras = 27;
		this->lista = new list<string>[letras];										//se inivializa vector de listas a la cantidad de letras
	}

	void insertar(char *palabra){
		if (palabra[0] < 'a' || palabra[0] > 'z'){									//se verifica que la letra esté en el alfabeto
			cout << "Palabra no valida" << endl;
			return;
		}
		lista[palabra[0]-'a'].push_back(palabra);									//se agrega la palabra
	}

	void listapor(char letra){
		list<string>::iterator it;
		if (letra < 'a' || letra > 'z'){											//se verifica que la letra esté en el alfabeto
			cout << "Letra no valida" << endl;
			return;
		}
		for (it = lista[letra-'a'].begin(); it != lista[letra-'a'].end(); ++it){
			cout << *it << endl;													//se imprimen los elementos iterados en la lista
		}
	}

	void listar(){
		for (int i = 0; i < letras; ++i)
			listapor('a'+i);														//se itera entre todas las listas
	}

	~Diccionario(){
		delete [] lista;
	}

};


int main(){
	Diccionario d;
	int salir = 0;
	char palabra[41];
	int opcion;
	char letra;

	while (!salir){
		cout << "1. Introducir palabra \n";
		cout << "2. Listar palabras que empiecen por ...\n";
		cout << "3. Listar todas las palabras \n";
		cout << "4. Salir \n";
		cin >> opcion;
		switch(opcion){
			case 1: cout << "Introduzca palabra:  ";
				cin >> palabra;
				d.insertar(palabra);
				break;
			case 2: cout << "Introduzca letra:  ";
				cin >> letra;
				d.listapor(letra);
				break;
			case 3:
				d.listar();
				break;
			case 4:
				salir = 1;
				break;
			default: 
				cout << "Eleccion incorrecta \n";
				break;
		}
	}
}