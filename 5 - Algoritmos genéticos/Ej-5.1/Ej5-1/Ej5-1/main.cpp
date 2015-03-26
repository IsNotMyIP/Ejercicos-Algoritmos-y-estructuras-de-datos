#include <iostream>
#include "Polinomio.h"
using namespace std;

int main(){
	float cof[2];
	cof[0] = 0;
	cof[1] = 1;
	cof[2] = 1;
	Polinomio frias(2, cof);
	cout << frias.evaluar(2);
	return 0;
}