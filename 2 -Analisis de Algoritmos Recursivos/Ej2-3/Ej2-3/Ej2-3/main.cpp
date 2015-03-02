#pragma once
#include <iostream>
using namespace std;
#include "AreaEmbaldosada.h"


int main(){
	int x;
	AreaEmbaldosada caca = AreaEmbaldosada(8, Celda(3, 1));
	cout << caca;
	caca.embaldosar(Celda(0, 0), 8, Celda(3, 1));
	cout << endl;
	cout << caca;
	return 0;
}