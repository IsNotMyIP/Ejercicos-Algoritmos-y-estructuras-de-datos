#include "Pila.h"
#include "cstring"
#include "string"
class Calculadora{
public:
	//add constructor maybe attributes pointers.
	ListaEnlazada inFijo;
	ListaEnlazada postFijo;
	Pila auxOperandos;

	void convertirTextoAListaInfija(string cadena);
	void convertirInfijoAListaPostFija();
	int evaluarPostFijo();


	
	int evaluar(string aCalcular);
	
};