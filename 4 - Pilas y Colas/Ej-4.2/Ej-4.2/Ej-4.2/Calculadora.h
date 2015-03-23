#include "Pila.h"
#include "cstring"
class Calculadora{
private:
	Pila inFijo;
	Pila postFijo;

	void convertirTextoAListaInfija();
	void convertirTextoAListaPostFija();
	void evaluarPostFijo();

public:
	int evaluar(string aCalcular);
	
};