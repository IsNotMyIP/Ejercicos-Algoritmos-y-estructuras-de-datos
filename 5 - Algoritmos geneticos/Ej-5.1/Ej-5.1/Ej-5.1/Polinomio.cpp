#include "Polinomio.h"
#include "SolucionParcial.h"
#include <cstdlib> // malloc
#include <cstring> // memcpy
#include <math.h>  // pow

Polinomio::Polinomio(int grado, float* coeficiente){
	this->grado = grado;
	this->coeficientes = (float*)malloc((grado + 1) * sizeof(float));
	memcpy(this->coeficientes, coeficiente, (grado + 1) * sizeof(float)); // Porque copiamos esa longitud? si coeficiente sera de size n no n+1
}


float Polinomio::evaluar(float x){
	float resultado = 0;
	for (int i = 0; i <= this->grado; i++){
		resultado += coeficientes[i] * pow(x, i);
	}
	return resultado;
}

float Polinomio::aleatorioNormalestandar(){
	float suma = 0;
	for (int i = 0; i < 12; i++){
		suma += rand() / (float)RAND_MAX;
	}
	return (suma - 6);
}
float Polinomio::obtenerMaximo(){
	SolucionParcial first(0, evaluar(0));
	return (obtenerMaximo(first));
}
float Polinomio::obtenerMaximo(SolucionParcial padre){
	int nHijos = 3 + rand() % 3; //srand se inicializa en main.cpp
	SolucionParcial bestSon = padre;
	//Imprimimos el padre del que partimos.
	padre.imprimir();
	printf(":");

	//Buscamos el mejor hijo.
	for (int i = 0; i < nHijos; i++){
		SolucionParcial hijo;
		//calculamos hijo
		hijo.x = padre.x + aleatorioNormalestandar();
		hijo.y = evaluar(hijo.y);

		//Imprimimos el hijo
		hijo.imprimir();
		printf(", ");
		
		if (hijo.y > padre.y) bestSon = hijo;
	}
	cout << endl;

	if (bestSon.y > padre.y) return obtenerMaximo(bestSon);
	else{ return padre.x; };
	return 0;
}
Polinomio::~Polinomio(){
	free(coeficientes);
}