#include "celda.h"
#include <cstdlib>
using namespace std;
#include <iostream>
#include <iomanip>
class AreaEmbaldosada{
private:
	int size;
	Celda** area;
	Celda busy;

	// Embaldosa una zona en cuestión. Con un angulo.
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
	void baldosa(int x, int y, int contador, int angulo);
public:
	AreaEmbaldosada(int size, Celda busy);

	void embaldosar(int x, int y, Celda ocupada);

	Celda*& operator[](int x);

	friend ostream& operator<< (ostream& o, AreaEmbaldosada a);

	int getSize();
};