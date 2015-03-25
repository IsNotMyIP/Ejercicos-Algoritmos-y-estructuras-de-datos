#include "Pila.h"
#include "cstring"
#include "string"
class Calculadora{
private:
	ListaEnlazada inFijo;
	ListaEnlazada postFijo;
	Pila auxOperandos;

	void convertirTextoAListaInfija(string cadena);
	void convertirInfijoAListaPostFija();
	int evaluarPostFijo();

public:
	
	int evaluar(string aCalcular);
	
};