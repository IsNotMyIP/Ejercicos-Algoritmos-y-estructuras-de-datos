#include "Pila.h"

Pila::Pila() : ListaEnlazada(){

}

Pila::Pila(float insert) : ListaEnlazada(){
	insertar(this->getN(), Elemento(insert)); // Same as the other one but with an insert of the element
}

void Pila::push(float insert){
	insertar(this->getN(), Elemento(insert)); // Simple "insertar", first parammeter will always be N because is a Pile
}
float Pila::pop(){
	float aDevolver;								// Saving a value for returning it later
	aDevolver = this->getValor(getN() - 1).get();	// Defining adevolver
	this->eliminar(getN() - 1);						// deleting aDevolver
	return aDevolver;
}

float Pila::verCima(){
	float aDevolver;
	aDevolver = this->getValor(getN() - 1).get();
	return aDevolver;	
}

bool Pila::isVacia(){
	if (this->getN() == 0) return true;
	else return false;
}

Pila::~Pila(){
	 //this->~ListaEnlazada();
}