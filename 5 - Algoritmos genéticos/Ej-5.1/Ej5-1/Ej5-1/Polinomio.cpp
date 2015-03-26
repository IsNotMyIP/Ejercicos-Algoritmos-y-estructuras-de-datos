#include "Polinomio.h"


Polinomio::Polinomio(){

}

Polinomio::Polinomio(int grado, float* coeficiente){
	this->grado = grado;
	this->coeficientes = coeficiente;
}

float Polinomio::evaluar(float x){
	float resultado =0;
	for (int i = 0; i <= this->grado; i++){
		resultado += this->coeficientes[i] * x; 
	}
	return resultado;
}

float Polinomio::obtenerMaximo(){
	return 0;
}

Polinomio::~Polinomio(){

}