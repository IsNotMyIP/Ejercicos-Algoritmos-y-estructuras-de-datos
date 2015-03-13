#include "Elemento.h"


Elemento::Elemento(float contenido){
	setContenido(contenido);
}
void Elemento::setContenido(float contenido){
	this->contenido = contenido;
}

float Elemento::getContenido() const {
	return this->contenido;
}