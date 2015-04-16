#pragma once

#include "iostream"
using namespace std;

// Clase que representa a los objetos que contiene una ListaContigua
// Internamente, Elemento tendrá un atributo privado que será el dato real
class Elemento
{
	float valor; // Valor del elemento. Dato que realmente guarda el elemento
public:

	// Constructor predeterminado. Deja el valor con basura
	// Complejidad temporal y espacial: O(1)
	Elemento();

	// Construye un elemento
	// Parámetro: valor que queremos dar al elemento
	// Complejidad temporal y espacial: O(1)
	Elemento(float valor);

	// Constructor de copia
	// Parámetro: origen de la copia
	// Complejidad temporal y espacial: O(1)
	Elemento (Elemento &loAsignado);

	// Obtiene el valor del elemento
	// Retorno: valor del elemento
	// Complejidad temporal y espacial: O(1)
	float get() const;

	// Modifica el valor del elemento
	// Parámetro: nuevo valor del contenido del elemento
	// Complejidad temporal y espacial: O(1)
	void set (float nuevoValor);

	// Operadores para hacer las comparaciones habituales entre elementos
	// Parámetro: segundo elemento de la comparación (el primero es predeterminado: el objeto actual)
	// Retorno: true o false según el resultado de la comparación
	// Complejidad temporal y espacial: O(1)
	bool operator == (const Elemento &operando2);
	bool operator < (const Elemento &operando2);
	bool operator > (const Elemento &operando2);
	bool operator <= (const Elemento &operando2);
	bool operator >= (const Elemento &operando2);

	// Sobrecarga del operador de asignación
	// El primer operando (a donde asignamos) es siempre el objeto actual sobre el que se llama al operador
	// Parámetro: el origen de la asignación
	// Retorno: elemento después de hacer la asignación
	// Complejidad temporal y espacial: O(1)
	Elemento& operator= (const Elemento &loAsignado);
	
};



