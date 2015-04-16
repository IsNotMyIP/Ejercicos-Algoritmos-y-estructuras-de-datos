#include "BibliotecaImpresionListasContiguas.h"
#include "iostream"

// Cambiar la implementaci�n de esta funci�n seg�n la naturaleza del Elemento
ostream& operator << (ostream& salida, const Elemento &elemento) {
	salida << elemento.get();
	return(salida);
}

ostream& operator << (ostream& salida, ListaContigua &ListaContigua) {
	// Imprimimos tama�o y capacidad
	salida << "n=" << ListaContigua.getN() << "|Max=" << ListaContigua.getCapacidad() << "|ListaContigua=";
	
	// Si la ListaContigua est� vac�a, imprimimos algo especial
	if (ListaContigua.getN()==0) salida << "vacia";

	// Si no est� vac�a, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
	// Si es demasiado grande, imprimimos un mensaje especial
	else {
		if (ListaContigua.getN() > 20) salida << "demasiadosElementosParaMostrar";
		else for (int i=0; i<ListaContigua.getN(); i++) salida << ListaContigua[i] << ",";
	}

	return(salida);
}
