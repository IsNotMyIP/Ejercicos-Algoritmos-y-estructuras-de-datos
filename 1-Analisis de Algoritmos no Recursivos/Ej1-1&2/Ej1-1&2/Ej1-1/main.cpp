#include <iostream>
#include "Racional.h"

using namespace std;

//Sobrecargamos el operador para poder imprimir por pantalla mediante cout
// de la forma "numerador/denominador"
/* Parametros:
	- salida: flujo de salida para ostream.
	- racional:clase que queremos imprimir por pantalla
	Salida:
	- salida, ostream para usar por cout.
*/ 
// Es de tipo ostream& dado que devolvera una referencia a un ostream, por
// restricciones propias de c++ dado que ostream es una clase muy grande y no permite pasarla como copia.
ostream& operator << (ostream &salida, Racional racional);

int main(){

	//Variables para guardar parametros
	int numerador;
	int denominador;
	
	//Primera entrada
	do{
		cout << "Introduzca primer num y denom separado por espacio.\n El denominador no ha de ser cero: ";
		cin >> numerador;
		cin >> denominador;
	} while (denominador == 0);

	//Declaramos y escribimos el racional.
	Racional a(numerador, denominador);
	cout << "Racional a: " << a << endl;

	//Lo simplificamos.
	Racional simplificado = a;
	simplificado.simplificar();
	cout << "Simplificado de a: " << simplificado;

	
	return 0;
}

ostream& operator << (ostream &salida, Racional racional)
{
	if (racional.getNumerador() == 0 || racional.getDenominador() == 1){
		salida << racional.getNumerador();
	}
	else {
		salida << racional.getNumerador() << "/" << racional.getDenominador();
	}
	return salida;
}