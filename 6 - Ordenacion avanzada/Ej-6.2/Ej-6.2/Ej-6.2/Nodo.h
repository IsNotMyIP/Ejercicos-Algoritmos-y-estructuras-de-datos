#pragma once
#include "Elemento.h"

// Clase que representa un nodo de una lista enlazada
class Nodo
{
	Elemento elemento; // El elemento que guarda el nodo
	Nodo *siguienteNodo; // Puntero al siguiente nodo de la lista enlazada
	Nodo *anteriorNodo; // Puntero al anterior nodo de la lista enlazada
public:
	// Constructor sin parámetros. Crea un nodo que no contiene ningún elemento
	// Complejidad temporal: O(1)
	Nodo();

	// Constructor normal
	// Parámetros: 
	// - el elemento que queremos poner en el nodo
	// - puntero al siguiente nodo (NULL por defecto)
	// - puntero al anterior nodo (NULL por defecto)
	// Complejidad temporal: O(1)
	Nodo (Elemento elemento, Nodo *siguienteNodo = NULL, Nodo *anteriorNodo = NULL);

	// Métodos habituales para establecer y leer los atributos
	// Complejidad temporal: O(1) en todos
	Elemento getElemento();
	void setElemento(Elemento elemento);
	Nodo* getSiguienteNodo();
	void setSiguienteNodo (Nodo *siguienteNodo);
	Nodo* getAnteriorNodo();
	void setAnteriorNodo (Nodo *anteriorNodo);
};

