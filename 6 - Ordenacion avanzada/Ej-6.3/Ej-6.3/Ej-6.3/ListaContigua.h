#pragma once
#include "Elemento.h"

// Numero de posiciones en que se incrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondici�n: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una ListaContigua gen�rica contigua en memoria y cuya capacidad se redimensiona autom�ticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
// La ListaContigua es gen�rica porque sus elementos son objetos de la clase "Elemento", que por dentro puede tener cualquier cosa
class ListaContigua
{
	// Puntero que apuntar� a la zona de memoria en donde empieza la ListaContigua
	Elemento *vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondici�n: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= 0 && capacidad <= n
	int capacidad;

	// Nos dice si la ListaContigua est� llena o no.
	// Retorno: verdadero si est� llena, falso si no est� llena
	// Complejidad temporal y espacial: O(1)
	bool isLlena();

	// Funci�n para comparar elementos, utilizada por la funci�n "qsort()" que se utiliza en "ordenar()"
	// Par�metros: 
	// - elemento1 apunta al primer elemento
	// - elemento2 apunta al segundo elemento
	// Retorno: devuelve positivo si el primer entero es menor que el segundo, 0 si son iguales, y negativo si el primer entero es mayor que el segundo
	// Precondici�n: elemento1 != NULL && elemento2 != NULL
	// Complejidad temporal y espacial: O(1)
	static int compararElementos (const void *elemento1, const void *elemento2);

public:

	// Constructor. Crea una ListaContigua de tama�o 0
	// Complejidad temporal y espacial: O(1)
	ListaContigua();

	// Constructor de copia
	// Par�metro: ListaContigua fuente de la copia
	// Complejidad temporal: O(loAsignado.n)
	// Complejidad espacial: O(loAsignado.n)
	ListaContigua(ListaContigua &loAsignado);

	// Devuelve un elemento de la ListaContigua
	// Par�metro: la posici�n del elemento
	// Retorno: el elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	Elemento getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	void setValor(int posicion, Elemento nuevoValor);

	// Devuelve el tama�o actual de la ListaContigua
	// Retorno: n�mero actual de elementos de la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getN(); 

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: n�mero m�ximo que actualmente podr�a contener la ListaContigua
	// Complejidad temporal y espacial: O(1)
	int getCapacidad(); 

	// Inserta un nuevo elemento en una posici�n de la ListaContigua, dejando primero un hueco para meterlo ah�
	// Los elementos que hab�a desde la posici�n hasta el final de la ListaContigua se desplazar�n una posici�n a la derecha
	// Par�metros:
	// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void insertar (int posicion, Elemento nuevoValor);

	// Elimina un elemento en una posici�n dada.
	// Los elementos que hab�a desde posicion+1 hasta el final de la ListaContigua se desplazar�n una posici�n a la izquierda
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(n)
	void eliminar (int posicion);

	// Operador = para asignar ListaContiguas
	// Par�metros:
	// - El objeto actual sobre el que se llama el m�todo es el lValue (parte izquierda de la asignaci�n)
	// - El par�metro es la parte derecha de la asignaci�n
	// Retorno:
	// - El objeto actual, una vez asignado
	// Complejidad temporal: O(loAsignado.n)
	// Complejidad espacial: O(loAsignado.n)
	ListaContigua& operator= (ListaContigua &loAsignado);

	// Operador + para concatenar dos ListaContiguas
	// Par�metros
	// - El objeto actual sobre el que se llama el m�todo es el primer operando del "+"
	// - El par�metro es el segundo operando del "+"
	// Retorno:
	// - Una nueva ListaContigua que es la concatenaci�n de las dos ListaContiguas pasadas como argumentos
	// Complejidad temporal: O(maximo(n,operador2.n))
	// Complejidad espacial: O(maximo(n,operador2.n))
	ListaContigua& operator+ (ListaContigua &operador2);

	// Devuelve un elemento de la ListaContigua
	// Par�metro: la posici�n del elemento
	// Retorno: el elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal y espacial: O(1)
	Elemento& operator[] (int posicion);

	// Busca la posici�n de un elemento en la ListaContigua
	// Par�metro: el elemento a buscar
	// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(1)
	int buscar(Elemento elementoABuscar);

	// Ordena la ListaContigua de mayor a menor, utilizando el m�todo QuickSort
	// Complejidad temporal: O(nlogn)
	// Complejidad espacial: no lo hemos visto
	void ordenar();

	// Destructor. Libera memoria
	// Complejidad temporal y espacial: O(1)
	~ListaContigua();
};








