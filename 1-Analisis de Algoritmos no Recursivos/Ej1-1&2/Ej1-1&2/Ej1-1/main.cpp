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
	Racional a(numerador, denominador);
	cout << a;
	return 0;
}

ostream& operator << (ostream &salida, Racional racional){
	if (racional.getNumerador() == 0 || racional.getDenominador() == 1){
		salida << racional.getNumerador();
	}
	else {
		salida << racional.getNumerador() << "/" << racional.getDenominador();
	}
	return salida;
}