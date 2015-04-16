#pragma once

#include "iostream"
using namespace std;

// Clase que representa a los objetos que contiene una ListaContigua
// Internamente, Elemento tendr� un atributo privado que ser� el dato real
class Elemento
{
	float valor; // Valor del elemento. Dato que realmente guarda el elemento
public:

	// Constructor predeterminado. Deja el valor con basura
	// Complejidad temporal y espacial: O(1)
	Elemento();

	// Construye un elemento
	// Par�metro: valor que queremos dar al elemento
	// Complejidad temporal y espacial: O(1)
	Elemento(float valor);

	// Constructor de copia
	// Par�metro: origen de la copia
	// Complejidad temporal y espacial: O(1)
	Elemento (Elemento &loAsignado);

	// Obtiene el valor del elemento
	// Retorno: valor del elemento
	// Complejidad temporal y espacial: O(1)
	float get() const;

	// Modifica el valor del elemento
	// Par�metro: nuevo valor del contenido del elemento
	// Complejidad temporal y espacial: O(1)
	void set (float nuevoValor);

	// Operadores para hacer las comparaciones habituales entre elementos
	// Par�metro: segundo elemento de la comparaci�n (el primero es predeterminado: el objeto actual)
	// Retorno: true o false seg�n el resultado de la comparaci�n
	// Complejidad temporal y espacial: O(1)
	bool operator == (const Elemento &operando2);
	bool operator < (const Elemento &operando2);
	bool operator > (const Elemento &operando2);
	bool operator <= (const Elemento &operando2);
	bool operator >= (const Elemento &operando2);

	// Sobrecarga del operador de asignaci�n
	// El primer operando (a donde asignamos) es siempre el objeto actual sobre el que se llama al operador
	// Par�metro: el origen de la asignaci�n
	// Retorno: elemento despu�s de hacer la asignaci�n
	// Complejidad temporal y espacial: O(1)
	Elemento& operator= (const Elemento &loAsignado);
	
};



