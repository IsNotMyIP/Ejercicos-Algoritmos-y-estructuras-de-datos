
#include "SolucionParcial.h"
class Polinomio {
private:
	int grado; //Ha de ser <=0

	float* coeficientes; //Tamano grado+1

	float aleatorioNormalestandar();


public:
	//Constructor por defecto, sin implementar.
	Polinomio();

	Polinomio(int grado, float* coeficiente);
	float evaluar(float x);
	float obtenerMaximo(SolucionParcial padre);
	float obtenerMaximo();
	~Polinomio();

};