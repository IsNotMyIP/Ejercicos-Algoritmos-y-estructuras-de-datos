#pragma once
#include "ListaEnlazada.h"
#include "Elemento.h"

// Clase que implementa una pila de elementos. La pila se implementa mediante una lista enlazada.
// La cima de la pila será el primer elemento de la lista
class Pila: public ListaEnlazada
{
public:

	// Mete un nuevo elemento en la cima de la pila
	// Parámetro: nuevo elemento que copiaremos en la cima
	// Complejidad temporal y espacial: O(1)
	void push(Elemento nuevoElemento);

	// Obtiene el elemento que está en la cima y lo borra de ahí
	// Retorno: una copia del elemento que está en la cima
	// Precondición: la pila no está vacía
	// Complejidad temporal y espacial: O(1)
	Elemento pop();

	// Obtiene el elemento que está en la cima sin borrarlo de ahí
	// Retorno: una copia del elemento que está en la cima
	// Precondición: la pila no está vacía
	// Complejidad temporal y espacial: O(1)
	Elemento verCima();

	// Comprueba si la pila está vacía
	// Retorno: verdadero si está vacía, falso si no lo está
	// Complejidad temporal y espacial: O(1)
	bool isVacia();

};

