#include "ListaEnlazada.h"


class Pila : ListaEnlazada {
private:

public:
	//Constructor vacio, recordamos problemas a la hora de llamarlo con ().
	//  Crea una lista de N o y complejidad espcial y temporal O(1);
	Pila();
	//Constructor en el cual se le pasa un valor ya para el primer dato.
	// Crea lista de N=0 y complejidades O(1)
	Pila(float insert);

	/* Inserta un elemento en la pila.
	Parametros: float.
	O temporal: O(1)
	O espacial: O(1)
	*/
	void push(float insert);
	
	/*
	Devuelve el primer elemento de la pila y lo destruye.
	Assert: N>0
	O temporal: O(1)
	O espacial: O(1)
	*/
	float pop();

	/*
	Al igual que pop, pero sin destruir dicho elemento.
	Assert: N>0
	O temporal: O(1)
	O espacial: O(1)
	*/
	float verCima();


	bool isVacia();
	~Pila();
};