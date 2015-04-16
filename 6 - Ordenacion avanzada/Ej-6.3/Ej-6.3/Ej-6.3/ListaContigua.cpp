#include "ListaContigua.h"
#include "iostream"
#include "cassert"
#include "cstdlib" // Para qsort

using namespace std;


ListaContigua::ListaContigua() {
	vector = NULL; // No hay que reservar memoria ya que la ListaContigua se crea vacía en un principio
	n=0;
	capacidad=0;
}


ListaContigua::ListaContigua(ListaContigua &loAsignado) {
	vector = NULL; // Para que el realloc que llamamos dentro del operador de asignación pueda funcionar
	*this = loAsignado; // Llamamos al operador de asignación
}

Elemento ListaContigua::getValor(int posicion) {
	assert(posicion >= 0 && posicion <= n-1);
	return (vector[posicion]);
}

void ListaContigua::setValor(int posicion, Elemento nuevoValor) {
	assert(posicion >= 0 && posicion <= n-1);
	vector[posicion] = nuevoValor;
}

int ListaContigua::getN() {
	return (n);
}

int ListaContigua::getCapacidad() {
	return (capacidad);
}

void ListaContigua::insertar (int posicion, Elemento nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	// Si la ListaContigua está ya llena, antes de insertar ampliamos su capacidad en INCREMENTO
	if (isLlena()) {
		vector = (Elemento*) realloc(vector, sizeof(Elemento)*(capacidad+INCREMENTO));
		capacidad += INCREMENTO;
	}
	
	// Dejamos hueco para el nuevo elemento, desplazando a la derecha los que hay a partir de posicion hasta el final
	memmove (&vector[posicion+1], &vector[posicion], sizeof(Elemento)*(n-posicion));

	// Metemos el nuevo elemento
	n++;
	setValor(posicion, nuevoValor);
}

void ListaContigua::eliminar (int posicion) {
	assert(posicion >= 0 && posicion <= n-1);

	// Tapamos el hueco dejado por el elemento eliminado. Para ello, desplazamos a la izquierda los
	// elementos que hay a partir de posicion+1 hasta el final
	memmove (&vector[posicion], &vector[posicion+1], sizeof(Elemento)*(n-posicion-1));
	n--;

	// Si la capacidad sobrante es demasiada (2*INCREMENTO), la reducimos en INCREMENTO unidades
	if (capacidad-n == 2*INCREMENTO) {
		vector = (Elemento*) realloc (vector, sizeof(Elemento)*(capacidad-INCREMENTO));
		capacidad -= INCREMENTO;
	}

}

bool ListaContigua::isLlena() {
	return (n==capacidad);
}

ListaContigua& ListaContigua::operator= (ListaContigua &loAsignado) {
	// Copiamos los atributos
	n = loAsignado.n;
	capacidad = loAsignado.capacidad;

	// Como el vector resultado (el objeto actual) va a ser totalmente pisado, liberamos su memoria y la volvemos a reservar
	free(vector);
	vector = (Elemento*) malloc (sizeof(Elemento)*capacidad);

	// Ahora copiamos los elementos, del parámetro al vector resultado
	// Usamos memcpy porque no hay solapamiento
	memcpy (vector, loAsignado.vector, sizeof(Elemento)*n); 

	// Devolvemos el resultado, que es la nueva ListaContigua actual
	return (*this);
}

ListaContigua& ListaContigua::operator+ (ListaContigua &operador2) {
	// Creamos la nueva ListaContigua resultado
	// Tiene que ser dinámica (creada con new) para que no desaparezca una vez terminado este método
	ListaContigua *resultado = new ListaContigua();

	// Ajustamos los atributos de la nueva ListaContigua
	// Podríamos ajustar aún más la capacidad para que nunca sobre más de INCREMENTO
	resultado->capacidad = capacidad + operador2.capacidad;
	resultado->n = n + operador2.n;

	// Reservamos la memoria del nuevo vector
	resultado->vector = (Elemento*) malloc(sizeof(Elemento)*(resultado->capacidad));

	// Copiamos los vectores a la nueva ListaContigua
	memcpy (resultado->vector, vector, sizeof(Elemento)*n);
	memcpy (&(resultado->vector[n]), operador2.vector, sizeof(Elemento)*operador2.n);

	// Devolvemos el nuevo objeto
	return (*resultado);
}

Elemento& ListaContigua::operator[] (int posicion) {
	assert(posicion >= 0 && posicion <= n-1);

	// Conseguimos el dato
	Elemento *resultado = &vector[posicion];

	// Devolvemos el resultado
	return (*resultado);
}

int ListaContigua::buscar(Elemento elementoABuscar) {
	int posicion = 0; // Posición actual en donde buscamos
	bool encontrado = false; // Nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < n) {
		if (vector[posicion] == elementoABuscar) encontrado = true;
		posicion++;
	}

	// Devolvemos la posición si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion-1);
	else return (-1);
}

int ListaContigua::compararElementos (const void *elemento1, const void *elemento2) {
	assert(elemento1 != NULL && elemento2 != NULL);
	Elemento *e1 = (Elemento*) elemento1; // Alias para el elemento1
	Elemento *e2 = (Elemento*) elemento2; // Alias para el elemento2
	if (*e1 > *e2) return (-1);
	if (*e1 == *e2) return (0);
	if (*e1 < *e2) return (1);
}

void ListaContigua::ordenar() {
	qsort(vector, n, sizeof(Elemento), compararElementos);
}


ListaContigua::~ListaContigua() {
	free(vector);
}


