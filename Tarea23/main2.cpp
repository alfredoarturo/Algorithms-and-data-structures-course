#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct CompareByFirst {
    bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b)
    { return a.first > b.first; }
};

pair<int, int> caso(map <pair<int,int>,int> datos, int *p, int a, int b){
	priority_queue<pair<int, int>, vector<pair<int, int>>, CompareByFirst > cola;
	int q, s, r;
	map <pair<int,int>,int>::iterator uno, dos;
	for (int i = a; i < b; ++i){
		uno = datos.find(make_pair(a, i));
		if (uno == datos.end()){
			cout << "algo salio mal" << endl;
		}
		dos = datos.find(make_pair(i+1, b));
		if (dos == datos.end()){
			cout << "algo salio mal" << endl;
		}
		s = uno->second;
		q = dos->second;
		r = p[a-1]*p[i]*p[b];
		cola.push(make_pair(s+q+r, i));
	}
	return cola.top();
}

int main(){
	int *p, tam, Ncasos;
	map <pair<int,int>,int> datos, camino;
	map <pair<int,int>,int>::iterator it, it2;
	pair <int, int> aux;

	cin >> Ncasos;
	for (int i = 0; i < Ncasos; ++i){
		cin >> tam;
		p = new int[tam];
		for (int j = 0; j < tam; ++j){
			cin >> p[j];
			datos.insert(make_pair(make_pair(j, j), 0));
			camino.insert(make_pair(make_pair(j, j), 0));
		}

		for (int i = 1; i < tam-1; ++i){
			for (int j = 0; i + j < tam; ++j){
				aux = caso(datos, p, j, j+i);
				datos.insert(make_pair(make_pair(j, j+i), aux.first));
				camino.insert(make_pair(make_pair(j, j+i), aux.second));
			}
		}
		
		it = datos.find(make_pair(1, tam-1));
		if (it != datos.end())
			cout << it->second << endl;
		else{
			cout << "error" << endl;
			return 1;
		}

		it = camino.find(make_pair(1, tam-1));
		it2 = it;
		while (it->second != 0){
			it = camino.find(make_pair(1, it->second));
			cout << it->second << " ";
		}
		cout << it2->second;
		while(it2->second != 0){
			it2 = camino.find(make_pair(it2->second + 1, tam-1));
			cout << " " << it2->second;
		}
		cout << endl;
	}
	return 0;
}