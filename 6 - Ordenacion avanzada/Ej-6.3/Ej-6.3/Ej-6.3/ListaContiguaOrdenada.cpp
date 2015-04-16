#include "ListaContiguaOrdenada.h"


int ListaContiguaOrdenada::busquedaBinaria(int numeroABuscar, int inicio, int fin){
	int n = n / 2;
	int fin = this->getN() -1 ;
	if (fin == inicio && this->getValor(n) != numeroABuscar) {
		if (){

		}
	}
	if (this->getValor(n) == numeroABuscar){
		return true;
	}
	else if (this->getValor(n) > numeroABuscar){
		return busquedaBinaria();
	}
}