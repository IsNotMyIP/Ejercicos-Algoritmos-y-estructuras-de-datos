#include "VectorInt.h"

#include <assert.h>
#include <cstdlib>
#include <time.h>
#include <cstring>

VectorInt::VectorInt(){
	//EMPTY
}
VectorInt::VectorInt(int size){
	//Como minimo el vector ha de tener un size de 1.
	assert(size > 0);

	//Reservamos memoria.
	this->inicio = (int*) malloc(size * sizeof(int));
	this->size = size;

	//Generamos numeros aleatorios
	srand(time(NULL));
	for (int i = 0; i < size; i++){
		this->inicio[i] = rand();
	}

}
VectorInt::VectorInt(const VectorInt &a){
	//Asignamos los elementos.
	this->size = a.size;

	//REservamos memoria.
	this->inicio = (int*)malloc(this->size * sizeof(int));

	//Copiamos memoria de a al nuevo vector.
	memcpy(this->inicio, a.inicio, this->size * sizeof(int));

}

void VectorInt::ordenadoChungo(){
	//Vamos a recorrer el array, buscaremos el valor minimo y lo pondremos en la posicion correcta.
	for (int i = 0; i < this->size; i++){
		int posMinimum = findMinimum(i, this->size - 1);

		//Intercambiamos los valores
		int aux;
		aux = this->inicio[i];
		this->inicio[i] = this->inicio[posMinimum];
		this->inicio[posMinimum] = aux;

	}
}


int VectorInt::getSize(){
	return this->size;
}
int* VectorInt::getInicio(){
	return this->inicio;
}
int VectorInt::findMinimum(int start, int finish){
	int minimo = this->inicio[start];
	int minimPos = start;
	for (; start < finish +1; start++){
		if (this->inicio[start] < minimo){
			minimo = this->inicio[start];
			minimPos = start;
		}
	}
	return minimPos;
}
VectorInt::~VectorInt(){
	free(this->inicio);
}