#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

bool usada[70];
int cam[70];

template <typename Item>
void exch( Item &A, Item &B){
	Item t = A;
	A = B;
	B = t;
}

template <typename Item>
int partition( pair<int, Item> *a, int l, int r){
	int i = l-1;
	int j = r;
	pair<int, Item> v = a[r];
	for (;;){
		while( a[++i].second < v.second);
		while( v.second < a[--j].second)
			if ( j == i)
				break;
		if ( i >=j)
			break;
		exch<pair<int, Item>>(a[i], a[j]);
	}
	exch<pair<int, Item>> ( a[i], a[r] );
	return i;
}

template <typename Item>
void quickSort (pair<int, Item> a[], int l, int r){
	if (r <= l) return;
	int i = partition<Item> (a, l, r);
	quickSort<Item> (a, l, i-1);
	quickSort<Item> (a, i+1, r);
}

template <typename t>
pair <int, t> *init(int N){
	pair<int, t> *vec = new pair <int, t>[N];
	for (int i = 0; i < N; ++i){
		vec[i].first = 0;
		vec[i].second = 0;
	}
	return vec;
}

template <typename t>
pair <int, t> *init_rand(int N){
	pair<int, t> *vec = new pair <int, t>[N];
	for (int i = 0; i < N; ++i){
		vec[i].first = rand() % 10000;
		vec[i].second = rand() % 10000;
		usada[i] = false;
		cam[i] = -1;
	}
	return vec;
}

 void distancias(int N, pair<int, int> *ciudades, pair<int, int> actual, pair<int, double> *mem){
	int j = 0;
	for (int i = 0; i < N; ++i){
		while(usada[j] == true){
			++j;
		}
		mem[i].second = sqrt(pow((actual.first-ciudades[j].first), 2) + pow((actual.second-ciudades[j].second), 2));
		mem[i].first = j;
		++j;
	}
}

void viaje(int N, pair<int, int> *ciudades){
	pair<int, int> actual = ciudades[0];
	pair<int, double> *dist;
	usada[0] = true;
	--N;
	dist = init<double>(N);
	distancias(N, ciudades, actual, dist);
	quickSort<double>(dist, 0, N);
	cam[0] = 0;
	int j = 1;
	while(N > 0){
		actual = ciudades[dist[0].first];
		usada[dist[0].first] = true;
		dist = init<double>(N);
		distancias(N, ciudades, actual, dist);
		quickSort<double>(dist, 0, N);
		--N;
		cam[j] = dist[0].first;
		++j;
	}
}

double distancia(pair<int, int> ciudad1, pair<int, int> ciudad2){
	return sqrt(pow(ciudad1.first - ciudad2.first, 2)+pow(ciudad1.second -ciudad2.second, 2));
}

int main(){
	srand(time(NULL));
	pair <int, int> *ciudades = init_rand<int>(70);
	viaje(70, ciudades);
	double dist = 0;
	cout << "El camino a seguir es: " << endl;
	for (int i = 0; i < 70; ++i){
		cout << '(' << ciudades[cam[i]].first << ", " << ciudades[cam[i]].second << ')' << endl;
		dist += distancia(ciudades[(cam[i%70])], ciudades[(cam[(i+1)%70])]);
	}
	cout << "La distancia recorrida fue: " << dist << endl;
	cout << endl;
	
}