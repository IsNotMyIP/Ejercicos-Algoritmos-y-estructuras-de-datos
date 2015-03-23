#include "Pila.h"
#include "cassert" // Para "assert()"


void Pila::push(Elemento nuevoElemento) {
	insertar(0, nuevoElemento);
}

Elemento Pila::pop() {
	assert(!isVacia()); // Precondición
	Elemento resultado = verCima(); // Obtenemos la cima
	eliminar(0); // Eliminamos la cima
	return(resultado);
}

Elemento Pila::verCima() {
	assert(!isVacia()); // Precondición
	return(getValor(0));
}

bool Pila::isVacia() {
	return (getN()==0);
}



