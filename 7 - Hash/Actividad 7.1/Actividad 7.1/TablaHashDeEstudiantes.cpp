#include "TablaHashDeEstudiantes.h"
#include "cassert"
#include "iostream"

using namespace std;


int TablaHashDeEstudiantes::obtenerPosicion (unsigned int clave) {
	return (clave%capacidad);
}

TablaHashDeEstudiantes::TablaHashDeEstudiantes(int capacidad) {

	// Inicializamos los atributos
	nombres = new string[capacidad];
	flags = (bool*) malloc (capacidad*sizeof(bool));
	claves = (unsigned int*) malloc (capacidad*sizeof(unsigned int));
	this->capacidad = capacidad;

	// Ponemos todos los flags a falso
	for (int i=0; i<capacidad; i++) flags[i]=false;
}

bool TablaHashDeEstudiantes::existeEstudiante (unsigned int clave) {
	int posicion = obtenerPosicion(clave);
	if (flags[posicion] && claves[posicion]==clave) return (true);
	else return (false);
}

string TablaHashDeEstudiantes::getEstudiante (unsigned int clave) {
	assert(existeEstudiante(clave)); // Precondición: el estudiante debe existir
	int posicion = obtenerPosicion(clave);
	return (nombres[posicion]);
}

void TablaHashDeEstudiantes::introducirEstudiante (unsigned int clave, string estudiante) {
	int posicion = obtenerPosicion(clave);
	assert(!flags[posicion]); // Precondición: en donde queremos meter el estudiante no hay nada aún
	nombres[posicion]=estudiante;
	flags[posicion]=true;
	claves[posicion]=clave;
}

void TablaHashDeEstudiantes::eliminarEstudiante (unsigned int clave) {
	assert(existeEstudiante(clave));
	int posicion = obtenerPosicion(clave);
	flags[posicion]=false;
}

void TablaHashDeEstudiantes::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Flag: " << flags[i] << " | Clave: " << claves[i] << " | Contenido: " << nombres[i] << endl;
}

TablaHashDeEstudiantes::~TablaHashDeEstudiantes() {
	delete[] nombres;
	free (flags);
	free (claves);
}
