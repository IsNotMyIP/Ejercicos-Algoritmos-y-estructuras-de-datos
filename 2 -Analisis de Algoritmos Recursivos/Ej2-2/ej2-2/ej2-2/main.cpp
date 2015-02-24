#include <math.h>
#include <iostream>

using namespace std;
//Multiplicacion recursiva a la rusa.
// Parametros:
// a, unsigned primer operando
// b, unsigned int, segundo operando
// Assert, A && B != 0.
unsigned int rusaRecursiva(unsigned int a, unsigned int b);

int main(){
	cout << "Multiplicacion de 1234 * 981: "<< rusaRecursiva(1234, 981)<< endl;
	cout << "Y bicepberza (981 * 1234): " << rusaRecursiva(981, 1234);
	return 0;
}

unsigned int rusaRecursiva(unsigned int a, unsigned int b){

	if (a == 1){
		return b;
	}
	else{
		if (a % 2 != 0){
			return b + rusaRecursiva(a / 2, b * 2);
		}
		else{
			return rusaRecursiva(a / 2, b * 2);
		}
	}
}