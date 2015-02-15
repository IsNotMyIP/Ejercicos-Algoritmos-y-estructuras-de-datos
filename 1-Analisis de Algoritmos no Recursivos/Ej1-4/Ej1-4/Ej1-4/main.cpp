#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;


//Ordenamos vector por insercion
// Parametros:
//	-inicio, puntero int, inicio del array.
//	- n, int, numero de elementos.
// vector!= 0 && n>0
void ordenarInsercion(int *inicio, int n);

void imprimirArray(int *inicio, int n);

int esMenorQue(const void *numero1, const void *numero2);

int esMayorQue(const void *numero1, const void *numero2);

int main() {
	//Declaramos las variables a usar.
	int n; //Numero de elementos del array.
	int nArraysMedia; //Numero de arrays para la media
	long int numeroClicksInicio, numeroClicksFin; //Para medir el tiempo.
	float tiempoSeg; //Tiempo invertido en la ordenacionS

	srand(time(NULL)); //Inicializamos la semilla de rand.

	cout << "Elementos del array, mayor a 0: ";
	cin >> n;

	cout << "Numero de arrays para la media, mayor a 0: ";
	cin >> nArraysMedia;
	

	//Declaramos los arrays de arrays para el caso medio, tanto qSort como insercion
	int **arraysParaMediaInsercion = (int**)malloc(nArraysMedia * sizeof(int*));
	int **arraysParaMediaQsort = (int**)malloc(nArraysMedia * sizeof(int*));

	//Llenamos los arrays y reservamos la memoria de manera igual para las dos listas
	for (int i = 0; i < nArraysMedia; i++){
		arraysParaMediaInsercion[i] = (int*)malloc(n*sizeof(int));
		arraysParaMediaQsort[i] = (int*)malloc(n*sizeof(int));

		for (int j = 0; j < nArraysMedia; j++){
			arraysParaMediaInsercion[i][j] = arraysParaMediaQsort[i][j] = rand();
		}
	}
	
	//Arrays para el MEJOR caso.
	int *arraysParaMejorInsercion = (int*) malloc(n*sizeof(int));
	int *arraysParaMejorQsort = (int*)malloc(n*sizeof(int));
	//Rellenamos uno.
	for (int i = 0; i < n; i++){
		arraysParaMejorInsercion[i] = rand();
	}
	//Lo ordenamos, dado que es para el mejor caso, de menor a mayor.
	qsort(arraysParaMejorInsercion, n ,sizeof(int), esMenorQue);
	// Y copiamos el array.
	for (int i = 0; i < n; i++){
		arraysParaMejorQsort[i] = arraysParaMejorInsercion[i];
	}

	//Arrays para el PEOR caso.
	int *arraysParaPeorInsercion = (int*)malloc(n*sizeof(int));
	int *arraysParaPeorQsort = (int*)malloc(n*sizeof(int));
	//Rellanamos uno
	for (int i = 0; i < n; i++) {
		arraysParaPeorInsercion[i] = rand();
	}
	//Lo ordenamos de mayor a menor, PEOR caso.
	qsort(arraysParaPeorInsercion, n, sizeof(int), esMayorQue);
	//Copiamos para el otro array.
	for (int i = 0; i < n; i++){
		arraysParaPeorQsort[i] = arraysParaPeorInsercion[i];
	}

	//Imprimimos por pantalla
	cout << endl << "Array caso mejor: " << endl;
	imprimirArray(arraysParaMejorInsercion, n);
	cout << endl << "Array caso peor: " << endl;
	imprimirArray(arraysParaPeorInsercion, n);
	cout << endl << "Arrays caso medio: " << endl;
	for (int i = 0; i < nArraysMedia; i++){
		cout << '\t';
		imprimirArray(arraysParaMediaInsercion[i], n);
		cout << endl;
	}
	
	//Comenzamos a calcular tiempos.
	//MEJOR
	cout << "\nTiempos para el caso mejor:\n   ";
	numeroClicksInicio = clock();
	ordenarInsercion(arraysParaMejorInsercion, n);
	numeroClicksFin = clock();
	tiempoSeg = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC;
	printf("Insercion: %.3f segundos\n   ", tiempoSeg);
	numeroClicksInicio = clock();
	qsort(arraysParaMejorQsort, n, sizeof(int), esMenorQue);
	numeroClicksFin = clock();
	tiempoSeg = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC;
	printf("QuickSort: %.3f segundos", tiempoSeg);

	//PEOR
	cout << "\nTiempos para el caso peor:\n   ";
	numeroClicksInicio = clock();
	ordenarInsercion(arraysParaPeorInsercion, n);
	numeroClicksFin = clock();
	tiempoSeg = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC;
	printf("Insercion: %.3f segundos\n   ", tiempoSeg);
	numeroClicksInicio = clock();
	qsort(arraysParaPeorQsort, n, sizeof(int), esMenorQue);
	numeroClicksFin = clock();
	tiempoSeg = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC;
	printf("QuickSort: %.3f segundos", tiempoSeg);

	//MEDIO
	cout << "\nTiempos para el caso medio:\n   ";
	numeroClicksInicio = clock();
	for (int i = 0; i < nArraysMedia; i++) {
		ordenarInsercion(arraysParaMediaInsercion[i], n);
	}
	numeroClicksFin = clock();
	tiempoSeg = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC;
	printf("Insercion: %.3f segundos (de media)\n   ", tiempoSeg / nArraysMedia);
	numeroClicksInicio = clock();
	for (int i = 0; i < nArraysMedia; i++) {
		qsort(arraysParaMediaInsercion[i], n, sizeof(int), esMenorQue);
	}
	numeroClicksFin = clock();
	tiempoSeg = ((float)(numeroClicksFin - numeroClicksInicio)) / CLOCKS_PER_SEC;
	printf("QuickSort: %.3f segundos (de media)\n", tiempoSeg / nArraysMedia);


	return 0;
	}

	void ordenarInsercion(int *vector, int n) {
		assert(vector != NULL);
		assert(n >= 1);

		int posicion = 0; // Posición del vector en la cual todas las posiciones menores están ordenadas
		int posicionHueco = 0; // Posición del hueco en donde insertar en cada momento
		int elemento; // Elemento que estamos colocando en su sitio

		// Por cada elemento, buscamos el lugar, previo a él, en donde debería ir
		// Empezamos en el elemento de la posicion 1 porque el elemento de la posicion 0 no tiene lugares previos
		// en donde lo podamos insertar (pues la posición 0 es la primera)
		for (posicion = 1; posicion <= n - 1; posicion++) {

			elemento = vector[posicion]; // Guardamos el elemento que queremos recolocar
			posicionHueco = posicion - 1; // El primer hueco en donde evaluar si colocamos el elemento está en la posición inmediatamente anterior

			// Buscamos el lugar en donde insertar el elemento. 
			while (posicionHueco >= 0 && elemento < vector[posicionHueco]) {
				vector[posicionHueco + 1] = vector[posicionHueco]; // Creamos un hueco copiando su conteniendo a su celda de la derecha
				posicionHueco--;
			}

			vector[posicionHueco + 1] = elemento; // Finalmente, copiamos el elemento al hueco adecuado encontrado
		}
	}

	void imprimirArray(int *vector, int n) {
		assert(vector != NULL);
		assert(n >= 1);
		if (n <= 10)
			for (int i = 0; i<n; i++) cout << vector[i] << " ";
		else
			cout << "<demasiados componentes para mostrar>";
	}


	int esMenorQue(const void *numero1, const void *numero2) {
		assert(numero1 != NULL && numero2 != NULL);
		int *punteroNumero1 = (int*)numero1; // Puntero a entero del primer número
		int *punteroNumero2 = (int*)numero2; // Puntero a entero del segundo número
		return (*punteroNumero1 - *punteroNumero2);
	}

	int esMayorQue(const void *numero1, const void *numero2) {
		assert(numero1 != NULL && numero2 != NULL);
		int *punteroNumero1 = (int*)numero1; // Puntero a entero del primer número
		int *punteroNumero2 = (int*)numero2; // Puntero a entero del segundo número
		return (*punteroNumero2 - *punteroNumero1);
	}

