#include "celda.h"
#include <cstdlib>
using namespace std;

#include <iostream>
#include <iomanip>


class AreaEmbaldosada{
private:

	int size;

	int contBaldosa;

	Celda** area;

	Celda busy;

	// Embaldosa una zona en cuestión. Con un angulo definido.
	/*Parametros
		-x, coordenada x del punto medio de la baldosa.
		-y, int, coordenada y del punto medio de la baldosa.
		-contador, int, mero contador para rellenar la celda.
		-angulo, int. la baldosa en forma de L puede colocarse de diversas formas, este numero
			ira del 1 al 4, ambos inclusive y se colocara de la siguiente manera
							1|2
							-|-
							3|4
		apuntando hacia el centro.
	*/
	void baldosa(int x, int y, int angulo);

	int calcularOrientacion(Celda supIzq, Celda busy);

	Celda crearCuadrante(Celda supIzq, int lado, int numCuadrante);

	Celda calcularBusy(Celda supIzq, int lado, int numCuad, Celda busy);

	bool existeCelda(Celda supIzq, int lado, Celda exist);
public:
	
	AreaEmbaldosada(int size, Celda busy);

	void embaldosar(Celda supIzq, int lado, Celda ocupada);

	Celda*& operator[](int x);

	friend ostream& operator<< (ostream& o, AreaEmbaldosada a);

	int getSize();
	Celda calcularCentralSquare(Celda supIzq, int lado);
};