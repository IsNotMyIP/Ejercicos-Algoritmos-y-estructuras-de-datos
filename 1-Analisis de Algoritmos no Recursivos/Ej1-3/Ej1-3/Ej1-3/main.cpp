#include "VectorInt.h"
#include <iostream>
#include <time.h>

using namespace std;

void escribirVector(int* vector, int size);
int checkInts(const void *a, const void *b);


int main(){
	//Pedimos el numero de elementos del array.
	int arrSize;
	cout << "Introduce numero de elementos del array: ";
	cin >> arrSize;
	
	//Lo creamos y lo escribimos.
	VectorInt a(arrSize);
	escribirVector(a.getInicio(), arrSize);

	//creamos una copia para ordenarlo con otro metodo.
	VectorInt b(a);

	cout << endl << endl;

	//Medimos tiempos y ordenamos de manera ineficiente.
	unsigned long int clicksInicio = clock();
	a.ordenadoChungo();
	unsigned long int clicksFinal = clock();

	//Imprimimos el resultado
	cout << "El vector ordenado de manera ineficiente: " << endl;
	escribirVector(a.getInicio(), arrSize);
	
	//Calculamos el tiempo total y lo imprimimos.
	float segundos = ((float)(clicksFinal - clicksInicio)) / CLOCKS_PER_SEC;
	printf("El metodo ineficiento ha tardado %.5f segundos en ordenarse\n\n", segundos);
	
	//Ordenamos y medimos los clocks, usando qsort esta vez.
	clicksInicio = clock();
	qsort(b.getInicio(), b.getSize(), sizeof(int), checkInts);
	clicksFinal = clock();

	//Imprimimos por pantalla el resultado
	cout << "Vector ordenado mediante qsort: " << endl;
	escribirVector(b.getInicio(), arrSize);

	//Calculamos los segundos y los mostramos por pantalla.
	segundos = ((float)(clicksFinal - clicksInicio)) / CLOCKS_PER_SEC;
	printf("El metodo qsort ha tardado %.5f segundos en ordenarse\n", segundos);
	return 0;
}

int checkInts(const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}
void escribirVector(int* vector, int size){
	if (size < 10)
		for (int i = 0; i < size; i++){
			cout << vector[i] << endl;
		}
	else
		cout << "Array demasiado largo para ordenar" << endl;
}