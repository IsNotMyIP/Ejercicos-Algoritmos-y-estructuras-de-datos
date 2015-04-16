#include "ListaEnlazada.h"
#include "iostream"
#include "cstdlib" // Para qsort
#include "cassert"

using namespace std;

Nodo * ListaEnlazada::getNodo(int posicion) {
	assert(posicion >= 0 && posicion <= n - 1); // Implica tambi�n que la lista no est� vac�a

	Nodo *resultado = NULL; // Aqu� guardaremos el puntero al nodo resultado 

	// Si intentamos acceder al �ltimo nodo, lo hacemos directamente desde el primero, 
	// para hacer que el acceso al �ltimo sea O(1)
	if (posicion == n - 1) resultado = lista->getAnteriorNodo();

	// En caso contrario, recorremos la lista hasta la posici�n correcta
	else {
		resultado = lista; // Hacemos que el resultado apunte al primer nodo
		for (int i = 0; i<posicion; i++) resultado = resultado->getSiguienteNodo();
	}

	return (resultado);
}

void ListaEnlazada::vaciarLista() {
	// Eliminamos el primer elemento de la lista. Esta operaci�n la repetimos n veces
	// Eliminar el primer elemento de la lista es O(1)
	for (int i = 0; i<n; i++) eliminar(0);
}


ListaEnlazada::ListaEnlazada() {
	lista = NULL; // No hay que reservar memoria ya que la lista se crea vac�a en un principio
	n = 0;
}

ListaEnlazada::ListaEnlazada(ListaEnlazada &loAsignado) {
	// Creamos una lista vac�a y luego copiamos loAsignado en ella
	lista = NULL;
	n = 0;
	*this = loAsignado; // Llamamos al operador de asignaci�n. Es O(n)
}

Elemento ListaEnlazada::getValor(int posicion) {
	assert(posicion >= 0 && posicion <= n - 1); // Implica tambi�n que la lista no est� vac�a
	// Obtenemos el nodo que contiene el elemento
	Nodo *nodoQueContieneResultado = getNodo(posicion);
	return (nodoQueContieneResultado->getElemento());
}

void ListaEnlazada::setValor(int posicion, Elemento nuevoValor) {
	assert(posicion >= 0 && posicion <= n - 1); // Implica tambi�n que la lista no est� vac�a
	getNodo(posicion)->setElemento(nuevoValor);
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar(int posicion, Elemento nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	// Creamos el nuevo nodo con el nuevo valor
	Nodo *nuevoNodo = new Nodo(nuevoValor);

	// Si la lista estaba vacia...
	if (n == 0) {
		// Si s�lo hay un nodo, ese nodo es el primero y el final de la lista, por lo tanto sus punteros
		// anterior y siguiente apuntan a s� mismo
		nuevoNodo->setAnteriorNodo(nuevoNodo);
		nuevoNodo->setSiguienteNodo(nuevoNodo);
	}

	// Si la lista no est� vac�a
	else {
		// Primero obtenemos el nodo que est� a continuaci�n del que queremos insertar
		// Nota que, si queremos insertar al final, su siguiente es el primero
		Nodo *nodoSiguiente;
		if (posicion == n) nodoSiguiente = lista;
		else nodoSiguiente = getNodo(posicion);

		// Obtenemos el nodo anterior al que queremos insertar
		Nodo *nodoAnterior = nodoSiguiente->getAnteriorNodo();

		// Actualizamos los punteros del nuevo nodo
		nuevoNodo->setAnteriorNodo(nodoAnterior);
		nuevoNodo->setSiguienteNodo(nodoSiguiente);

		// Actualizamos los punteros de los dos nodos que rodean al nuevo nodo
		// El puntero siguiente del anterior y el puntero anterior del siguiente apuntar�n ambos al nuevo nodo
		nodoSiguiente->setAnteriorNodo(nuevoNodo);
		nodoAnterior->setSiguienteNodo(nuevoNodo);
	} // Fin else

	// Incrementamos el numero de elementos
	n++;

	// Si estamos insertando al principio de la lista, hay que modificar el puntero a la lista
	if (posicion == 0) lista = nuevoNodo;
}

void ListaEnlazada::eliminar(int posicion) {
	assert(posicion >= 0 && posicion <= n - 1); // Ya implica que la lista no puede estar vac�a

	// Obtenemos el nodo que queremos eliminar
	Nodo *nodoAEliminar = getNodo(posicion);

	// Si la lista s�lo tiene un elemento, actualizamos el atributo lista pues la lista se queda vacia
	if (n == 1) lista = NULL;

	// Si la lista tiene m�s de un elemento, hacemos el caso general
	else {
		// Obtenemos los dos nodos que le rodean
		Nodo *nodoAnterior = nodoAEliminar->getAnteriorNodo();
		Nodo *nodoSiguiente = nodoAEliminar->getSiguienteNodo();
		// Modificamos los punteros de cada uno de los dos nodos que rodean al que queremos eliminar
		nodoAnterior->setSiguienteNodo(nodoSiguiente);
		nodoSiguiente->setAnteriorNodo(nodoAnterior);
		// Si el nodo a eliminar era el 0, tenemos que actualizar el atributo lista
		if (posicion == 0) lista = nodoSiguiente;
	} // Fin else

	// Liberamos la memoria del nodo
	delete(nodoAEliminar);

	// Actualizamos n
	n--;

}

ListaEnlazada& ListaEnlazada::operator= (ListaEnlazada &loAsignado) {

	// Primero eliminamos todos los elementos de la lista actual, pues ya no nos sirven
	// Esto es importante pues hay que liberar la memoria que ocupaban los viejos nodos!
	// Es O(n)
	vaciarLista();


	// Ahora volvemos a crear la lista, pero con los elementos de loAsignado. 
	// Para ello, insertamos sucesivamente al final de la lista
	// Este bucle es O(loAsignado.n) porque insertar al final de la lista es O(1)
	for (int i = 0; i<loAsignado.n; i++) insertar(i, loAsignado.getValor(i));

	// Devolvemos la referencia al resultado, que es la nueva lista actual
	return (*this);
}

ListaEnlazada& ListaEnlazada::operator+ (ListaEnlazada &operador2) {

	// Creamos la lista que ser� el resultado
	// Tiene que ser din�mica (creada con new) para que no desaparezca una vez terminado este m�todo
	ListaEnlazada *resultado = new ListaEnlazada();

	// Copiamos la lista actual en la nueva lista
	*resultado = *this;

	// Copiamos la segunda lista (operador2) al final de la nueva lista.
	// No nos queda m�s remedio que ir insertando elemento a elemento
	for (int i = 0; i<operador2.n; i++) resultado->insertar(n + i, operador2.getValor(i));

	// Devolvemos el nuevo objeto
	return (*resultado);
}

Elemento& ListaEnlazada::operator[] (int posicion) {
	assert(posicion >= 0 && posicion <= n - 1); // Ya implica que la lista no puede estar vac�a

	// Es necesario guardar el retorno de getValor() en un objeto creado din�micamente
	// para que no se destruya autom�ticamente al finalizar el m�todo
	Elemento *resultado = new Elemento(getValor(posicion));

	// Devolvemos el resultado
	// OJO: tal como est�, el resultado de este operador no podr�a ser un lvalue en una asignaci�n, para ello el elemento devuelto deber�a
	// ser exactamente el que est� dentro del nodo, y no una copia del mismo. 
	return (*resultado);
}

int ListaEnlazada::buscar(Elemento elementoABuscar) {
	int posicion = 0; // Posici�n actual en donde buscamos
	bool encontrado = false; // Nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < n) {
		if (getValor(posicion) == elementoABuscar) encontrado = true;
		posicion++;
	}

	// Devolvemos la posici�n si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion - 1);
	else return (-1);
}

ListaEnlazada::~ListaEnlazada() {
	vaciarLista();
}

void ListaEnlazada::ordenarPorMergeSort() {
	// Si la lista est� vac�a o tiene un solo nodo, ya est� ordenada y no hay que hacer nada
	if (n >= 2) ordenarPorMergeSortRecursivo(*this);
}

void ListaEnlazada::ordenarPorQuickSort() {
	// Si la lista est� vac�a o tiene un solo nodo, ya est� ordenada y no hay que hacer nada
	if (n >= 2) ordenarPorQuickSortRecursivo(*this);
}


void ListaEnlazada::ordenarPorMergeSortRecursivo(ListaEnlazada &lista) {

	// S�lo hacemos algo si la lista tiene al menor 2 nodos 
	// Por tanto no hay llamada recursiva (caso trivial) cuando se tiene 1 nodo o menos
	if (lista.getN() >= 2) {

		// Listas que contendr�n a cada una de las dos partes en que dividiremos la lista enlazada
		ListaEnlazada sublista1, sublista2;

		// Los nodos de posici�n par los ponemos en la primera sublista, y los impares en la segunda
		int n = lista.getN(); // Tama�o de la lista pasada como parametro
		for (int i = 0; i<n; i++) {
			if (i % 2 == 0) {
				sublista1.insertar(sublista1.getN(), lista.getValor(0));
				lista.eliminar(0);
			}
			else {
				sublista2.insertar(sublista2.getN(), lista.getValor(0));
				lista.eliminar(0);
			}
		}

		// Hacemos la llamada recursiva para ordenar ambas sublistas por separado
		ordenarPorMergeSortRecursivo(sublista1);
		ordenarPorMergeSortRecursivo(sublista2);

		// Combinamos ambas sublistas y metemos la combinaci�n en el par�metro de la funci�n
		// Vamos cogiendo el menor elemento del principio de ambas sublistas, hasta que una de ellas quede vac�a
		// En ese momento ponemos la lista no vac�a tal cual a continuaci�n
		while (sublista1.getN() > 0 && sublista2.getN() > 0) {

			// Calculamos cu�l es la sublista que en su primera posici�n contiene el menor elemento
			ListaEnlazada *sublistaConMenor;
			if (sublista1.getValor(0) <= sublista2.getValor(0)) sublistaConMenor = &sublista1;
			else sublistaConMenor = &sublista2;

			// Ahora sacamos ese menor elemento de la lista y lo metemos en el resultado
			Elemento menor = sublistaConMenor->getValor(0);
			sublistaConMenor->eliminar(0); // Tenemos que eliminarle para no gastar memoria adicional O(n)

			// Insertamos el menor en el resultado
			lista.insertar(lista.getN(), menor);

		}

		// Ahora una de las sublistas est� vac�a. Averiguamos cu�l
		ListaEnlazada *sublistaNoVacia;
		if (sublista1.getN() == 0) sublistaNoVacia = &sublista2;
		else sublistaNoVacia = &sublista1;

		// Insertamos la no vac�a a continuaci�n del resultado 
		// No podemos usar el operador de concatenar porque entonces estar�amos teniendo memoria adicional O(n)
		while (sublistaNoVacia->getN() > 0) {
			lista.insertar(lista.getN(), sublistaNoVacia->getValor(0));
			sublistaNoVacia->eliminar(0); // Tenemos que ir eliminando a medida que vamos a�adiendo en el otro lado, para que la memoria adicional no sea O(n)
		}

	} // Fin if (lista.getN() >= 2)
}


void ListaEnlazada::ordenarPorQuickSortRecursivo(ListaEnlazada &lista) {
	assert(lista.getN() > 0); // Nunca podemos recibir una lista vac�a. Como m�nimo que tenga 1 nodo.

	int n = lista.getN(); // Tama�o de la lista pasada como parametro

	// S�lo hacemos algo si la lista tiene al menor 2 nodos 
	// Por tanto no hay llamada recursiva (caso trivial) cuando se tiene 1 nodo
	if (n >= 2) {

		// Listas que contendr�n a cada una de las dos partes en que dividiremos la lista enlazada
		ListaEnlazada sublista1, sublista2;

		// Elegimos el pivote como el primer elemento para que sea O(1)
		// Una mejor elecci�n hubiera sido la media del primero y el ultimo. Seguir�a siendo O(1) porque la 
		// lista es doblemente enlazada y circular, y seguir�a siendo un buen privote incluso si la lista est� ordenada o casi ordenada
		// Hemos elegido la mala solucion para ilustrar, a continuacion, la solucion para que una de las sublistas no quede vacia.
		// Si hubieramos elegido la media, en ning�n caso hubiera habido ninguna sublista vacia aunque hubieramos recorrido la lista
		// de principio a fin en vez de fin a inicio
		Elemento valorPivote = lista.getValor(0);

		// Repartimos los elementos seg�n el pivote. Empezamos por el �ltimo y acabamos por el primero.
		// De este modo, el �ltimo elemento que metemos es el pivote. Como los elementos que son menores que el pivote
		// los metemos en la sublista que menos elementos tenga, y como el �ltimo que comprobamos es el pivote, de este modo
		// nos aseguramos que la lista que menos elementos tenga al menos tenga tama�o 1
		while (lista.getN() > 0) {
			ListaEnlazada *sublistaEnDondeMeter; // Sublista en donde meteremos el elemento a repartir

			// Obtenemos el elemento a repartir y lo eliminamos de la lista
			Elemento elemento = lista.getValor(lista.getN() - 1); // Elemento a repartir. Tomamos el �ltimo
			lista.eliminar(lista.getN() - 1);

			// Averiguamos en qu� sublista meter el elemento
			if (elemento < valorPivote) sublistaEnDondeMeter = &sublista1;
			else if (elemento > valorPivote) sublistaEnDondeMeter = &sublista2;
			else { // El elemento es igual que el pivote
				// Lo metemos en la sublista que menos elementos tenga
				if (sublista1.getN() < sublista2.getN()) sublistaEnDondeMeter = &sublista1;
				else sublistaEnDondeMeter = &sublista2;
			}

			// Metemos el elemento en la sublista adecuada
			sublistaEnDondeMeter->insertar(sublistaEnDondeMeter->getN(), elemento);
		}

		// Hacemos la llamada recursiva para ordenar ambas sublistas por separado
		ordenarPorMergeSortRecursivo(sublista1);
		ordenarPorMergeSortRecursivo(sublista2);

		// Concatenamos ambas listas de forma eficiente, en O(1). Por ello no podemos usar el operador de concatenar, pues tardaria O(n) 
		// y adem�s crear�a una nueva lista como resultado de la concatenacion (y por lo tanto usar�a memoria adicional)
		// Primero averiguamos los cuatro nodos clave (primero y �ltimo de cada una de las sublistas), y despu�s los enlazamos entre s�
		// Recordemos que cada una de las dos sublistas al menos tiene 1 nodo
		Nodo *primeroSublista1 = sublista1.getNodo(0);
		Nodo *ultimoSublista1 = sublista1.getNodo(sublista1.getN() - 1);
		Nodo *primeroSublista2 = sublista2.getNodo(0);
		Nodo *ultimoSublista2 = sublista2.getNodo(sublista2.getN() - 1);

		// Enlazamos los nodos entre ellos. Recordemos que la lista es doblemente enlazada y circular
		ultimoSublista1->setSiguienteNodo(primeroSublista2);
		primeroSublista2->setAnteriorNodo(ultimoSublista1);
		primeroSublista1->setAnteriorNodo(ultimoSublista2);
		ultimoSublista2->setSiguienteNodo(primeroSublista1);

		// Configuramos la lista resultado, que es la que nos pasaron por par�metro
		lista.lista = primeroSublista1;
		lista.n = sublista1.getN() + sublista2.getN();

		// Configuramos las sublistas para que ya no apunten a esos nodos.
		sublista1.lista = NULL;
		sublista1.n = 0;
		sublista2.lista = NULL;
		sublista2.n = 0;

	} // Fin if (lista.getN() >= 2)
}