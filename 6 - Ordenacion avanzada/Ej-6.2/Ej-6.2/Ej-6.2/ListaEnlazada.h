#pragma once

#include "Elemento.h"
#include "Nodo.h"



// Clase que representa a una lista gen�rica doblemente enlazada y circular. No tiene restricci�n de tama�o
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento, un puntero al siguiente nodo, y un puntero al anterior nodo
// La lista es gen�rica porque los elementos son objetos de la clase "Elemento", que por dentro puede tener cualquier cosa
class ListaEnlazada
{
	// Puntero que apuntar� al primer nodo de la lista, o ser� NULL si la lista est� vac�a
	Nodo *lista;

	// Numero actual de elementos que tiene la lista
	// Precondici�n: n>=0
	int n;

	// Obtiene un nodo de la lista
	// Par�metro: la posici�n del nodo
	// Retorno: un puntero al nodo que est� en dicha posici�n
	// Precondiciones: 
	// - la posici�n debe estar en el intervalo [0, n-1] y la lista no est� vac�a
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Nodo * getNodo(int posicion);

	// Vacia la lista entera, liberando la memoria de todos los nodos. 
	// Este m�todo se usa en varios otros m�todos
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void vaciarLista();

	// Ordena una lista doblemente enlazada y circular utilizando merge sort recursivo
	// Par�metro: lista enlazada que se quiere ordenar (ojo: es una referencia para no tener que copiarla!!)
	// Complejidad temporal: O(nlgn)
	// Complejidad espacial: O(1)
	void ordenarPorMergeSort(ListaEnlazada &lista);


	void ListaEnlazada::ordenarPorQuickSort(ListaEnlazada &lista);


	float getPivote();
public:

	// Constructor. Crea una lista de tama�o 0
	// Complejidad temporal y espacial: O(1)
	ListaEnlazada();

	// Constructor de copia
	// Complejidad temporal: O(loAsignado.n)
	// Complejidad espacial: O(loAsignado.n), porque crea una nueva lista
	ListaEnlazada(ListaEnlazada &loAsignado);

	// Devuelve un elemento de la lista en determinada posici�n
	// Par�metro: la posici�n del elemento
	// Retorno: una copia del elemento encontrado en esa posici�n
	// Precondiciones: 
	// - posicion en [0, n-1] y la lista no est� vac�a
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Elemento getValor(int posicion);

	// Modifica un elemento de la lista
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// - la lista no est� vac�a
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void setValor(int posicion, Elemento nuevoValor);

	// Devuelve el tama�o actual de la lista
	// Complejidad temporal y espacial: O(1)
	int getN();

	// Inserta un nuevo elemento en una posici�n de la lista
	// Los elementos que hab�a desde la posici�n hasta el final de la lista se desplazar�n una posici�n a la derecha
	// Par�metros:
	// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void insertar(int posicion, Elemento nuevoValor);

	// Elimina un elemento en una posici�n dada.
	// Los elementos que hab�a desde posicion+1 hasta el final de la lista se desplazar�n una posici�n a la izquierda
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
	// Precondiciones:
	// - posicion en [0, n-1]
	// - la lista no est� vac�a
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	void eliminar(int posicion);

	// Operador = para asignar listas
	// Par�metros:
	// - El objeto actual sobre el que se llama el m�todo es el lValue (parte izquierda de la asignaci�n)
	// - El par�metro es la parte derecha de la asignaci�n
	// Retorno:
	// - El objeto actual, una vez asignado
	// Complejidad temporal: O(max(n,loAsignado.n))
	// Complejidad espacial: O(loAsignado.n) en el peor caso (cuando n=0)
	ListaEnlazada& operator= (ListaEnlazada &loAsignado);

	// Operador + para concatenar dos listas
	// Par�metros
	// - El objeto actual sobre el que se llama el m�todo es el primer operando del "+"
	// - El par�metro es el segundo operando del "+"
	// Retorno:
	// - Una nueva lista que es la concatenaci�n de las dos listas pasadas como argumentos
	// Complejidad temporal: O(max(n,operador2.n))
	// Complejidad espacial: O(max(n,operador2.n))
	ListaEnlazada& operator+ (ListaEnlazada &operador2);

	// Devuelve un elemento de la lista
	// Par�metro: la posici�n del elemento
	// Retorno: el elemento encontrado en esa posici�n
	// Precondiciones: 
	// - posicion en [0, n-1]
	// - lista no vac�a
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	Elemento& operator[] (int posicion);

	// Busca secuencialmente la posici�n de un elemento en la lista. Usa el operador == de Elemento
	// Par�metro: el elemento a buscar
	// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
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







