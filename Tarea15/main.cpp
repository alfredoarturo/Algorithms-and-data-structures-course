#include <iostream>

using namespace std;
template <class T>
class Tree{
private:
	Tree<T> *l;
	Tree<T> *r;
	T item;
public:
	Tree(){
		l = NULL;
		r = NULL;
		item = 0;
	}
	Tree(T uno, T dos){
		l = NULL;
		r = NULL;
		item = 0;
	}
	Tree<T> *get_r(){ return r; }
	Tree<T> *get_l(){ return l; }
	T get_item() { return item; }
	T *dato_raiz() { return &item; }
	void colapsa(Tree<T> &uno, Tree<T> &dos){
		r = &uno;
		l = &dos;
	}
};

int main () {
Tree <int> myobject (20, 30);
Tree <int> a (20, 30);
Tree <int> b (20, 30);
cout << myobject.dato_raiz() << endl;
cout << myobject.get_r() << endl;
cout << myobject.get_l() << endl;
myobject.colapsa(a,b);
cout << myobject.get_r() << endl;
cout << myobject.get_l() << endl;
return 0;
}

