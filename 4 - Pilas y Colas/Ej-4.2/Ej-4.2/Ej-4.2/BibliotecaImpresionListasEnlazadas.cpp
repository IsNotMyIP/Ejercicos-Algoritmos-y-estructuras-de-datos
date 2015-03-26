#include "BibliotecaImpresionListasEnlazadas.h"


ostream& operator << (ostream& salida, const Elemento &elemento) {
	salida << elemento.get();
	return(salida);
}

ostream& operator << (ostream& salida, ListaEnlazada &lista) {
	// Imprimimos tamaño y capacidad
	salida << "n=" << lista.getN() << "|ListaEnlazada=";
	
	// Si la lista está vacía, imprimimos algo especial
	if (lista.getN()==0) salida << "vacia";

	// Si no está vacía, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
	// Si es demasiado grande, imprimimos un mensaje especial
	else {
		if (lista.getN() > 20) salida << "demasiadosElementosParaMostrar";
		else for (int i=0; i<lista.getN(); i++) salida << lista[i] << ",";
	}

	return(salida);
}
