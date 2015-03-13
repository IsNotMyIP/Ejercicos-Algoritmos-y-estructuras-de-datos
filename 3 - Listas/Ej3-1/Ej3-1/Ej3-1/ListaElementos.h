#include "Elemento.h"
#include <stdlib.h> //Memory funcs
#include <assert.h> //assert()
#include <cstring>
#include <iostream>

using namespace std;
#define INCREMENTO 2

class ListaElementos{
private:
	Elemento * inicio;
	int size; 
	int capacity;
	
	void setElemento(int pos, Elemento nuevo);
	bool llena();
public:
	ListaElementos();
	ListaElementos(float contenido);
	Elemento getElemento(int pos);

	void insertar(int pos, Elemento nuevo);
	void eliminar(int pos);
	
	void ifExpandir();
	void ifMenguar();

	void imprimir();
};