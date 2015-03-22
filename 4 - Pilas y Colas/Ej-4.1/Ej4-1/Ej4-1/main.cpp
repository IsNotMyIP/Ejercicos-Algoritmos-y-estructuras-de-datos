#pragma once
#include "Pila.h"
using namespace std;

int main(){
	int entrada;
	Pila pila;
	cout << "MENU:\n1.Push\n2.Pop\n3.Cima\n4.Salir\n";
	do{
		cout << "\nIntroduce una funcion del menu: ";
		cin >> entrada;
		switch (entrada) {
		case 1:
			float introducido;
			cout << "\nIntroduce un float: ";
			cin >> introducido;
			pila.push(introducido);
			break;
		case 2:
			if (pila.isVacia()) cout << "\nLa pila esta vacia y no se puede hacer pop";
			else{
				cout << "\nSe ha popeado el elemento: " << pila.pop();
			}
			cout << "\nLa pila completa tiene:" << pila.getN() << " elementos y es" << pila;
			break;
		case 3:
			if (pila.isVacia()) cout << "\nLa pila esta vacia y no se puede hacer verCima";
			else{
				cout << "\nEl elemento en la cima es: " << pila.verCima();
			}
			break;
		default:
			cout << "\nHa de introducir una entrada valida, entre el 1 y el 4";
			break;
		}

	} while (entrada != 4);
	return 0;
}