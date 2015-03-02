#include "AreaEmbaldosada.h"


AreaEmbaldosada::AreaEmbaldosada(int size, Celda busy){
	this->size = size;
	this->area = (Celda**) malloc(size * sizeof(Celda*));
	this->contBaldosa = 0;
	for (int i = 0; i < size; i++){
		this->area[i] = (Celda*)malloc(size * sizeof(Celda));
	}
	
	// Rellenamos las celdas con la clase CELDA.
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			Celda aux;
			if (i == busy.getX() && j == busy.getY()){
				aux = Celda(i, j, 0);
			}
			else{
				aux = Celda(i, j);
			}
			this->area[i][j] = aux;
		}
	}
}

void AreaEmbaldosada::baldosa(int x, int y, int angulo){
	switch (angulo){
	case 1:
		this->area[x][y].setContenido(contBaldosa);
		this->area[x][y + 1].setContenido(contBaldosa);
		this->area[x + 1][y].setContenido(contBaldosa);
		this->contBaldosa += this->contBaldosa;
		break;
	case 2:
		this->area[x][y].setContenido(contBaldosa);
		this->area[x - 1][y].setContenido(contBaldosa);
		this->area[x][y + 1].setContenido(contBaldosa);
		this->contBaldosa += this->contBaldosa;
		break;
	case 3:
		this->area[x][y].setContenido(contBaldosa);
		this->area[x][y-1].setContenido(contBaldosa);
		this->area[x + 1][y].setContenido(contBaldosa);
		this->contBaldosa += this->contBaldosa;
		break;
	case 4:
		this->area[x][y].setContenido(contBaldosa);
		this->area[x - 1][y].setContenido(contBaldosa);
		this->area[x][y - 1].setContenido(contBaldosa);
		this->contBaldosa += this->contBaldosa;
		break;
	default:
		break;
	}
}

Celda AreaEmbaldosada::calcularCentralSquare(Celda supIzq, int lado){
	Celda returned(supIzq.getX + lado / 2 - 1, supIzq.getY + lado / 2 - 1);
	return returned;
}

int AreaEmbaldosada::calcularOrientacion(Celda supIzq, Celda busy){
	if (busy.getX() <= supIzq.getX() && busy.getY() <= supIzq.getY()){
		return 1;
	}
	if (busy.getX() <= supIzq.getX() && busy.getY() >= supIzq.getY() + 1){
		return 2;
	}
	if (busy.getX() >= supIzq.getX() + 1 && busy.getY() <= supIzq.getY()){
		return 3;
	}
	if (busy.getX() >= supIzq.getX() + 1 && busy.getY() >= supIzq.getY() + 1){
		return 4;
	}
}

Celda crearCuadrante(Celda supIzq, int lado, int numCuadrante){
	switch (numCuadrante){
	case 1:
		return supIzq;
		break;
	case 2:
		return Celda(supIzq.getX(), supIzq.getY + lado / 2);
		break;
	case 3:
		return Celda(supIzq.getX() + lado / 2, supIzq.getY());
		break;
	case 4:
		return Celda(supIzq.getX() + lado / 2, supIzq.getY() + lado / 2);
		break;
	}
}

bool existeCelda(Celda supIzq, int lado, Celda exist){
	if (exist.getX() >= supIzq.getX() && exist.getX <= supIzq.getX() + lado - 1 &&
		exist.getY() >= supIzq.getX() && exist.getY() <= supIzq.getY() + lado - 1)
	{
		return true;
	}
	else{
		return false;
	}
}
Celda calcularBusy(Celda supIzq, int lado, int numCuad, Celda busy){
	Celda supIzqCuad = crearCuadrante(supIzq, lado, numCuad);

	if (existeCelda(supIzqCuad, lado / 2, busy)){
		return busy;
	}
}

void AreaEmbaldosada::embaldosar(Celda supIzq, int lado, Celda busy){
	Celda supIzqCentral = calcularCentralSqare(supIzq, lado);
	int orientacion = calcularOrientacion(supIzqCentral, busy);

	if (lado == 2){
		baldosa(supIzq.getX(), supIzq.getY(), orientacion);
	}
	else{
		Celda cuadrantes[4];
		for (int i = 1; i < 5; i++){
			cuadrantes[i - 1] = crearCuadrante(supIzq, lado, i);
		}
		Celda busies[4];
		for (int i = 1; i < 5; i++){
			busies[i - 1] = calcularBusy(supIzq, lado, i, busy);

		}
		baldosa(supIzq.getX(), supIzq.getY(), orientacion);
		for (int i = 1; i < 5; i++){
			embaldosar(cuadrantes[i - 1], lado / 2, busies[i - 1]);
		}
	}

	

}
int AreaEmbaldosada::getSize(){
	return this->size;
}

 Celda*& AreaEmbaldosada::operator[](int x){
	return area[x];
}
 
ostream& operator<< (ostream& o, AreaEmbaldosada a){
	for (int i = 0; i < a.getSize(); i++){
		for (int j = 0; j < a.getSize(); j++){
			cout << setw(4) << a[j][i].getContenido();
		}
		cout << endl;
	}
	 return o;
 }
