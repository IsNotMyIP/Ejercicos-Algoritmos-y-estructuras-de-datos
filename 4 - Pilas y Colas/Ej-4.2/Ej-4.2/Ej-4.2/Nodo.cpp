#include "Nodo.h"
#include "Elemento.h"


Nodo::Nodo() {
	siguienteNodo = NULL;
	anteriorNodo = NULL;
}

Nodo::Nodo (Elemento elemento, Nodo *siguienteNodo, Nodo *anteriorNodo) {
	this->elemento = elemento;
	this->siguienteNodo = siguienteNodo;
	this->anteriorNodo = anteriorNodo;
}

Elemento Nodo::getElemento() {return (elemento);}
void Nodo::setElemento(Elemento elemento) {this->elemento = elemento;}
Nodo* Nodo::getSiguienteNodo() {return (siguienteNodo);}
void Nodo::setSiguienteNodo (Nodo *siguienteNodo) {this->siguienteNodo = siguienteNodo;}
Nodo* Nodo::getAnteriorNodo() {return(anteriorNodo);}
void Nodo::setAnteriorNodo (Nodo *anteriorNodo) {this->anteriorNodo = anteriorNodo;}
