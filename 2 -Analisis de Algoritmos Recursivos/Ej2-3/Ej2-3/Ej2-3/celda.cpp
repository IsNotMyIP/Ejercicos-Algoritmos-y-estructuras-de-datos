#include "celda.h"
Celda::Celda(){
	//EMPTY
}

Celda::Celda(int posX, int posY){
	this->x = posX;
	this->y = posY;
	this->contenido = -1;
}


Celda::Celda(int posX, int posY, int contenido){
	this->x = posX;
	this->y = posY;
	this->contenido = contenido;
}