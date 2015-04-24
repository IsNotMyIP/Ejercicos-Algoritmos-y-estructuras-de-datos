#include "iostream"
#include "ListaEnlazada.h"
#include "cstdlib" // Para srand y rand
#include "ctime" // Para time()
#include "BibliotecaImpresionListasEnlazadas.h"

using namespace std;


void main () {

	ListaEnlazada lista; // Lista con la que haremos las pruebas
	int n; // Tama�o de la lista

	srand(time(NULL));

	cout << "Introduce el numero de elementos de la lista: ";
	cin >> n;

	// Llenamos la lista con numeros aleatorios entre 20 y 40 e imprimimos
	for (int i=0; i<n; i++) lista.insertar(lista.getN(), Elemento((float)(rand()%21 + 20)));
	cout << "Lista sin ordenar: " << lista << endl;

	// Ordenamos e imprimimos
	lista.ordenar();
	cout << "Lista ordenada con MergeSort: " << lista << endl;
}

