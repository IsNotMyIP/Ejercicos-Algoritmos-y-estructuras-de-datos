#include "TablaHashDeEstudiantes.h"
#include "cassert"
#include "iostream"

using namespace std;


int TablaHashDeEstudiantes::obtenerPosicion (unsigned int clave) {
	return (clave%m);
}

TablaHashDeEstudiantes::TablaHashDeEstudiantes(int m) {

	// Inicializamos los atributos
	nombres = new string[m];
	flags = (bool*) malloc (m*sizeof(bool));
	claves = (unsigned int*) malloc (m*sizeof(unsigned int));
	this->m = m;

	// Ponemos todos los flags a falso
	for (int i=0; i<m; i++) flags[i]=false;
}

bool TablaHashDeEstudiantes::existeEstudiante (unsigned int clave) {
	int posicion = obtenerPosicion(clave);
	if (flags[posicion] && claves[posicion]==clave) return (true);
	else return (false);
}

int TablaHashDeEstudiantes::checkEmpty (int pos){
	if (!flags[pos]){
		return pos;
	}
	else{
		if (pos == m - 1){
			return checkEmpty(0);
		}
		else{
			return checkEmpty(pos + 1);
		}
	}
}

int TablaHashDeEstudiantes::checkClave(int pos, unsigned int clave){
	if (clave == claves[pos]){
		return pos;
	}
	else{
		if (pos == m - 1){
			return checkClave(0, clave);
		}
		else{
			return checkClave(pos + 1, clave);
		}
	}
}
bool TablaHashDeEstudiantes::isLlena(){
	if (n>=m){
		return true;
	}
	else{
		return false;
	}
}

string TablaHashDeEstudiantes::getEstudiante (unsigned int clave) {
	assert(existeEstudiante(clave)); // Precondición: el estudiante debe existir
	int posicion = obtenerPosicion(clave);
	if (clave != claves[posicion]){
		posicion = checkClave(posicion, clave);
	}
	return (nombres[posicion]);
}

void TablaHashDeEstudiantes::introducirEstudiante (unsigned int clave, string estudiante) {
	int posicion = obtenerPosicion(clave);
	assert(!isLlena()); // Precondición: en donde queremos meter el estudiante no hay nada aún
	if (!flags[posicion]) {
		n++; // aumentamos el size de la tabla.
		nombres[posicion] = estudiante;
		flags[posicion] = true;
		claves[posicion] = clave;
	}
	else{
		int freePos = checkEmpty(posicion);
		nombres[freePos] = estudiante;
		flags[freePos] = true;
		claves[freePos] = clave;
	}
}

void TablaHashDeEstudiantes::eliminarEstudiante (unsigned int clave) {
	assert(existeEstudiante(clave));
	n--; // disminuiremos el size de la tabla.
	int posicion = obtenerPosicion(clave);
	flags[posicion]=false;
}

void TablaHashDeEstudiantes::imprimir() {
	for (int i=0; i<m; i++) cout << "Posicion " << i << " | Flag: " << flags[i] << " | Clave: " << claves[i] << " | Contenido: " << nombres[i] << endl;
}

TablaHashDeEstudiantes::~TablaHashDeEstudiantes() {
	delete[] nombres;
	free (flags);
	free (claves);
}
