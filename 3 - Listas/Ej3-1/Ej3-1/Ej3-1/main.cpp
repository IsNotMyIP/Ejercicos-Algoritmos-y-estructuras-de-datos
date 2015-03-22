
#include "ListaElementos.h"


int main(){
	ListaElementos caca(1);
	Elemento jo(2);
	caca.insertar(1, jo);
	jo.setContenido(3);
	caca.insertar(1, jo);
	cout << caca.getElemento(0).getContenido() << endl << caca.getElemento(1).getContenido() << endl << caca.getElemento(2).getContenido();
	return 0;
}