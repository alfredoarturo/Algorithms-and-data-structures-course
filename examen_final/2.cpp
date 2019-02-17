#include <iostream>
#include <map>
#include <list>

using namespace std;

class Diccionario{
private:
	map< char, list<string> > orden;
	int letras;

public:
	Diccionario(){
		letras = 26;															//Se determina el número de letras que se van a tener
	}

	void insertar(char *palabra){
		if (palabra[0] - 'a' < 0 || palabra[0] - 'a' >= letras){					//Se verifica que la palabra comience con una letra dentro de los caracteres permitidas
			cout << "Palabra no valida" << endl;
			return;
		}
		map< char, list< string > >::iterator it;								//Iterador del mapa orden
		it = orden.find(palabra[0]);											//Se busca el primer caracter de la palabra
		if (it == orden.end()){													//Si el caracter ha sido agegado como llave en el mapa
			list<string> lista;
			lista.push_back(palabra);											//Se agrega la palabra a la lista
			orden.insert(pair<char, list<string>>(palabra[0], lista));			//Se agrega la lista al mapa con llave el primer caracter de la palabra
			return;
		}
		it->second.push_back(palabra);											//Se agrega a la lista co llave la primer letra de la palabra, otra palabra
	}

	void listapor(char letra){
		if (letra - 'a' < 0 || letra - 'a' >= letras){							//Se verifica que la palabra sea valida
			cout << "Letra no valida" << endl;
			return;
		}
		map< char, list< string > >::iterator it;
		it = orden.find(letra);													//Se busca la lista que tiene como llave la letra indicada
		if (it == orden.end())
			return;
		list<string>::iterator it2;
		for (it2 = it->second.begin(); it2 != it->second.end(); ++it2)			//Se itera en la lista para imprimir sus elementos
			cout << *it2 << " ";
		cout << endl;
	}

	void listar(){
		map< char, list< string > >::iterator it;
		for(it=orden.begin(); it != orden.end(); ++it)							//Se itera en los elementos del mapa y se llama imprimir las listas.
			listapor(it->first);
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