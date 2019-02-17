#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct point{
	float x;
	float y;
	point (){
		x = 0;
		y = 0;
	}
};

struct rectangulo{
	float x_max, x_min;
	float y_max, y_min;
	rectangulo(float u, float v, float w, float x){
		x_max = u;
		x_min = v;
		y_max = w;
		y_min = x;
	}
};

typedef point PUNTO;
typedef rectangulo REC;

PUNTO *vec_puntos(int tam){
	PUNTO *vec = new PUNTO[tam];
	return vec;
}

void eliminar_vec(PUNTO *vec){
	delete [] vec;
}

float rand_float(){
	float a;
	a = (float)rand()/RAND_MAX;
	a += rand();
	return a;
}

void llenar_vec(PUNTO *vec, int tam){
	for (int i = 0; i < tam; ++i){
		vec[i].x = rand_float();
		vec[i].y = rand_float();
	}
}

void imprimir_vec(PUNTO *vec, int tam){
	for (int i = 0; i < tam; ++i)
		cout << "( " << vec[i].x << " , " << vec[i].y << " )" << endl;
}

REC rec( PUNTO *vec, int tam){
	float x_max = vec[0].x, x_min = vec[0].x, y_max = vec[0].y, y_min = vec[0].y;
	for (int i = 1; i < tam; ++i){
		if (vec[i].x < x_min)
			x_min = vec[i].x;
		else if (vec[i].x > x_max)
			x_max = vec[i].x;
		if (vec[i].y < y_min)
			y_min = vec[i].y;
		else if (vec[i].y > y_max)
			y_max = vec[i].y;
	}
	REC *r = new rectangulo(x_max, x_min, y_max, y_min);
	return *r;
}

int main(int narg, char *args[]){
	int N;
	if (narg < 2){
		cout << "Error, ingrese los parametros indicados" << endl;
		return 1;
	}

	N = atoi(args[1]);

	srand(time(NULL));

	PUNTO *vec = vec_puntos(N);
	llenar_vec(vec, N);
	REC a = rec(vec, N);
	imprimir_vec(vec, N);
	cout << "(" << a.x_min << " , " << a.y_max << ")" << endl;
	cout << "(" << a.x_min << " , " << a.y_min << ")" << endl;
	cout << "(" << a.x_max << " , " << a.y_min << ")" << endl;
	cout << "(" << a.x_max << " , " << a.y_max << ")" << endl;
	eliminar_vec(vec);
}
