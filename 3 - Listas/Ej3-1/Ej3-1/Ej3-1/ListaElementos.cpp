#include "ListaElementos.h"


bool ListaElementos::llena(){
	return (capacity == size);
}

void ListaElementos::setElemento(int pos, Elemento nuevo){
	this->inicio[pos] = nuevo;
}

ListaElementos::ListaElementos(){
	this->inicio = nullptr;
	this->capacity = 0;
	this->size = 0;
}

ListaElementos::ListaElementos(float contenido){
	this->inicio = (Elemento*) malloc(INCREMENTO * sizeof(Elemento));
	this->inicio = new Elemento(contenido);
	this->size = 1;
	this->capacity = 2;
}

void ListaElementos::ifExpandir(){
	if (llena()){
		this->inicio = (Elemento*)realloc(this->inicio, sizeof(Elemento)* (INCREMENTO + this->capacity));
		this->capacity += INCREMENTO;
	}
}
void ListaElementos::insertar(int pos, Elemento nuevo){
	assert(pos > 0);
	assert(nuevo.getContenido() != NULL);
	
	ifExpandir();
	memmove(&this->inicio[pos+1], &this->inicio[pos], sizeof(Elemento) * (size-pos));
	size++;
	setElemento(pos, nuevo);
}


void ListaElementos::imprimir(){
	for (int n = 0; n < size; n++){
		cout << this->inicio[n].getContenido() << "  ";
	}
}