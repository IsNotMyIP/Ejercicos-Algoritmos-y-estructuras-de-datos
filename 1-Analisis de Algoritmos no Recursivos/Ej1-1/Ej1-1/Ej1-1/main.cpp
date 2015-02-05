#include <iostream>
#include "Racional.h"

using namespace std;

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
	cout << "Ha introducido: ";
	a.escribir();
	cout << endl;

	//Segunda entrada
	do{
		cout << "Introduzca segundo num y denom separado por espacio.\n El denominador no ha de ser cero: ";
		cin >> numerador;
		cin >> denominador;
	} while (denominador == 0);
	Racional b(numerador, denominador);
	cout << "Su segunda entrada ha sido: ";
	b.escribir();
	cout << endl;

	//Sumamos y multiplicamos e imprimimos.
	Racional resultado = a.sumar(b);
	cout << "Resultado suma primer y el segundo racional: ";
	resultado.escribir();
	cout << endl;

	resultado = a.multiplicar(b);
	cout << "Resultado multiplicaciom primer y segundo racional: ";
	resultado.escribir();

	return 0;
}