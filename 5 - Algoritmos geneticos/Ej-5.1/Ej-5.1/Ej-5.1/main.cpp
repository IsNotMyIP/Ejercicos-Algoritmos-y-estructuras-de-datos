#include "Polinomio.h"
#include "iostream"
#include <ctime>

using namespace std;
int main(){
	srand(time(NULL));
	int grado;
	float *coeficientes = NULL;

	cout << "Grado del polinomio (mayor que 0): ";
	cin >> grado;
	cout << endl;

	coeficientes = new float[grado + 1];
	cout << grado + 1 << " coeficientes del polinomio separados por espacio: ";
	for (int i; i <= grado; i++){
		cin >> coeficientes[i];
	}
	cout << endl;

	Polinomio p(grado, coeficientes);
	for (int i = 0; i < 10; i++){
		cout << "Maximo de " << i << ": " << p.obtenerMaximo() << endl;
	}
	return 0;
}