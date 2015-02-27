#pragma once
#include <iostream>
using namespace std;
#include "AreaEmbaldosada.h"


int main(){
	AreaEmbaldosada caca = AreaEmbaldosada(2, Celda(0, 0));
	cout << caca[0][1].getY() << caca[0][1].getX();
	return 0;
}