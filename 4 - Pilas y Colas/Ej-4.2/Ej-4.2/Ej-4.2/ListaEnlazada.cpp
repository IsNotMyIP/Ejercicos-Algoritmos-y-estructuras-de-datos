#include "ListaEnlazada.h"
#include "iostream"
#include "cstdlib" // Para qsort
#include "cassert"

using namespace std;

Nodo * ListaEnlazada::getNodo (int posicion) {
	assert(posicion >= 0 && posicion <= n-1); // Implica tambi�n que la lista no est� vac�a

	Nodo *resultado = NULL; // Aqu� guardaremos el puntero al nodo resultado 

	// Si intentamos acceder al �ltimo nodo, lo hacemos directamente desde el primero, 
	// para hacer que el acceso al �ltimo sea O(1)
	if (posicion == n-1) resultado = lista->getAnteriorNodo();
	
	// En caso contrario, recorremos la lista hasta la posici�n correcta
	else {
		resultado = lista; // Hacemos que el resultado apunte al primer nodo
		for (int i=0; i<posicion; i++) resultado = resultado->getSiguienteNodo();
	}

	return (resultado);
}

void ListaEnlazada::vaciarLista() {
	// Eliminamos el primer elemento de la lista. Esta operaci�n la repetimos n veces
	// Eliminar el primer elemento de la lista es O(1)
	for (int i=0; i<n; i++) eliminar(0);
}


ListaEnlazada::ListaEnlazada() {
	lista = NULL; // No hay que reservar memoria ya que la lista se crea vac�a en un principio
	n=0;
}

ListaEnlazada::ListaEnlazada(ListaEnlazada &loAsignado) {
	// Creamos una lista vac�a y luego copiamos loAsignado en ella
	lista = NULL; 
	n=0;
	*this = loAsignado; // Llamamos al operador de asignaci�n. Es O(n)
}

Elemento ListaEnlazada::getValor(int posicion) {
	assert (posicion >= 0 && posicion <= n-1); // Implica tambi�n que la lista no est� vac�a
	// Obtenemos el nodo que contiene el elemento
	Nodo *nodoQueContieneResultado = getNodo (posicion);
	return (nodoQueContieneResultado->getElemento());
}

void ListaEnlazada::setValor(int posicion, Elemento nuevoValor) {
	assert (posicion >= 0 && posicion <= n-1); // Implica tambi�n que la lista no est� vac�a
	getNodo(posicion)->setElemento(nuevoValor);
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar (int posicion, Elemento nuevoValor) {
	assert (posicion >= 0 && posicion <= n); 

	// Creamos el nuevo nodo con el nuevo valor
	Nodo *nuevoNodo = new Nodo(nuevoValor);

	// Si la lista estaba vacia...
	if (n==0) {
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

void ListaEnlazada::eliminar (int posicion) {
	assert (posicion >= 0 && posicion <= n-1); // Ya implica que la lista no puede estar vac�a

	// Obtenemos el nodo que queremos eliminar
	Nodo *nodoAEliminar = getNodo(posicion);

	// Si la lista s�lo tiene un elemento, actualizamos el atributo lista pues la lista se queda vacia
	if (n==1) lista = NULL;

	// Si la lista tiene m�s de un elemento, hacemos el caso general
	else {
		// Obtenemos los dos nodos que le rodean
		Nodo *nodoAnterior = nodoAEliminar->getAnteriorNodo();
		Nodo *nodoSiguiente = nodoAEliminar->getSiguienteNodo();
		// Modificamos los punteros de cada uno de los dos nodos que rodean al que queremos eliminar
		nodoAnterior->setSiguienteNodo(nodoSiguiente);
		nodoSiguiente->setAnteriorNodo(nodoAnterior);
		// Si el nodo a eliminar era el 0, tenemos que actualizar el atributo lista
		if (posicion==0) lista = nodoSiguiente;
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
	for (int i=0; i<loAsignado.n; i++) insertar(i, loAsignado.getValor(i));

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
	for (int i=0; i<operador2.n; i++) resultado->insertar(n+i, operador2.getValor(i));

	// Devolvemos el nuevo objeto
	return (*resultado);
}

Elemento& ListaEnlazada::operator[] (int posicion) {
	assert (posicion >= 0 && posicion <= n-1); // Ya implica que la lista no puede estar vac�a

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
	if (encontrado) return (posicion-1);
	else return (-1);
}


void ListaEnlazada::ordenar() {
	// Ordena de mayor a menor mediante el m�todo de la burbuja yendo de principio a fin del vector.
	// Por lo tanto en cada pasada deja el m�nimo en el final del vector
	// OJO: ya no podemos ordenar por qsort() de la biblioteca est�ndar porque s�lo sirve para listas contiguas en memoria

	int ultimaPosicion; // Cada pasada (cada sacudida de la burbuja) ir� hasta esta posici�n

	for (ultimaPosicion = n-1; ultimaPosicion >= 1; ultimaPosicion--) {
		// Ahora hacemos una pasada (sacudida de la burbuja). El resultado ser� que el menor quedar� puesto en ultimaPosicion
		for (int i=0; i<=ultimaPosicion-1; i++) {
			Elemento e1, e2; // Los dos elementos a comparar e intercambiar si es necesario
			e1=getValor(i);
			e2=getValor(i+1);
			// Compara el elemento i con el i+1 y los intercambia si es necesario
			if (e1 < e2) {
				setValor(i, e2);
				setValor(i+1, e1);
			}
		}
	}
}


ListaEnlazada::~ListaEnlazada() {
	vaciarLista();
}



