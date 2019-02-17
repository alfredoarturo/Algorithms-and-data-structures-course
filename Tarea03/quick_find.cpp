#include <iostream>
using namespace std;


static const int N = 10000;

typedef struct a{
	int uno;
	int dos;
} pareja;

pareja aleatorios(){
	pareja a;
	a.uno = rand() % N;
	a.dos = rand() % N;
	return a;
}

int main() {
	int i, p, q, id[N];
	for (i = 0; i < N; ++i)  //initialization
		id[i] = i;
	while ( cin >> p >> q ){
		int t = id[p];
		if (t == id[q]) continue;  //quick find
		for ( i = 0; i < N; ++i)  //union
			if (id[i] == t) id[i] = id[q];
		cout << " " << p << " " << q << endl;
	}
	return 0;
}
