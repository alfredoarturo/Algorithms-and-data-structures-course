#include <iostream>
#include <string>
#include <map>

using namespace std;

class GuiaTelefonos{
private:
	map <string, string> guia;
public:
	GuiaTelefonos(){
		cout << "Guia creada" << endl;
	}

	~GuiaTelefonos(){
		cout << "Guia eliminada" << endl;
	}

	string buscarEntrada(const string& nombre){
		map<string,string>::iterator it;
		cout << "Buscando a: " << nombre;
		it = guia.find(nombre);
		if (it != guia.end())													//Si el elemeto se encuentra en la guia
			return it->second;
		cout << "Usuario no existente" << endl;
		return "NULL";															//Si el usuario buscado no existe
	}

	void insertarEntrada(const string& nombre, const string& numero){
		map<string,string>::iterator it;
		it = guia.find(nombre);
		if (it != guia.end()){													//Si se quiere insertar un usuarioa ya existente otra vez
			cout << "Usuario existente" << endl;			
			return;
		}
		cout << "creando a: " << nombre << endl;
		guia.insert(pair <string, string> (nombre, numero));					//Se crea al nuevo usuario
	}

	void modificarEntrada(const string& nombre, const string& numero){
		cout << "Modificando a: " << nombre << endl;
		map<string,string>::iterator it;
		it = guia.find(nombre);
		if (it == guia.end()){
			guia.insert(pair <string, string> (nombre, numero));				//Si el usuario no existe, se crea
			return;
		}
		it->second = numero;													//si el usuario existe, se modifica su numero telefonica
	}

	void eliminarEntrada(const string nombre){
		map<string,string>::iterator it;
		it = guia.find(nombre);
		if (it == guia.end()){													//si el usuario no existe, no se modifica
			cout << "Usuario no existente" << endl;
			return;
		}
		cout << "Eliminando a: " << nombre << endl;
		guia.erase(nombre);														//se elimina al usuario
	}

	void mostrarGuia(){
		map<string,string>::iterator it;
		cout << "La guia telefonica es: " << endl;
		for (it = guia.begin(); it != guia.end(); ++it)
			cout << it->first << " " << it->second << endl;						//se itera en el mapa para imprimir la guia
	}
};


int main(){
	GuiaTelefonos a;
	a.mostrarGuia();
	a.insertarEntrada("Alfredo", "1234567");
	a.insertarEntrada("Crack", "12344566");
	a.insertarEntrada("Ale", "122353452");
	a.modificarEntrada("Alfredo", "09089080");
	a.buscarEntrada("djsalkfj");
	a.eliminarEntrada("Crack");
	a.mostrarGuia();
}