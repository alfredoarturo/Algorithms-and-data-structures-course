#include <iostream>

using namespace std;

int letras(char *w){
	int l = 0;
	while (w[l] != '\0')
		++l;
	return l;
}

void permuta(char *w, char *fin, int longitud, int pos){
	if (pos = longitud-1){
		fin[longitud-1] = *w
		for (int i = 0; i < longitud; ++i)
			cout << fin[i] << endl;
		return;
	}
	char *aux = new char [longitud-1];
	int j = pos, q = pos;
	for (int i = 0; i < longitud-pos; ++i){
		j = pos; q = pos;
		while (j < longitud-1-pos){
			if (i == q){
				++q;
				continue;
			}
			fin[j] = w[q];
			++j;
			++q;
		}
		permuta(aux, longitud-1);
	}
}

int main(){
	char *a = new char[5];
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	a[3] = '\0';
	cout << a << endl;
	cout << "permutando" << endl;
	cout << "longitud: " << letras(a) << endl;
	permuta(a, letras(a));
	return 0;
}
