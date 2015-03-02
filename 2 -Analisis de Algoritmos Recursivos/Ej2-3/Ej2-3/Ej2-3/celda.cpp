#include "celda.h"
Celda::Celda(){
	//EMPTY
}
void Celda::setContenido(int contenido){
	this->contenido = contenido;
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

int Celda::getX(){
	return this->x;
}

int Celda::getY(){
	return this->y;
}

int Celda::getContenido(){
	return this->contenido;
}