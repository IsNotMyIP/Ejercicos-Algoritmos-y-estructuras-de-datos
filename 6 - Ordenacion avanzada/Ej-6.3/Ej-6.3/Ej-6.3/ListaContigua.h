#pragma once
#include "Elemento.h"

// Numero de posiciones en que se incrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondición: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una ListaContigua genérica contigua en memoria y cuya capacidad se redimensiona automáticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
// La ListaContigua es genérica porque sus elementos son objetos de la clase "Elemento", que por dentro puede tener cualquier cosa
class ListaContigua
{
	// Puntero que apuntará a la zona de memoria en donde empieza la ListaContigua
	Elemento *vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondición: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= 0 && capacidad <= n
	int capacidad;

	// Nos dice si la ListaContigua está llena o no.
	// Retorno: verdadero si está llena, falso si no está llena
	// Complejidad temporal y espacial: O(1)
	bool isLlena();

	// Función para comparar elementos, utilizada por la función "qsort()" que se utiliza en "ordenar()"
	// Parámetros: 
	// - elemento1 apunta al primer elemento
	// - elemento2 apunta al segundo elemento
	// Retorno: devuelve positivo si el primer entero es menor que el segundo, 0 si son iguales, y negativo si el primer entero es mayor que el segundo
	// Precondición: elemento1 != NULL && elemento2 != NULL
	// Complejidad temporal y espacial: O(1)
	static int compararElementos (const void *elemento1, const void *elemento2);

public:

	// Constructor. Crea una ListaContigua de tamaño 0
	// Complejidad temporal y espacial: O(1)
	ListaContigua();

	// Constructor de copia
	// Parámetro: ListaContigua fuente de la copia
	// Complejidad temporal: O(loAsignado.n)
	// Complejidad espacial: O(loAsignado.n)
	ListaContigua(ListaContigua &loAsignado);

	// Devuelve un elemento de la ListaContigua
	// Parámetro: la posición del elemento
	// Retorno: el elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	Elemento getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	void setValor(int posicion, Elemento nuevoValor);

	// Devuelve el tamaño actual de la ListaContigua
	// Retorno: número actual de elementos de la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getN(); 

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: número máximo que actualmente podría contener la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getCapacidad(); 

	// Inserta un nuevo elemento en una posición de la ListaContigua, dejando primero un hueco para meterlo ahí
	// Los elementos que había desde la posición hasta el final de la ListaContigua se desplazarán una posición a la derecha
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertar (int posicion, Elemento nuevoValor);

	// Elimina un elemento en una posición dada.
	// Los elementos que había desde posicion+1 hasta el final de la ListaContigua se desplazarán una posición a la izquierda
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void eliminar (int posicion);

	// Operador = para asignar ListaContiguas
	// Parámetros:
	// - El objeto actual sobre el que se llama el método es el lValue (parte izquierda de la asignación)
	// - El parámetro es la parte derecha de la asignación
	// Retorno:
	// - El objeto actual, una vez asignado
	// Complejidad temporal: O(loAsignado.n)
	// Complejidad espacial: O(loAsignado.n)
	ListaContigua& operator= (ListaContigua &loAsignado);

	// Operador + para concatenar dos ListaContiguas
	// Parámetros
	// - El objeto actual sobre el que se llama el método es el primer operando del "+"
	// - El parámetro es el segundo operando del "+"
	// Retorno:
	// - Una nueva ListaContigua que es la concatenación de las dos ListaContiguas pasadas como argumentos
	// Complejidad temporal: O(maximo(n,operador2.n))
	// Complejidad espacial: O(maximo(n,operador2.n))
	ListaContigua& operator+ (ListaContigua &operador2);

	// Devuelve un elemento de la ListaContigua
	// Parámetro: la posición del elemento
	// Retorno: el elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	Elemento& operator[] (int posicion);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(Elemento elementoABuscar);

	// Ordena la ListaContigua de mayor a menor, utilizando el método QuickSort
	// Complejidad temporal: O(nlogn)
	// Complejidad espacial: no lo hemos visto
	void ordenar();

	// Destructor. Libera memoria
	// Complejidad temporal y espacial: O(1)
	~ListaContigua();
};








