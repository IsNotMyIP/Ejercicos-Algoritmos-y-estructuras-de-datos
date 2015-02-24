
#include <math.h>


unsigned int recursivoMCD(int mayor, int menor){
	if (mayor != 0){
		return recursivoMCD(menor, mayor%menor);
	}
	else{
		return mayor;
	}
}

int recursivoPotencia(int base, unsigned int exponente){
	if (exponente != 0){
		return  base * recursivoPotencia(base, exponente - 1);
	}
	else{
		return 1;
	}
}

unsigned int recursivoSumaNaturales(int cuantos){
	if (cuantos != 0){
		return cuantos  + recursivoSumaNaturales(cuantos - 1);
	}
	else{
		return 0;
	}

}

bool recursivoBuscar(unsigned int* inicio, unsigned int size, unsigned int cualo){
	if((size -1) == -1){
		return false;
	}
	else if(inicio[size - 1] == cualo){
		return true;
	}
	else{
		return recursivoBuscar(inicio, size - 1, cualo);
	}
}
int main(){

	return 0;
}