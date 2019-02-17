#include <iostream>

using namespace std;

int cambio(int k, int Nmonedas, int *monedas, int* mins, int* cams){
	if (k <= 0)																	//Caso base
		return 0;
	if (mins[k-1] != -1)
		return mins[k-1];														//Se regresa un caso ya calculado que se guardó en memoria
	int min = cambio(k-monedas[0], Nmonedas, monedas, mins, cams) + 1;
	int cam = monedas[0];
	int aux;
	for (int i = 1; i < Nmonedas; ++i){											//Se calcula el minimo, dependiendo que que monedas se tomen
		if (k-monedas[i] < 0)
			continue;
		aux = cambio(k-monedas[i], Nmonedas, monedas, mins, cams) + 1;
		if (min > aux){
			min = aux;
			cam = monedas[i];
		}
	}
	mins[k-1] = min;															//se guarda el mínimo en memoria
	cams[k-1] = cam;															//Se guarda la moneda usada en este caso
	return min;
}

void imprimir_cambio(int k, int *cams){
	int aux = k;
	while (aux > 0){
		cout << cams[aux-1] << " ";												//imprime la moneda y luego las monedas usadas en los casos mas pequeños
		aux -= cams[aux-1];
	}
}

int main(){
	int Nmonedas = 8;
	int monedas[Nmonedas] = {1, 5, 9, 12, 28, 52, 91, 365};
	int k;
	int *mins, *cams;

	cin >> k;

	mins = new int[k];
	cams = new int[k];

	for (int i = 0; i < k; ++i){
		mins[i] = -1;
		cams[i] = -1;
	}

	cout << cambio(k, Nmonedas, monedas, mins, cams) << endl;

	imprimir_cambio(k, cams);
	cout << endl;
}