#pragma once
#include <iostream>


using namespace std;
class SolucionParcial{
private:

public:
	float x;
	float y;
	SolucionParcial(){
		//empty
	}
	SolucionParcial(float x,float y){
		this->x = x;
		this->y = y;
	}
	void imprimir(){
		cout << x << "," << y;
	}
};