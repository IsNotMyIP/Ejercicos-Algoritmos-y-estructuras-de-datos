#pragma once
#include "string"

using namespace std;

// Tabla hash que guarda los nombres de los estudiantes de una universidad
class TablaHashDeEstudiantes
{

protected:
	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto

	// Vectores que guardar�n la informaci�n de la tabla hash
	string *nombres; // Vector con los nombres de los estudiantes
	bool *flags;   // Vector con los flags que indican si una posici�n est� vac�a (false) o no (true). Si esta vacia, tiene basura.
	unsigned int *claves; // Vector con las claves de los estudiantes

	// M�todo de hashing
	// Par�metro: la clave del estudiante (es su n�mero de matr�cula)
	// Retorno: la posici�n donde el estudiante deber�a estar o ponerse en la tabla hash
	// Complejidad temporal y espacial: O(1)
	int obtenerPosicion (unsigned int clave);

public:

	// Constructor
	// Par�metro: capacidad de la tabla
	// Complejidad temporal y espacial: O(capacidad)
	TablaHashDeEstudiantes(int capacidad);

	// Comprueba si un estudiante est� o no en la tabla hash
	// Par�metro: la clave del estudiante
	// Retorno: true si est�, false si no
	// Complejidad temporal y espacial: O(1)
	bool existeEstudiante (unsigned int clave);

	// Obtiene un estudiante (su nombre) a partir de su clave
	// Par�metro: la clave del estudiante
	// Retorno: el nombre del estudiante
	// Precondici�n: el estudiante debe estar en la tabla hash
	// Complejidad temporal y espacial: O(1)
	string getEstudiante (unsigned int clave);

	// Inserta un estudiante en la tabla
	// Par�metros:
	// - clave: el n�mero de matr�cula del estudiante
	// - estudiante: el nombre del estudiante
	// Precondici�n: no existe en la tabla hash un estudiante en la misma posici�n en donde lo metemos
	//               Es decir, no existe un estudiante cuya posicion (a partir de su clave) coincida con el estudiante que queremos meter
	// Complejidad temporal y espacial: O(1)
	void introducirEstudiante (unsigned int clave, string estudiante);

	// Elimina un estudiante de la tabla
	// Par�metro: la clave del estudiante a eliminar
	// Precondici�n: el estudiante debe estar en la tabla hash
	// Complejidad temporal y espacial: O(1)
	void eliminarEstudiante (unsigned int clave);

	// Imprime toda la tabla hash
	// Complejidad temporal: O(capacidad)
	// Complejidad espacial: O(1)
	void imprimir();

	// Destructor
	// Complejidad temporal y espacial: O(1)
	~TablaHashDeEstudiantes();

};

