#include "Racional.h"
#include "iostream" 
#include "cassert" //Para los controladores
using namespace std;

Racional::Racional(){
	//Empty
}

Racional::Racional(int num, int denom){
	assert(denom != 0);

	//Comprobamos el signo y se lo damos al numerador 
	//para facilitar las operaciones.
	if (denom < 0) {
		num = -num;
		denom = -denom;
	}
	//Se lo servimos al obj.
	this->numerador = num;
	this->denominador = denom;
}

int Racional::getDenominador(){
	return this->denominador;
}

int Racional::getNumerador(){
	return this->numerador;
}

Racional Racional::sumar(Racional sumando){
	//Comprobamos que los denom son correctos.
	assert(this->denominador > 0);
	//?? getDenominador ???//
	assert(sumando.denominador);

	//Calculamos nuevo denominador
	int newDenom = this->denominador * sumando.denominador;
	//Calculamos nuevo numerador
	int newNum = (this->numerador * sumando.numerador) + (sumando.numerador * this->denominador);
	
	//Creamos el obj y lo devolvemos
	Racional result(newNum, newDenom);
	return(result);
}

Racional Racional::multiplicar(Racional operando){
	//Calculamos numerador y denominador
	int newNumerador = this->numerador * operando.numerador;		//Could be better to use a getter
	int newDenominador = this->denominador * operando.denominador;	//Could be better to use a getter
	
	//Devolvemos el Racional 
	Racional result(newNumerador, newDenominador);
	return result;
}

int Racional::calcularMCD(int p1, int p2){
	// Hacemos un control de errores
	assert(p1 > 0);
	assert(p2 > 0);

	int aux; //Variable de apoyo y retornada.

	//Realizamos el calculo en bucle.
	while (p1 != p2){
		if (p1 > p2){
			p1 = p1 - p2;
		}
		else{
			p2 = p2 - p1;
		}
		aux = p1;
	}
	return aux;
}

void Racional::simplificar(){
	// Control de errores.
	assert(this->denominador > 0);

	int MCD = calcularMCD(this->numerador, this->denominador);
	this->denominador = this->denominador / MCD;
	this->numerador = this->numerador / MCD;

}