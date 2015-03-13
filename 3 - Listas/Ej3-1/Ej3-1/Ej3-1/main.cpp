
#include "ListaElementos.h"


int main(){
	ListaElementos caca(1);
	caca.imprimir();
	caca.insertar(1, Elemento(2));
	cout << endl;
	caca.imprimir();
	caca.insertar(1, Elemento(3));
	caca.insertar(2, Elemento(4));
	cout << endl;
	caca.imprimir();

	caca.insertar(2, Elemento(5));
	cout << endl;
	caca.imprimir();
	cout << endl;
	return 0;
}