#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef struct a{
	int x, y, conex;
	bool visitado;
} CIUDAD;

void init_ciudad(CIUDAD *c){			//inicializa una ciudad en una ubicación aleatoria, que no ha sido visitada, ni tiene una conexion
	c->x = rand() % 10;
	c->y = rand() % 10;
	c->visitado = false;
	c->conex = 0;
}

CIUDAD *crear_mundo(int tamano){		//crea un vector de n ciudades
	CIUDAD *mundo = new CIUDAD[tamano];
	for (int i = 0; i < tamano; ++i)
		init_ciudad(mundo + i);
	return mundo;
}

void destruir_mundo(CIUDAD *c){			//libera la memoria del mundo
	delete [] c;
}

int *estado_ciudades(int tamano){		//crea un vector que tiene el estado de cada ciudad
	int *c = new int[tamano];
	for (int i = 0; i < tamano; ++i)
		c[i] = 0;
	return c;
}

int seleccionar_ciudad(int *ciudades_libres, int tamano, int libres, int actual){	//elige una ciudad para hacer una conexion
	int cont = -1, Nciudad = (rand() % libres);
	for (int i = 0; i < tamano; ++i){
		if (cont == Nciudad && actual != i && ciudades_libres[i] != 1){
			ciudades_libres[i] = 1;
			return i;
		}
		if (cont == Nciudad && actual == i && ciudades_libres[i] != 1)
			continue;
		if (ciudades_libres[i] != 1)
			cont ++;
	}
	return -1;
}

void crear_conex(CIUDAD *c, int sig_ciudad){	//hace que una ciudad se conecte con la otra
	c->visitado = true;
	c->conex = sig_ciudad;
}

void limpiar_visitas(CIUDAD *c, int tamano){
	for (int i = 0; i< tamano; ++i)
		c[i].conex = 0;
}

void copiar_ciudad(CIUDAD *recibe, CIUDAD *copiada){
	recibe->x = copiada->x;
	recibe->y = copiada->y;
}

void ordenar_x(CIUDAD *c, int tamano){
	if (tamano == 1)
		return;
	CIUDAD aux;
	copiar_ciudad(&aux, c);
	for (int i = 1; i < tamano; ++i){
		if (c[i].x < aux.x){
			copiar_ciudad(c, c+i);
			copiar_ciudad(c+i, &aux);
			copiar_ciudad(&aux, c);
		}
	}
	ordenar_x(c+1, tamano-1);
}

void conectar_ordenado(CIUDAD *c, int tamano){
	limpiar_visitas(c, tamano);
	ordenar_x(c, tamano);
	for (int i = 0; i < tamano-1; ++i)
		crear_conex(c+i, i+1);
}

void conectar(CIUDAD *c, int tamano){		//conecta una ciudad con otra
	int ciudad = 0, aux = 0,  *libres = estado_ciudades(tamano);
	CIUDAD *ap;
	for (int i = 0; i < tamano-1; ++i){
		ap = c + aux;
		ciudad = seleccionar_ciudad(libres,tamano, tamano-i-1, aux);
		crear_conex(ap, ciudad);
		aux = ciudad;
	}
	delete [] libres;
}

void imprimir(CIUDAD *c, int tamano){
	for (int i = 0; i<tamano; ++i){
		cout << "x, y: " << c[i].x << " " << c[i].y <<  " va a " << c[c[i].conex].x << ", " << c[c[i].conex].y << endl;
	}
}

double distancia(CIUDAD *c){
	double dis = 0;
	int i = 0;
	while(c[i].conex != 0){
		dis += sqrt(pow((c[i].x-c[c[i].conex].x), 2)+pow((c[i].y-c[c[i].conex].y), 2));
		i = c[i].conex;
	}
	dis += sqrt(pow((c[i].x-c[c[i].conex].x), 2)+pow((c[i].y-c[c[i].conex].y), 2));
	return dis;
}

void run(int tamano){
	CIUDAD *mundo = crear_mundo(tamano);
	cout << "Random" << endl;
	conectar(mundo, tamano);
//	imprimir(mundo, tamano);
	cout << "La disancia fue: " << distancia(mundo) << endl << endl;
	cout << "Ordenado" << endl;
	conectar_ordenado(mundo, tamano);
//	imprimir(mundo, tamano);
	cout << "La distancia fue: " << distancia(mundo) << endl;
	destruir_mundo(mundo);
}

int main(){
	srand(time(NULL));
	run(100000);
}
