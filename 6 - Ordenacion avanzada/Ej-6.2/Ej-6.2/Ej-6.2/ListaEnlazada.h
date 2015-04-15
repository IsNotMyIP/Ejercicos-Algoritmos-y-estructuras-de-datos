#pragma once

#include "Elemento.h"
#include "Nodo.h"



// Clase que representa a una lista genérica doblemente enlazada y circular. No tiene restricción de tamaño
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento, un puntero al siguiente nodo, y un puntero al anterior nodo
// La lista es genérica porque los elementos son objetos de la clase "Elemento", que por dentro puede tener cualquier cosa
class ListaEnlazada
{
	// Puntero que apuntará al primer nodo de la lista, o será NULL si la lista está vacía
	Nodo *lista;

	// Numero actual de elementos que tiene la lista
	// Precondición: n>=0
	int n;

	// Obtiene un nodo de la lista
	// Parámetro: la posición del nodo
	// Retorno: un puntero al nodo que está en dicha posición
	// Precondiciones: 
	// - la posición debe estar en el intervalo [0, n-1] y la lista no está vacía
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Nodo * getNodo(int posicion);

	// Vacia la lista entera, liberando la memoria de todos los nodos. 
	// Este método se usa en varios otros métodos
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void vaciarLista();

	// Ordena una lista doblemente enlazada y circular utilizando merge sort recursivo
	// Parámetro: lista enlazada que se quiere ordenar (ojo: es una referencia para no tener que copiarla!!)
	// Complejidad temporal: O(nlgn)
	// Complejidad espacial: O(1)
	void ordenarPorMergeSort(ListaEnlazada &lista);


	void ListaEnlazada::ordenarPorQuickSort(ListaEnlazada &lista);


	float getPivote();
public:

	// Constructor. Crea una lista de tamaño 0
	// Complejidad temporal y espacial: O(1)
	ListaEnlazada();

	// Constructor de copia
	// Complejidad temporal: O(loAsignado.n)
	// Complejidad espacial: O(loAsignado.n), porque crea una nueva lista
	ListaEnlazada(ListaEnlazada &loAsignado);

	// Devuelve un elemento de la lista en determinada posición
	// Parámetro: la posición del elemento
	// Retorno: una copia del elemento encontrado en esa posición
	// Precondiciones: 
	// - posicion en [0, n-1] y la lista no está vacía
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Elemento getValor(int posicion);

	// Modifica un elemento de la lista
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// - la lista no está vacía
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void setValor(int posicion, Elemento nuevoValor);

	// Devuelve el tamaño actual de la lista
	// Complejidad temporal y espacial: O(1)
	int getN();

	// Inserta un nuevo elemento en una posición de la lista
	// Los elementos que había desde la posición hasta el final de la lista se desplazarán una posición a la derecha
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void insertar(int posicion, Elemento nuevoValor);

	// Elimina un elemento en una posición dada.
	// Los elementos que había desde posicion+1 hasta el final de la lista se desplazarán una posición a la izquierda
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones:
	// - posicion en [0, n-1]
	// - la lista no está vacía
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void eliminar(int posicion);

	// Operador = para asignar listas
	// Parámetros:
	// - El objeto actual sobre el que se llama el método es el lValue (parte izquierda de la asignación)
	// - El parámetro es la parte derecha de la asignación
	// Retorno:
	// - El objeto actual, una vez asignado
	// Complejidad temporal: O(max(n,loAsignado.n))
	// Complejidad espacial: O(loAsignado.n) en el peor caso (cuando n=0)
	ListaEnlazada& operator= (ListaEnlazada &loAsignado);

	// Operador + para concatenar dos listas
	// Parámetros
	// - El objeto actual sobre el que se llama el método es el primer operando del "+"
	// - El parámetro es el segundo operando del "+"
	// Retorno:
	// - Una nueva lista que es la concatenación de las dos listas pasadas como argumentos
	// Complejidad temporal: O(max(n,operador2.n))
	// Complejidad espacial: O(max(n,operador2.n))
	ListaEnlazada& operator+ (ListaEnlazada &operador2);

	// Devuelve un elemento de la lista
	// Parámetro: la posición del elemento
	// Retorno: el elemento encontrado en esa posición
	// Precondiciones: 
	// - posicion en [0, n-1]
	// - lista no vacía
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Elemento& operator[] (int posicion);

	// Busca secuencialmente la posición de un elemento en la lista. Usa el operador == de Elemento
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(Elemento elementoABuscar);

	// Ordena la lista de menor a mayor, utilizando el algoritmo MergeSort recursivo
	// Complejidad temporal: O(nlgn)
	// Complejidad espacial: O(1)
	void ordenar();

	// Destructor. Libera memoria
	// Complejidad temporal: O(n)
	~ListaEnlazada();
};







