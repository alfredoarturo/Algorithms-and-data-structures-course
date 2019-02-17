#include <iostream>
#include <map>

using namespace std;

template<class t>
class MatrizRala{
	private:
		map<pair <int, int>, t> *mapa;
	public:
		int ren, col;
		MatrizRala(){
			mapa = new map<pair <int, int>, t>;
			ren = 0;
			col = 0;
		}

		MatrizRala(int rens, int cols){
			mapa = new map<pair <int, int>, t>;
			ren = rens;
			col = cols;
		}

		void insertar(t elemento, int x, int y){							//se usa para insertar elementos en la posicion (x,y)

			if (x >= col || y >= col){
				cout << "Se sobrepasan los límites" << endl;
				return;
			}

			if (elemento == 0){
				typename map<pair<int,int> , t>::iterator it;
				it = mapa->find(pair<int, int>(x, y));
				if (it != mapa->end())
					mapa->erase(it);
				return;
			}
			mapa->insert(pair< pair <int,int>,t > ( pair<int, int>(x, y), elemento) );
		}

		t get_val(int x, int y){
			typename map< pair<int, int>, t>::iterator it;
			it = mapa->find(pair<int, t> (x, y));					//Se busca el elemento
			if (it != mapa->end())
				return it->second;									//Si no se encuentra es un cero por definicion
			else
				return 0;
		}

		void imprimir(){
			map< pair<int, int>, int>::iterator it;
			for (it = mapa->begin(); it != mapa->end(); ++it)
				cout << it->second << endl;
		}

		~MatrizRala(){
			delete mapa;
		}
};

template<typename t>
MatrizRala<t>* operator+(MatrizRala<t>& uno, MatrizRala<t>& dos){
	int r, c;												//Renglones y columnas de la nueva matriz
	if (uno.ren > dos.ren)										//Se fijan los renglones como la mayor de las dos y analogamente con las columnas
		r = uno.ren;
	else
		r = dos.ren;
	if (uno.col > dos.col)
		c = uno.col;
	else
		c = dos.col;
	MatrizRala<t> *suma = new MatrizRala<t>(r, c);
	for (int i = 0; i < c; ++i){
		for (int j = 0; j < r; ++j){
			suma->insertar(uno.get_val(i, j)+dos.get_val(i, j), i, j);	//Se hace la suma entrada por entrada
		}
	}
	return suma;
}

int main(){
	MatrizRala<int> *a = new MatrizRala<int>(10, 20);					//Matriz de 10x20, se usa template int.
	a->insertar(10, 10, 5);												//Muestra de insertar en la matriz
	a->insertar(3, 10, 4);
	a->insertar(10, 10, 30);
	cout << "Matriz a:" << endl;
	a->imprimir();
	a->insertar(0, 10, 5);
	cout << "Se insertó cero en a" << endl;
	a->imprimir();
	MatrizRala<int> *b = new MatrizRala<int>(20, 30);
	b->insertar(7, 10, 4);
	b->insertar(4, 5, 6);
	cout << "Matriz b:" << endl;
	b->imprimir();
	MatrizRala<int> *c;
	c = (*a) + (*b);
	cout << "Matriz c = a+b:" << endl;
	c->imprimir();

	delete a;
	delete b;
	delete c;
}